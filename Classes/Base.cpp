#include "Base.h"

Base::Base(Location location, string manager,int manager_nif, vector<Client>blacklist){
        this->location = location;
        this->manager=manager;
        this->manager_nif =manager_nif;
        this->blacklist=blacklist;
}

Location Base::getLocation() const{
    return location;
}

string Base::getManager() const{
    return manager;
}
int Base::getManagerNif() const {
    return manager_nif;
}

vector<Client> Base::getClients() const{
    return clients;
}

vector<Client> Base::getBlackList() const{
    return blacklist;
}

vector<Restaurant> Base::getRestaurants()const{
    return restaurants;
}

void Base::setLocation(Location location){
    this->location = location;
}

void Base::setManager(string manager){
    this->manager = manager;
}
void Base::setManagerNif(int nif) {
    this->manager_nif=nif;
}

void Base::setClients(vector<Client>clients){
    this->clients = clients;
}

void Base::setBlacklist(vector<Client> blacklist){
    this->blacklist = blacklist;
}

void Base::setRestaurants(vector<Restaurant> restaurants){
    this->restaurants = restaurants;
}

void Base::addClient(Client client) {
    clients.push_back(client);
}

void Base::addRestaurant(Restaurant restaurant) {
    restaurants.push_back(restaurant);
}


vector<Delivery> Base::getDeliveries() const {
    return deliveries;
}

void Base::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}

vector<Employee *> Base::getEmployees() const {
    return employees;
}

void Base::addEmployee(Employee *employee) {
    employees.push_back(employee);
}

bool Base::removeRestaurant(string name){
    vector<Restaurant>::iterator it = restaurants.begin();

    while(it != restaurants.end()){
        if (name == (*it).getName()){
            break;
        }
        advance(it, 1);
    }

    if(it == restaurants.end()){
        throw RestaurantNotFound(name);
    }
    Restaurant rest = *it;

    system("cls");
    cout << endl << "---------------- REMOVE RESTAURANT ----------------" << endl << endl;
    cout << endl << rest << endl;
    cout << endl << endl << "---------------------------------------------------" << endl;

    if(confirm_modifications("remove", "restaurant")){
        restaurants.erase(it);
        return true;
    }
    return false;
}

Restaurant Base::searchRestaurant(string name){
    for (vector<Restaurant>::iterator it = restaurants.begin(); it != restaurants.end(); it++){
        if (name == it->getName())
            return (*it);
    }
    throw RestaurantNotFound(name);
}

int Base::getIndexrestaurant(Restaurant restaurant){

    for(int i = 0; i<restaurants.size(); i++){
        if(restaurants[i] == restaurant){
            return i;
        }
    }

    throw RestaurantNotFound(restaurant.getName());
}

void Base::changeRestaurant(Restaurant restaurant, int index){
    restaurants.erase(restaurants.begin()+index);
    restaurants.insert(restaurants.begin()+index, restaurant);

}
void Base::removeClient(int index){
    clients.erase(clients.begin()+index);
    return;
}
void Base::removeEmployee(int index) {
    employees.erase(employees.begin()+index);
}

int Base::getIndexEmployee(string nif) const {

    for(int i = 0; i < employees.size(); i++){
        if (employees[i]->getNif() == stoi(nif)){
            return i;
        }
    }
    return -1;
}

void Base::addDeliveryToDeliverer(Delivery delivery) {
    Deliverer* low_deliverer = new Deliverer;
    low_deliverer->setBackground({});
    bool low = false;
    for (vector<Employee*>::const_iterator it =  employees.begin(); it != employees.end(); it++){
        Deliverer* nd = dynamic_cast<Deliverer*>(*it);
        if (nd != nullptr){
            if (!low || low_deliverer->getBackground().size() > nd->getBackground().size()) {
                low_deliverer = nd;
                low = true;
            }
        }
    }
    low_deliverer->addDelivery(delivery);
}

void Base::updateBases() {
    for (vector<Client>::iterator it = clients.begin(); it != clients.end(); it++){
        for (vector<Client>::const_iterator it1 = blacklist.begin(); it1 != blacklist.end(); it1++){
            if (it->getNif() == it1->getNif())
                (*it).setBlack(true);
        }
    }
    float profit = 0;
    for (vector<Restaurant>::iterator it = restaurants.begin(); it != restaurants.end(); it++){
        for(vector<Delivery>::const_iterator it1 = deliveries.begin(); it1 != deliveries.end(); it1++){
            if (it1->getRestaurant().getName() == (*it).getName())
                profit += it1->getPrice();
        }
        it->setRevenue(profit);
        profit = 0;
    }
    profit = 0;
    for (vector<Employee*>::iterator it =  employees.begin(); it != employees.end(); it++) {
        Deliverer *nd = dynamic_cast<Deliverer *>(*it);
        if (nd != nullptr){
            for (vector<Delivery>::const_iterator it1 = nd->getBackground().begin(); it1 != nd->getBackground().end(); it1++){
                profit += it1->getTax();
            }
            (*it)->setIncome(profit);
        }

        profit = 0;
    }
}

void Base::addClientToBlacklist(Client client) {
    blacklist.push_back(client);

}
