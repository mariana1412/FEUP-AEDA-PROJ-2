#include "StringConverters.h"

vector<string> stringToStringVector(string str){ //Types of food
    string delimiter = ",";
    vector<string> data;
    vector<string> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        result.push_back(i);
    }

    return result;
}

vector<Product> stringToProductVector(string str){
    string delimiter = "/";
    vector<string> data;
    vector<string> data_clean;
    Product current;
    vector<Product> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back((i));
    }
    for (auto & i : data_clean){
        current.setName(stringToStringVector(i).at(0));
        current.setType_of_food(stringToStringVector(i).at(1));
        current.setPrice(stof(stringToStringVector(i).at(2)));
        result.push_back(current);
    }
    return result;
}

Time stringToDate(string str){
    string delimiter = "/";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    Time result(0,0,data_clean.at(0),data_clean.at(1),data_clean.at(2));
    return result;
}

Vehicle stringToVehicle(string str){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    Vehicle result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(i);
    }
    result.setBrand(data_clean.at(0));
    result.setType(data_clean.at(1));
    result.setDate(stringToDate(data_clean.at(2)));
    return result;
}

Time stringToTime(string str){
    vector<string> split = stringToStringVector(str);
    Time result = stringToDate(split.at(0));
    str= split.at(1);
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    result.setHour(data_clean.at(0));
    result.setMinutes(data_clean.at(1));
    return result;
}

Time stringToHour(string str){
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    Time result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    result.setHour(data_clean.at(0));
    result.setMinutes(data_clean.at(1));
    return result;
}

Location stringToLocation(string str){
    Location location;
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data)
    {
        trim(i);
        data_clean.push_back(i);
    }
    if (data_clean.size() == 3){
        location.setAddress(data_clean.at(0));
        location.setCounty(data_clean.at(1));
        location.setGps(data_clean.at(2));
    }
    else{
        location.setAddress(data_clean.at(0));
        location.setCounty(data_clean.at(1));
    }

    return location;
}

//Returns a client if str is the client's NIF
vector<Client> stringToClientVectorSearch(string str, const Base& b) {   //Blacklist
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Client> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }

    vector<Client> clients = b.getClients();
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Client>::const_iterator it1 = clients.begin(); it1 != clients.end(); it1++){
            if ((*it) == it1->getNif())
                result.push_back((*it1));
        }
    }
    return result;
}

vector<Product> stringToProductVectorSearch(string str, const Restaurant& r){
    string delimiter = ",";
    vector<string> data;
    vector<string> data_clean;
    vector<Product> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(i);
    }
    vector<Product> products = r.getProducts();
    for (vector<string>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Product>::const_iterator it1 = products.begin();it1 != products.end(); it1++){
            if ((*it) == (it1->getName()))
                result.push_back((*it1));
        }
    }
    return result;
}

vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b){
    string delimiter = ",";
    vector<string> data;
    vector<int> data_clean;
    vector<Delivery> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {\
        trim(i);
        data_clean.push_back(stoi(i));
    }
    vector<Delivery> deliveries = b.getDeliveries();
    for (vector<int>::const_iterator it = data_clean.begin(); it != data_clean.end(); it++){
        for (vector<Delivery>::const_iterator it1 = deliveries.begin(); it1 != deliveries.end(); it1++){
            if ((*it) == (it1->getId()))
                result.push_back((*it1));
        }
    }
    return result;
}

bool stringToAdminSearch(string str, const Base& b){
    vector<Employee*> employees = b.getEmployees();
    for (vector<Employee*>::const_iterator it = employees.begin(); it != employees.end(); it++) {
        Admin *na = dynamic_cast<Admin *>((*it));
        if (na == nullptr)
            continue;
        else{
            if (stoi(str) == na->getNif())
                return true;
        }
    }
    return false;
}
