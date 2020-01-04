#include "Person.h"


Person::Person(string base, string name, int nif, Time birthdate){
    this->base = base;
    this->name = name;
    this->nif = nif;
    this->birthdate = birthdate;
}

Time Person::getBirthdate() const{
    return birthdate;
}

string Person::getName() const{
    return name;
}

int Person::getNif() const{
    return nif;
}

string Person::getBase() const{
    return base;
}

void Person::setBirthdate(Time birthdate){
    this->birthdate = birthdate;
}

void Person::setName(string name){
    this->name = name;
}

void Person::setNif(int nif){
    this->nif = nif;
}

void Person::setBase(string base){
    this->base = base;
}

Client::Client(string base, string name, int nif, string address, bool black, string county, Time birthdate):Person(base, name, nif, birthdate){
    this->address = address;
    this->black = black;
    this->county = county;
}

bool Client::getBlack() const{
    return black;
}

string Client::getAddress() const{
    return address;
}

string Client::getCounty() const{
    return county;
}

void Client::setAddress(string address){
    this->address = address;
}

void Client::setBlack(bool black) {
    this->black = black;
}

void Client::setCounty(string county) {
    this->county = county;
}

ostream &operator<<(ostream &os, const Client cl){
    os<<"Base: "<<cl.getBase()<<endl
      << "Name: "<< cl.getName()<<endl
      <<"NIF: "<<cl.getNif()<<endl
      <<"Birthdate: " << cl.getBirthdate() << endl
      << "Address: "<<cl.getAddress()
      <<", "<< cl.getCounty()<<endl;
    return os;
}

Employee::Employee(string base, string name, int nif, Time birthdate, float income, bool former) : Person(base, name, nif, birthdate){
    this->income = income;
    this->former = former;
}

float Employee::getIncome() const{
    return income;
}

bool Employee::getFormer() const{
    return former;
}

void Employee::setIncome(float income){
    this->income = income;
}

void Employee::setFormer(bool f) {
    this->former = f;
}

Admin::Admin(string base, string name, int nif, Time birthdate, float income, string task, bool former): Employee(base, name, nif, birthdate, income, former){
    this->task = task;
}

string Admin::getTask() const{
    return task;
}

void Admin::setTask(string task){
    this->task = task;
}

Deliverer::Deliverer(string base, string name, int nif, Time birthdate, float income, Vehicle vehicle, vector<Delivery> background, bool former) : Employee(base, name, nif, birthdate, income, former){
    this->vehicle = vehicle;
    this->background = background;
    float salary = 0;
    for (vector<Delivery>::const_iterator it = background.begin(); it != background.end(); it++){
        salary += it->getTax();
    }
    this->setIncome(salary);
}

Vehicle Deliverer::getVehicle() const {
    return vehicle;
}

vector<Delivery> Deliverer::getBackground() const {
    return background;
}

void Deliverer::setVehicle(Vehicle vehicle){
    this->vehicle = vehicle;
}

void Deliverer::setBackground(vector<Delivery> background){
    this->background = background;
}

ostream &operator<<(ostream &os, const Admin *a) {
    os << "Base: "<< a->getBase() << endl
       << "Name: " << a->getName() << endl
       << "NIF: " << a->getNif() << endl
       << "Working: ";

    if(!(a->getFormer())) os << "yes" << endl;
    else os << "no" << endl;

    os << "Birthdate: " << a->getBirthdate() << endl
       << "Income: " << a->getIncome() << endl
       << "Task: " << a->getTask() << endl;
    return os;
}
ostream &operator<<(ostream &os, const Deliverer *d){
    os << "Base: " << d->getBase() << endl
      << "Name: " << d->getName() << endl
      <<"NIF: " << d->getNif() << endl
            << "Working: ";

    if(!(d->getFormer())) os << "yes" << endl;
    else os << "no" << endl;

    os  <<"Birthdate: " << d->getBirthdate() << endl
      <<"Income: " << d->getIncome() << endl
      <<"Vehicle: " << d->getVehicle() << endl;
    return os;
}

void Deliverer::addDelivery(Delivery delivery) {
    background.push_back(delivery);
}

Tec::Tec(string base,string name,Time birthdate,int nif, int m, int n):Person(base, name,nif, birthdate) {
    this->time_to_available = m;
    this -> number_of_maintenances =n;
}

void Tec::setTimeToAvailable(int m) {
    this->time_to_available = m;
}
void Tec::setNumberOfMaintenances(int n) {
    this->number_of_maintenances = n;
}

int Tec::getTimeToAvailable() const{
    return time_to_available;
}

int Tec::getNumberOfMaintenances() const {
    return number_of_maintenances;
}

void Tec::addMaintenance(){
    number_of_maintenances++;
}

bool Tec::operator<(const Tec & tec1) const{
    return((this->time_to_available > tec1.time_to_available));
}

void Deliverer::addDeliveryToVehicle(){
    vehicle.addDelivery();
}


bool Tec::operator==(const Tec &tec1) const {
    return this->getNif() == tec1.getNif();
}
ostream &operator<<(ostream &os, const Tec &tecnico){
    int hours = tecnico.getTimeToAvailable() / 60;
    int min = tecnico.getTimeToAvailable() % 60;
    os  <<"Base: "<< tecnico.getBase() <<endl
        << "Name: " << tecnico.getName() << endl
        <<"NIF: " << tecnico.getNif() << endl
        <<"Birthdate: " << tecnico.getBirthdate() << endl
       << "Number of hours to be available: "<< hours <<endl
       << "Number of minutes to be available: "<< min <<endl
       << "Number of maintenances: "<< tecnico.getNumberOfMaintenances();
    return os;

}



