#include "Base.h"
Base::Base(): vehicles(Vehicle("","",Time(0,0,0,0,0),"",0,0,0,0)){
}

Base::Base(Location location, string manager, int manager_nif, vector<Client>blacklist): vehicles(Vehicle("","",Time(0,0,0,0,0),"",0,0,0,0)){
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
vector<Delivery> Base::getDeliveries() const {
    return deliveries;
}
vector<Restaurant> Base::getRestaurants()const{
    return restaurants;
}
BST<Vehicle> Base::getVehicles() const {
    return vehicles;
}
vector<Employee *> Base::getEmployeesHash() const {
    vector<Employee *> ptrs;
    for(HashTableEmployees::const_iterator it = employeesHash.begin(); it != employeesHash.end(); it++) {
        ptrs.push_back(*it);
    }
    return ptrs;
}
vector<Tec> Base::getTecs () const{
    TecPriorityQueue aux=tecnicos;
    vector <Tec>final;
    while(!(aux.empty())){
        final.push_back(aux.top());
        aux.pop();
    }
    return final;
}
int Base::getIndexrestaurant(Restaurant restaurant){

    for(int i = 0; i<restaurants.size(); i++){
        if(restaurants[i] == restaurant){
            return i;
        }
    }

    throw RestaurantNotFound(restaurant.getName());
}
int Base::getIndexEmployee(string nif) const {

    for(int i = 0; i < getEmployeesHash().size(); i++){
        if (getEmployeesHash()[i]->getNif() == stoi(nif)){
            return i;
        }
    }
    return -1;
}

void Base::setTecs(vector<Tec> tecs) {
    clearTecs();
    for(unsigned int i =0; i< tecs.size() ; i++){
        addTec(tecs.at(i));
    }
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
void Base::setVehicles(vector<Vehicle> v){
    vehicles.makeEmpty();
    vector<Vehicle>:: iterator it= v.begin();
    for (it; it!= v.end(); it++){
        vehicles.insert(*it);
    }
}

void Base::addClient(Client client) {
    clients.push_back(client);
}

void Base::addRestaurant(Restaurant restaurant) {
    restaurants.push_back(restaurant);
}

void Base::addDelivery(Delivery delivery) {
    deliveries.push_back(delivery);
}

void Base::addVehicle(Vehicle vehicle) {
    vehicles.insert(vehicle);
}

void Base::addEmployee(Employee *employee) {
    employeesHash.insert(employee);
}
void Base::addTec(Tec tecnico){
    tecnicos.push(tecnico);
}


void Base::addDeliveryToDeliverer(Delivery delivery, Time order_time) {
    Deliverer* low_deliverer = new Deliverer;
    low_deliverer->setBackground({});
    bool low = false;
    vector<Employee*> employees = getEmployeesHash();
    for (vector<Employee*>::const_iterator it =  employees.begin(); it != employees.end(); it++){
        Deliverer* nd = dynamic_cast<Deliverer*>(*it);
        if (nd != nullptr){
            if (nd->getFormer()){
                continue;
            }
            if ((!low || (low_deliverer->getBackground().size() > nd->getBackground().size())) &&(nd->getVehicle().getNMin()==0)) {
                low_deliverer = nd;
                low = true;
            }
        }
    }
    low_deliverer->addDelivery(delivery); //adiciona uma entrega ao entregador

    low_deliverer->addDeliveryToVehicle(); //adicionar uma entrega ao veiculo

    Vehicle v= low_deliverer->getVehicle();
    vehicles.remove(v);
    vehicles.insert(v);
    if (delivery.getDeliver_time().getDay() != 0) { //Verificar se a order foi bem sucedida para atualizar o tempo
        int aux = subtractTimes(delivery.getDeliver_time(), order_time);
        updateTecs(aux);
        updateVehicles(aux);
    }

    if(low_deliverer->getVehicle().getNDel() == 5){
        sendToMaintenance(low_deliverer->getVehicle());
    }

}
void Base::addClientToBlacklist(Client client) {
    blacklist.push_back(client);

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
void Base::removeClient(int index){
    clients.erase(clients.begin()+index);
    return;
}
void Base::removeEmployee(int index) {
    vector <Employee *> aux = getEmployeesHash();
    aux.at(index)->setFormer(true);
    setEmployeesHash(aux);
}


void Base::removeTec( Tec tecnico ){
    vector<Tec> tecs = getTecs();
    vector<Tec> aux;
    for(vector<Tec>::iterator it = tecs.begin(); it!= tecs.end(); it++){
        if(!((*it) == tecnico)){
            aux.push_back(*it);
        }
    }
    setTecs(aux);
}
Restaurant Base::searchRestaurant(string name){
    for (vector<Restaurant>::iterator it = restaurants.begin(); it != restaurants.end(); it++){
        if (name == it->getName())
            return (*it);
    }
    throw RestaurantNotFound(name);
}



void Base::changeRestaurant(Restaurant restaurant, int index){
    restaurants.erase(restaurants.begin()+index);
    restaurants.insert(restaurants.begin()+index, restaurant);

}

void Base::hireEmployee(int index) {
    vector <Employee *> aux = getEmployeesHash();
    aux.at(index)->setFormer(false);
    setEmployeesHash(aux);
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

void Base::printTecs(vector<Tec> aux){
    vector<Tec>::iterator it=aux.begin();
    for(it; it!= aux.end();it++){
        cout <<*it<<endl<<endl;
    }
}
void Base::clearTecs() {
    while(!(tecnicos.empty())){
        tecnicos.pop();
    }
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
    vector<Employee*> employees =getEmployeesHash();
    for (vector<Employee*>::iterator it = employees.begin(); it != employees.end(); it++) {
        Deliverer *nd = dynamic_cast<Deliverer *>(*it);
        if (nd != nullptr){
            vector<Delivery> deliveries = nd->getBackground();
            for (vector<Delivery>::const_iterator it1 = deliveries.begin(); it1 != deliveries.end(); it1++){
                profit += it1->getTax();
            }
            (*it)->setIncome(profit);
        }

        profit = 0;
    }
}


void Base::sendToMaintenance(Vehicle ve){
    //escolha do tecnico e sua atualização
    Tec t = tecnicos.top();
    removeTec(t);
    int h = t.getTimeToAvailable();
    t.setTimeToAvailable(h +240); // +4 horas
    addTec(t);
    //atualizaçao do veiculo
    vehicles.remove(ve);
    ve.setNMin(240);
    vehicles.insert(ve);
}

void Base::updateVehicles(int m){
    BSTItrIn<Vehicle> it(vehicles);
    vector<Vehicle> aux;
    Vehicle v;
    while(!it.isAtEnd()){
        if (it.retrieve().getNDel() == 5) {
            v = it.retrieve();
            if (v.getNMin()-m <= 0){
                v.setNMin(0);
                v.setNDel(0);
            }
            else {
                v.setNMin(v.getNMin() - m);
            }
            aux.push_back(v);
        }
        it.advance();
    }

    for (Vehicle x: aux){
        vehicles.remove(x);
        vehicles.insert(x);
    }

}

void Base::updateTecs(int m) {
    TecPriorityQueue aux = tecnicos;
    vector<Tec> result;
    Tec tec;
    while (!aux.empty()){
        if (aux.top().getTimeToAvailable() > 0){
            tec = aux.top();
            if (tec.getTimeToAvailable() - m <= 0){
                tec.setTimeToAvailable(0);
                tec.addMaintenance();
            } else{
                tec.setTimeToAvailable(tec.getTimeToAvailable() - m);
            }
            result.push_back(tec);
            aux.pop();
            continue;
        }
        result.push_back(aux.top());
        aux.pop();
    }
    for (Tec x: result){
        aux.push(x);
    }
    tecnicos = aux;
}

void Base::hashUpdate() {
    BSTItrIn<Vehicle> it(vehicles);
    while(!it.isAtEnd()){
        for (HashTableEmployees::const_iterator it1 = employeesHash.begin(); it1 != employeesHash.end(); it1++){
            Employee* e = *it1;
            Deliverer* nd = dynamic_cast<Deliverer*>(e);
            if (nd != nullptr){
                if (nd->getVehicle().getLicPlate() == it.retrieve().getLicPlate())
                    nd->setVehicle(it.retrieve());
            }
        }
        it.advance();
    }
}

void Base::addDistance(int distance, Deliverer* del) {
    vector<Employee*> employees = getEmployeesHash();
    Vehicle vehicle;
    for (vector<Employee*>::const_iterator it =  employees.begin(); it != employees.end(); it++){
        Deliverer* nd = dynamic_cast<Deliverer*>(*it);
        if (nd != nullptr){
            if (nd->getNif() == del->getNif()){
                vehicle = nd->getVehicle();
                vehicle.setTotalKm(vehicle.getTotalKm() + distance);
                nd->setVehicle(vehicle);
            }
        }
    }
    vehicles.remove(vehicle);
    vehicles.insert(vehicle);
}






