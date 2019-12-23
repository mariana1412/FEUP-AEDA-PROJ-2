#include "Base.h"

Base::Base(Location location, string manager, int manager_nif, vector<Client>blacklist){
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

vector<Employee *> Base::getEmployeesHash() const {
    vector<Employee *> ptrs;
    HashTableEmployees::const_iterator it1 = this->employeesHash.begin();
    HashTableEmployees::const_iterator it2 = this->employeesHash.end();
    for(; it1 != it2; it1++) {
        ptrs.push_back(*it1);
    }
    return ptrs;
}

void Base::setEmployeesHash(vector<Employee *>& aux) { //acho que não é necessária por agora mas just in case
    employeesHash.clear();
    for(unsigned int i = 0; i < aux.size(); i++) {
        addEmployee(aux.at(i));
    }
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


void Base::addEmployee(Employee *employee) {
    employeesHash.insert(employee);
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
    vector <Employee *> aux = getEmployeesHash();
    aux.at(index)->setFormer(true);
    setEmployeesHash(aux);
}

void Base::hireEmployee(int index) {
    vector <Employee *> aux = getEmployeesHash();
    aux.at(index)->setFormer(false);
    setEmployeesHash(aux);
}

int Base::getIndexEmployee(string nif) const {

    for(int i = 0; i < getEmployeesHash().size(); i++){
        if (getEmployeesHash()[i]->getNif() == stoi(nif)){
            return i;
        }
    }
    return -1;
}

void Base::addDeliveryToDeliverer(Delivery delivery) {
    Deliverer* low_deliverer = new Deliverer;
    low_deliverer->setBackground({});
    bool low = false;
    for (vector<Employee*>::const_iterator it =  getEmployeesHash().begin(); it != getEmployeesHash().end(); it++){
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
    for (vector<Employee*>::iterator it = getEmployeesHash().begin(); it != getEmployeesHash().end(); it++) {
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

vector<int> Base::printEmployees(bool former, bool newE, bool admin, bool deliverer){
    vector<int> index;
    int counter;
    if(former && newE){
        counter = 1;
        for (int i = 0; i < getEmployeesHash().size(); i++){
            if(admin && deliverer){
                Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                if(a != NULL){ //é um administrador
                    cout << counter << ". " << "Administrator\n" << a << endl;
                    index.push_back(i);
                    counter++;
                }
                else { //é um entregador
                    Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                    cout << counter << ". " << "Deliverer\n" << d << endl;
                    index.push_back(i);
                    counter++;
                }
            }
            else if (admin){
                Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                if(a != NULL){ //é um administrador
                    cout << counter << ". " << "Administrator\n" << a << endl;
                    index.push_back(i);
                    counter++;
                }
            }
            else if (deliverer){
                Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                if(d != NULL){ //é um administrador
                    cout << counter << ". " << "Deliverer\n" << d << endl;
                    index.push_back(i);
                    counter++;
                }
            }
        }
        if (counter == 1) {
            cout << "We do not have informations to show! " << endl;
        }
    }
    else if(former){
        counter = 1;
        for (int i = 0; i < getEmployeesHash().size(); i++){
            if(getEmployeesHash().at(i)->getFormer()){
                if(admin && deliverer){
                    Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                    if(a != NULL){ //é um administrador
                        cout << counter << ". " << "Administrator\n" << a << endl;
                        index.push_back(i);
                        counter++;
                    }
                    else { //é um entregador
                        Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                        cout << counter << ". " << "Deliverer\n" << d << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
                else if (admin){
                    Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                    if(a != NULL){ //é um administrador
                        cout << counter << ". " << "Administrator\n" << a << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
                else if (deliverer){
                    Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                    if(d != NULL){ //é um administrador
                        cout << counter << ". " << "Deliverer\n" << d << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
            }
        }
        if (counter == 1) {
            cout << "We do not have informations to show! " << endl;
        }
    }

    else if (newE){
        counter = 1;
        for (int i = 0; i < getEmployeesHash().size(); i++){
            if(!(getEmployeesHash().at(i)->getFormer())){
                if(admin && deliverer){
                    Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                    if(a != NULL){ //é um administrador
                        cout << counter << ". " << "Administrator\n" << a << endl;
                        index.push_back(i);
                        counter++;
                    }
                    else { //é um entregador
                        Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                        cout << counter << ". " << "Deliverer\n" << d << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
                else if (admin){
                    Admin *a= dynamic_cast<Admin *> (getEmployeesHash().at(i));
                    if(a != NULL){ //é um administrador
                        cout << counter << ". " << "Administrator\n" << a << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
                else if (deliverer){
                    Deliverer *d = dynamic_cast<Deliverer *> (getEmployeesHash().at(i));
                    if(d != NULL){ //é um administrador
                        cout << counter << ". " << "Deliverer\n" << d << endl;
                        index.push_back(i);
                        counter++;
                    }
                }
            }
        }
        if (counter == 1) {
            cout << "We do not have informations to show! " << endl;
        }
    }
    return index;
}

int Base::chooseEmployee(bool former, bool newE, bool admin, bool deliverer, string action){
    system("cls");
    vector<int> indices = printEmployees(former, newE, admin, deliverer);
    int index;

    cout << endl << "-----------------------------------------------" << endl;

    cout << "Do you want to " << action << " one of these employees? Choose the number of the employee (insert 0 to return to the main menu): ";
    cin >> index;
    while (cin.fail() || index < 0 || index > indices.size()) {
        if (cin.eof()) { //caso de ter sido introduzido o 'crtl-z'
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> index;
        }
        else { //qualquer outro caso que nao corresponda ao input pretendido
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid operation, please insert a valid one: ";
            cin >> index;
        }
    }

    if(index == 0){
        return -1;
    }

    system("cls");
    return indices.at(index-1);

}