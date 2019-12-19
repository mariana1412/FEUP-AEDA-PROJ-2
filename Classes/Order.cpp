#include"Order.h"

int Delivery::id_global = 1;

Order::Order(Restaurant restaurant, Time time , vector<Product>products, int nif){
    this->time = time;
    this->restaurant = restaurant;
    this->products = products;
    this->nif = nif;
    this->price = 0;
    for (vector<Product>::const_iterator it = products.begin(); it != products.end(); it++){
        this->price += it->getPrice();
    }
}

Restaurant Order::getRestaurant() const{
    return restaurant;
}

Time Order::getTime() const{
    return time;
}

vector<Product> Order::getProducts()const{
    return products;
}

int Order::getNif()const{
    return nif;
}
void Order::setRestaurant(Restaurant restaurant){
    this->restaurant = restaurant;
}

void Order::setTime(Time time){
    this->time = time;
}

void Order::setProducts(vector<Product> products){
    this->products = products;
}
void Order::setNif(int nif) {
    this-> nif = nif;
}


Delivery::Delivery(Restaurant restaurant, Time time , vector<Product> products, int nif, int id, bool success, string reason_insuccess, Time deliver_time, float tax): Order(restaurant, time , products, nif){
    this->id = id;
    this->success = success;
    this->reason_insuccess = reason_insuccess;
    this->deliver_time = deliver_time;
    this->tax = tax;
    this->final_price = this->price + this->tax;
    id_global++;
}

int Delivery::getId() const {
    return id;
}

bool Delivery::getSuccess() const{
    return success;
}

string Delivery::getReason_insuccess() const {
    return reason_insuccess;
}
Time Delivery::getDeliver_time() const{
    return deliver_time;
}

float Delivery::getPrice() const{
    return price;
}

void Delivery::setSuccess(bool success){
    this->success = success;
}

void Delivery::setReason_insuccess(string reason_insuccess){
    this->reason_insuccess = reason_insuccess;
}

void Delivery::setDeliver_time(Time deliver_time){
    this->deliver_time = deliver_time;
}

void Delivery::setPrice(float price){
    this->price = price;
}
float Delivery::getFinalPrice() const {
    return final_price;
}

float Delivery::getTax() const {
    return tax;
}

ostream & operator<<(ostream &os, const Delivery &d){
    os << "--> Deliver " << d.getId() << endl;
    os << "Restaurant: " << d.getRestaurant().getName() << endl
    << "Current time: " << d.getTime() << endl;

    for(int i=0; i<d.getProducts().size(); i++){
        os << "Product " << i+1 << ": " << d.getProducts()[i];
    }

    os << "Price: " << d.getPrice() << " euros" << endl;

    if(d.getSuccess()) os << "Succeeded" << endl;
    else os << "Not Succeeded. Reason: " << d.getReason_insuccess() << endl;

    os << "Deliver time: " << d.getDeliver_time() << endl;
    os << "Tax: " << d.getTax() << " euros" << endl;
    os << "Final price: " << d.getFinalPrice() << " euros" << endl;

    return os;
}

Delivery::Delivery(Restaurant restaurant, Time time, vector<Product> products, int nif, float tax): Order(restaurant, time , products, nif){
    this->tax = tax;
    this->id = id_global;
    this->final_price = this->price + this->tax;
    id_global++;
}
