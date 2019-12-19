#include "Restaurant.h"

Restaurant::Restaurant(string name, string address, string county, vector<string> types_of_food, vector<Product> products, float revenue){
    this->name = name;
    this->county = county;
    this-> address= address;
    this-> types_of_food=types_of_food;
    this-> products=products;
    this-> revenue=revenue;
}

string Restaurant::getName() const {
    return name;
}

string Restaurant::getAddress() const{
    return address;
}

string Restaurant::getCounty() const{
    return county;
}

vector<string> Restaurant::getTypes_of_food() const{
    return types_of_food;
}

vector<Product> Restaurant:: getProducts() const{
    return products;
}

float Restaurant::getRevenue() const{
    return revenue;
}


void Restaurant::setName(string name) {
    this->name = name;
}

void Restaurant::setName(string name, const vector<Restaurant> &v){

    vector<Restaurant>::const_iterator it = v.begin();

    while(it != v.end()){
        if (name == (*it).getName()){
            throw RestaurantAlreadyExists(name);
        }
        advance(it, 1);
    }
    this->name = name;
}

void Restaurant::setCounty(string county) {
    this->county = county;
}

void Restaurant::setCounty(string county, string base){

    vector<string>::const_iterator it1, it2;

    if (base == "Porto"){
        it1 = nearby_Porto.begin();
        it2 = nearby_Porto.end();
    }
    else if (base == "Lisboa"){
        it1 = nearby_Lisboa.begin();
        it2 = nearby_Lisboa.end();
    }
    else if (base == "Faro"){
        it1 = nearby_Faro.begin();
        it2 = nearby_Faro.end();
    }

    while(it1 != it2){
        if (county == (*it1)){
            this->county = county;
            break;
        }
        advance(it1, 1);
    }

    if(it1 == it2)
        throw RestaurantOutOfArea(county);
}

void Restaurant::setAddress(string address){
    this->address = address;
}

void Restaurant::setTypes_of_food(vector<string> types_of_food){
    this->types_of_food = types_of_food;
}

void Restaurant::setProducts(vector<Product> products){
    this->products = products;
}

void Restaurant::setRevenue(float revenue){
    this->revenue = revenue;
}

void Restaurant::addProduct(Product product){

    vector<Product>::const_iterator it = products.begin();

    while(it != products.end()){
        if((*it) == product){
            throw ProductAlreadyExists(product.getName());
        }
        advance(it, 1);
    }

    this->products.push_back(product);
}
void Restaurant::addType_of_food(string type_of_food){

    vector<string>::const_iterator it = types_of_food.begin();

    while(it != types_of_food.end()){
        if((*it) == type_of_food){
            break;
        }
        advance(it, 1);
    }
    if(it == types_of_food.end()) this->types_of_food.push_back(type_of_food);
}

bool Restaurant::operator==(const Restaurant& rest) const{

    if(name == rest.getName() && address == rest.getAddress() && county == rest.getCounty() && types_of_food == rest.getTypes_of_food() && products == rest.getProducts() && revenue == rest.getRevenue())
        return true;
    return false;
}

Product Restaurant::searchProduct(string name){
    for (vector<Product>::iterator it = products.begin(); it != products.end(); it++){
        if (name == it->getName())
            return (*it);
    }
    throw ProductNotFound(name);
}

int Restaurant::getIndexProduct(Product product){

    for(int i = 0; i<products.size(); i++){
        if(products[i] == product){
            return i;
        }
    }
    throw ProductNotFound(product.getName());
}

void Restaurant::removeProduct(int index){
    products.erase(products.begin() + index);
    updateTypes_of_food();
}

void Restaurant::updateTypes_of_food(){

    vector<Product>::const_iterator it = products.begin();
    types_of_food.clear();

    while(it != products.end()){
        addType_of_food((*it).getType_of_food());
        advance(it, 1);
    }
}

void Restaurant::changeProduct(Product product, int index){
    products.erase(products.begin()+index);
    products.insert(products.begin()+index, product);
}

ostream& operator<<(ostream& os, const vector<string>& types_of_food){
    int size = types_of_food.size();

    for(int i = 0; i< size; i++){
        if(i != (size-1)) os << types_of_food[i] << ", ";
        else os <<types_of_food[i] << endl;
    }

    return os;
}

ostream& operator<<(ostream& os, const vector<Product>& products){
    int size = products.size();

    for(int i = 0; i< size; i++){
        if(i != (size-1)) os << products[i] << " / ";
        else os << products[i] << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const Restaurant& rest){
    os << "Name: " << rest.getName() << endl
    << "Address: " << rest.getAddress() << ", " << rest.getCounty() << endl
    << "Types of food: " << rest.getTypes_of_food();

    int size = rest.getProducts().size();

    for(int i = 0; i< size; i++){
        os << "Product " << i+1 << ": " << rest.getProducts()[i];
    }

    os << "Revenue: " << rest.getRevenue() << " euros";

    return os;
}
