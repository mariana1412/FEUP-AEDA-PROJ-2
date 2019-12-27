#include "Vehicle.h"

Vehicle::Vehicle(){}

Vehicle::Vehicle(string brand, string type, Time date, string lic_plate, int total_del, int total_km, int n_del, int n_min){
    this->brand = brand;
    this->type = type;
    this->date = date;
    this->lic_plate = lic_plate;
    this->total_del = total_del;
    this->n_del = n_del;
    this->total_km = total_km;
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
int Vehicle::getTotalDel() const {
    return total_del;
}

int Vehicle::getTotalKm() const {
    return total_km;
}

string Vehicle::getLicPlate() const {
    return lic_plate;
}
int Vehicle::getNDel() const {
    return n_del;
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
void Vehicle::setLicPlate(string plate) {
    this->lic_plate = plate;
}

void Vehicle::setTotalDel(int del) {
    this->total_del = del;
}

void Vehicle::setTotalKm(int km) {
    this->total_km = km;
}
void Vehicle::setNDel(int ndel) {
    this->n_del = ndel;
}

void Vehicle::setNMin(int min) {
    this->n_min=min;
}
void Vehicle::addDelivery(){
    n_del++;
}

void Vehicle::resetNDel(){
    n_del =0;
}

ostream& operator<<(ostream& os, const Vehicle& v){

    os << v.getBrand() << ", " << v.getType() << ", " << v.getDate()<<", " << v.getLicPlate() << ", " << v.getTotalDel() << " deliveries, " << v.getTotalKm() << " km";

    return os;
}

void Vehicle::PrintVehicle() const{
    int hours = n_min / 60;
    int min = n_min % 60;
    cout << lic_plate << endl;
    cout << "Brand: " << brand << endl;
    cout << "Type: " << type << endl;
    cout << "Date: " << date << endl;
    cout << "Total Deliveries: " << total_del << endl;
    cout << "Total Kilometres: " << total_km << endl;
    if (n_del == 5){
        cout << "Vehicle is in maintenance" << endl;
        cout << "Time left until maintenance ends: " << hours << ":" << min << endl;
    } else{
        cout << "Vehicle is operational" << endl;
        cout << "Number of deliveries until maintenance: " << 5-n_del << endl;
    }

}

bool Vehicle::operator<(const Vehicle &v1) const {
    if (this->total_del == v1.total_del){
        return this->total_km < v1.total_km;
    } else
        return this->total_del < v1.total_del;
}

bool Vehicle::operator==(const Vehicle &v1) const {
    return (this->lic_plate == v1.lic_plate);
}



