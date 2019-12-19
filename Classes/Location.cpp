#include "Location.h"


Location::Location() {}

Location::Location(string address, string county, string gps){
    this-> address=address;
    this-> county=county;
    this-> gps=gps;
}
string Location::getAddress() const{
    return address;
}

string Location::getCounty() const{
    return county;
}

string Location::getGps() const{
    return gps;
}

void Location::setAddress(string address){
    this->address = address;
}

void Location::setCounty(string county){
    this->county = county;
}

void Location::setGps(string gps){
    this->gps = gps;
}

ostream& operator<<(ostream& os, const Location& l){
    os << l.getAddress() << ", " << l.getCounty() << ", [" << l.getGps() << "]";
    return os;
}
