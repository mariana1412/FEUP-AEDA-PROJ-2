#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(string brand, string type, Time date){
    this->brand = brand;
    this->type = type;
    this->date = date;
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

void Vehicle::setBrand(string brand){
    this-> brand = brand;
}

void Vehicle::setType(string type){
    this->type = type;
}

void Vehicle::setDate(Time date){
    this->date = date;
}

ostream& operator<<(ostream& os, const Vehicle& v){
    os << v.getBrand() << ", " << v.getType() << ", " << v.getDate();
    return os;
}


