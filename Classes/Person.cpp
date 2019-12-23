#include "Person.h"

int Tec::id_g= 0;
Person::Person(string base, string name, int nif){
    this->base = base;
    this->name = name;
    this->nif = nif;
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

void Person::setName(string name){
    this->name = name;
}

void Person::setNif(int nif){
    this->nif = nif;
}

void Person::setBase(string base){
    this->base = base;
}

Client::Client(string base, string name, int nif, string address, bool black, string county):Person(base, name, nif){
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
      << "Address: "<<cl.getAddress()
      <<", "<< cl.getCounty()<<endl;
    return os;
}

Employee::Employee(string base, string name, int nif, Time birthdate, float income, bool former) : Person(base, name, nif){
    this->birthdate = birthdate;
    this->income = income;
    this->former = former;
}

Time Employee::getBirthdate() const{
    return birthdate;
}

float Employee::getIncome() const{
    return income;
}

bool Employee::getFormer() const{
    return former;
}

void Employee::setBirthdate(Time birthdate){
    this->birthdate = birthdate;
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

Tec::Tec(string base, int h,int m, int n) {
    this->base = base;
    this-> hours_to_available =h;
    this->minutes_to_available = m;
    this -> number_of_maintenances =n;
    id_g++;
}
Tec::Tec(string base, int i,int h,int m, int n) {
    this->id =i;
    this->base = base;
    this-> hours_to_available =h;
    this->minutes_to_available = m;
    this -> number_of_maintenances =n;
    id_g ++;
}
void Tec::setBase(string base){
    this->base = base;
}
void Tec::setId(int i) {
    this-> id = i;
}
void Tec::setHoursToAvailable(int h) {
    this-> hours_to_available= h;
}
void Tec::setMinutesToAvailable(int m) {
    this->minutes_to_available = m;
}
void Tec::setNumberOfMaintenances(int n) {
    this->number_of_maintenances = n;
}
string Tec::getBase() const{
    return base;
}
int Tec::getId() const {
    return id;
}

int Tec::getHoursToAvailable() const {
    return hours_to_available;
}
int Tec::getMinutesToAvailable() const {
    return minutes_to_available;
}
int Tec::getNumberOfMaintenances() const {
    return number_of_maintenances;
}

bool Tec::operator<(const Tec & tec1) const{
    if(this->hours_to_available < tec1.getHoursToAvailable()){
        return true;
    }
    else{
        return(this->number_of_maintenances > tec1.getNumberOfMaintenances());
    }
}

bool Tec::operator==(const Tec &tec1) const {//verificasse tudo para nao haver casos errados
    if (id == tec1.getId()){
        if(hours_to_available == tec1.getHoursToAvailable()){
            if(number_of_maintenances == tec1.getNumberOfMaintenances()){
                return true;
            }
        }
    }
    return false;
}
ostream &operator<<(ostream &os, const Tec &tecnico){
    os <<"Base: "<<tecnico.getBase() <<endl
       <<"ID: "<<tecnico.getId() <<endl
       << "Number of hours to be available: "<<tecnico.getHoursToAvailable()<<endl
       << "Number of minutes to be available: "<<tecnico.getMinutesToAvailable()<<endl
       << "Number of maintenances: "<< tecnico.getNumberOfMaintenances()<<endl;
    return os;
}


