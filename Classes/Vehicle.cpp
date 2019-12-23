#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(string brand, string type, Time date, int n_del,int n_hour, int n_min){
    this->brand = brand;
    this->type = type;
    this->date = date;
    this->n_hour =n_hour;
    this->n_min = n_min;
}

string Vehicle::getBrand() const{
    return brand;
}

string Vehicle::getType() const{
    return type;
}

Time Vehicle::getDate() const{
    return date;
}
int Vehicle::getNDel() const {
    return n_del;
}
int Vehicle::getNHour() const {
    return n_hour;
}
int Vehicle::getNMin() const {
    return n_min;
}

void Vehicle::setBrand(string brand){
    this-> brand = brand;
}

void Vehicle::setType(string type){
    this->type = type;
}

void Vehicle::setDate(Time date){
    this->date = date;
}

void Vehicle::setNDel(int ndel) {
    this->n_del = ndel;
}
void Vehicle::setNHour(int hour) {
    this->n_hour=hour;
}
void Vehicle::setNMin(int min) {
    this->n_min=min;
}
void Vehicle::addDelivery(){
    n_del++;
}
ostream& operator<<(ostream& os, const Vehicle& v){
    os << v.getBrand() << ", " << v.getType() << ", " << v.getDate()<<"\t"<<v.getNHour()<<"\t"<<v.getNMin();
    return os;
}


