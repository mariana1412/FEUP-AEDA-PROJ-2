#include "ReadingFiles.h"
#include "../Functions/StringConverters.h"

void extract_Clients(Base& baseP, Base& baseL, Base& baseF){
    string line, name, nif;
    Time birthdate;
    ifstream clientfile;
    clientfile.open("../Clients.txt");
    if (clientfile.is_open()) {
        while (!clientfile.eof()) {
            bool black = false;
            getline(clientfile, line);
            if (line == "Porto"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                birthdate = stringToDate(line);
                getline(clientfile, line);
                Location location = stringToLocation(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseP.addClient(Client("Porto", name, stoi(nif), location.getAddress(), black, location.getCounty(), birthdate));
                continue;
            }

            if (line == "Lisboa"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                birthdate = stringToDate(line);
                getline(clientfile, line);
                Location location = stringToLocation(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseL.addClient(Client("Lisboa", name, stoi(nif), location.getAddress(), black, location.getCounty(), birthdate));
                continue;
            }

            if (line == "Faro"){
                getline(clientfile, name);
                getline(clientfile, nif);
                getline(clientfile, line);
                birthdate = stringToDate(line);
                getline(clientfile, line);
                Location location = stringToLocation(line);
                getline(clientfile, line);
                if (line == "true")
                    black = true;
                getline(clientfile, line); //separator
                baseF.addClient(Client("Faro", name, stoi(nif), location.getAddress(), black, location.getCounty(), birthdate));
                continue;
            }
        }
    }
    else
        cerr << "Clients.txt could not be opened!" << endl;
    clientfile.close();

}

void extract_Restaurants(Base& baseP, Base& baseL, Base& baseF){
    string line, name, revenue;
    vector<string> types_of_food;
    vector<Product> products;
    ifstream restaurantfile;
    restaurantfile.open("../Restaurants.txt");
    if (restaurantfile.is_open()) {
        while (!restaurantfile.eof()) {
            getline(restaurantfile, line);
            if (line == "Porto") {
                getline(restaurantfile, name);
                getline(restaurantfile, line);
                Location location = stringToLocation(line);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseP.addRestaurant(Restaurant(name, location.getAddress(), location.getCounty(), types_of_food, products, stof(revenue)));
                continue;
            }

            if (line == "Lisboa") {
                getline(restaurantfile, name);
                getline(restaurantfile, line);
                Location location = stringToLocation(line);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseL.addRestaurant(Restaurant(name, location.getAddress(), location.getCounty(), types_of_food, products, stof(revenue)));
                continue;
            }

            if (line == "Faro") {
                getline(restaurantfile, name);
                getline(restaurantfile, line);
                Location location = stringToLocation(line);
                getline(restaurantfile, line);
                types_of_food = stringToStringVector(line);
                getline(restaurantfile, line);
                products = stringToProductVector(line);
                getline(restaurantfile, revenue);
                getline(restaurantfile, line); //separator
                baseF.addRestaurant(Restaurant(name, location.getAddress(),location.getCounty(), types_of_food, products, stof(revenue)));
                continue;
            }
        }
    }
    else
        cerr << "Restaurants.txt could not be opened! " << endl;
    restaurantfile.close();
}

void extract_Deliveries(Base& baseP, Base& baseL, Base& baseF){
    string line, reason, id, tax, success,nif;
    bool made = false, discount;
    Restaurant restaurant;
    Time date;
    Time hour;
    vector<Product> products;
    ifstream deliveryfile;
    deliveryfile.open("../Orders.txt");
    if (deliveryfile.is_open()) {
        while (!deliveryfile.eof()) {
            getline(deliveryfile, line);
            if (line == "Porto") {
                getline(deliveryfile, id);
                getline(deliveryfile, nif);
                getline(deliveryfile, line);
                restaurant = baseP.searchRestaurant(line);
                getline(deliveryfile, line);
                if(line == "true") discount = true;
                else discount = false;
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, restaurant);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToTime(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseP.addDelivery(Delivery(restaurant, date, products, stoi(nif),stoi(id), made, reason, hour, stof(tax), discount));
                continue;
            }

            if (line == "Lisboa") {
                getline(deliveryfile, id);
                getline(deliveryfile, nif);
                getline(deliveryfile, line);
                restaurant = baseL.searchRestaurant(line);
                getline(deliveryfile, line);
                if(line == "true") discount = true;
                else discount = false;
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, restaurant);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToTime(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseL.addDelivery(Delivery(restaurant, date, products, stoi(nif),stoi(id), made, reason, hour, stof(tax), discount));
                continue;
            }

            if (line == "Faro") {
                getline(deliveryfile, id);
                getline(deliveryfile, nif);
                getline(deliveryfile, line);
                restaurant = baseF.searchRestaurant(line);
                getline(deliveryfile, line);
                if(line == "true") discount = true;
                else discount = false;
                getline(deliveryfile, line);
                date = stringToTime(line);
                getline(deliveryfile, line);
                products = stringToProductVectorSearch(line, restaurant);
                getline(deliveryfile, success);
                if (success == "Success")
                    made = true;
                else if (success == "Insuccess")
                    made = false;
                getline(deliveryfile, reason);
                getline(deliveryfile, line);
                hour = stringToTime(line);
                getline(deliveryfile, tax);
                getline(deliveryfile, line); //separator
                baseF.addDelivery(Delivery(restaurant, date, products, stoi(nif),stoi(id), made, reason, hour, stof(tax), discount));
                continue;
            }
        }
    }
    else
        cerr << "Orders.txt could not be opened!" << endl;
    deliveryfile.close();
}

void extract_Employees(Base& baseP, Base& baseL, Base& baseF) {
    string line, name, nif, income, task;
    bool former;
    Time birthdate;
    Vehicle vehicle;
    vector<Delivery> deliveries;
    ifstream employeefile;
    employeefile.open("../Employees.txt");
    if (employeefile.is_open()) {
        while (!employeefile.eof()) {
            getline(employeefile, line);
            if (line == "Porto") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    Employee* e = new Admin("Porto", name, stoi(nif), birthdate, stof(income), task, former);
                    baseP.addEmployee(e);
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    if (line != "0") {
                        deliveries = stringToDeliveryVectorSearch(line, baseP);
                        vehicle.setTotalDel(deliveries.size());
                    }
                    else
                        deliveries = {};
                    baseP.addVehicle(vehicle);
                    getline(employeefile, line);    //separator
                    Employee* e = new Deliverer("Porto", name, stoi(nif), birthdate, stof(income), vehicle, deliveries, former);
                    baseP.addEmployee(e);
                }
                continue;
            }

            if (line == "Lisboa") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    Employee* e = new Admin("Lisboa", name, stoi(nif), birthdate, stof(income), task, former);
                    baseL.addEmployee(e);
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    if (line != "0") {
                        deliveries = stringToDeliveryVectorSearch(line, baseL);
                        vehicle.setTotalDel(deliveries.size());
                    }
                    else
                        deliveries = {};
                    baseL.addVehicle(vehicle);
                    getline(employeefile, line);    //separator
                    Employee* e = new Deliverer("Lisboa", name, stoi(nif), birthdate, stof(income), vehicle, deliveries, former);
                    baseL.addEmployee(e);
                }
                continue;
            }

            if (line == "Faro") {
                getline(employeefile, line);
                if (line == "Admin") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, task);
                    getline(employeefile, line);    //separator
                    Employee* e = new Admin("Faro", name, stoi(nif), birthdate, stof(income), task, former);
                    baseF.addEmployee(e);
                }
                if (line == "Deliverer") {
                    getline(employeefile, name);
                    getline(employeefile, nif);
                    getline(employeefile, line);
                    if (line == "true") former = true;
                    else former = false;
                    getline(employeefile, line);
                    birthdate = stringToDate(line);
                    getline(employeefile, income);
                    getline(employeefile, line);
                    vehicle = stringToVehicle(line);
                    getline(employeefile, line);
                    if (line != "0") {
                        deliveries = stringToDeliveryVectorSearch(line, baseF);
                        vehicle.setTotalDel(deliveries.size());
                    }
                    else
                        deliveries = {};
                    baseF.addVehicle(vehicle);
                    getline(employeefile, line);    //separator
                    Employee* e = new Deliverer("Faro", name, stoi(nif), birthdate, stof(income), vehicle, deliveries, former);
                    baseF.addEmployee(e);
                }
                continue;
            } else
                cerr << "Employees.txt could not be opened!" << endl;
            employeefile.close();
        }
    }
}

void extract_Bases(Base& baseP, Base& baseL, Base& baseF,string &boss, int &boss_nif) {
    string line;
    ifstream basefile;
    basefile.open("../Base.txt");
    if (basefile.is_open()) {
        while (!basefile.eof()) {
            getline(basefile, boss);//name of the boss
            getline(basefile, line);
            boss_nif = stoi(line); //nif of the boss
            getline(basefile, line);    //separator
            getline(basefile, line);    //Porto
            getline(basefile, line);
            Location location = stringToLocation(line);
            baseP.setLocation(location);
            getline(basefile, line);
            baseP.setManager(line);
            getline(basefile, line);
            baseP.setManagerNif(stoi(line));
            getline(basefile, line);
            if (stoi(line) != 0)
                baseP.setBlacklist(stringToClientVectorSearch(line, baseP));

            getline(basefile, line);    //separator
            getline(basefile, line);    //Lisboa
            getline(basefile, line);
            Location location1 = stringToLocation(line);
            baseL.setLocation(location1);
            getline(basefile, line);
            baseL.setManager(line);
            getline(basefile, line);
            baseL.setManagerNif(stoi(line));
            getline(basefile, line);
            if (stoi(line) != 0)
                baseL.setBlacklist(stringToClientVectorSearch(line, baseL));

            getline(basefile, line);    //separator
            getline(basefile, line);    //Faro
            getline(basefile, line);
            Location location2 = stringToLocation(line);
            baseF.setLocation(location2);
            getline(basefile, line);
            baseF.setManager(line);
            getline(basefile, line);
            baseF.setManagerNif(stoi(line));
            getline(basefile, line);
            if (stoi(line) != 0)
                baseF.setBlacklist(stringToClientVectorSearch(line, baseF));
        }
    }
    else
        cerr << "Base.txt could not be opened!" << endl;
    basefile.close();
}

void extract_Tecs(Base& baseP, Base& baseL, Base& baseF){
    string line, i, n_maintenances,name,nif;
    int m_avail;
    Time birthdate;
    ifstream tecfile;

    tecfile.open("../Tecs.txt");

    if (tecfile.is_open()) {
        while (!tecfile.eof()) {
            line="";
            getline(tecfile, line);
            if (line == "Porto"){
                getline(tecfile, name);
                getline(tecfile, nif);
                getline(tecfile, line);
                birthdate = stringToDate(line);
                getline(tecfile, line);
                m_avail = stoi(line);
                getline(tecfile, n_maintenances);
                getline(tecfile, line);//separator
                baseP.addTec(Tec("Porto",name, birthdate,stoi(nif),m_avail,stoi(n_maintenances)));
                continue;
            }

            if (line == "Lisboa"){
                getline(tecfile, name);
                getline(tecfile, nif);
                getline(tecfile, line);
                birthdate = stringToDate(line);
                getline(tecfile, line);
                m_avail = stoi(line);
                getline(tecfile, n_maintenances);
                getline(tecfile, line);//separator
                baseL.addTec(Tec("Lisboa",name, birthdate,stoi(nif),m_avail,stoi(n_maintenances)));
                continue;
            }

            if (line == "Faro"){
                getline(tecfile, name);
                getline(tecfile, nif);
                getline(tecfile, line);
                birthdate = stringToDate(line);
                getline(tecfile, line);
                m_avail = stoi(line);
                getline(tecfile, n_maintenances);
                getline(tecfile, line);//separator
                baseF.addTec(Tec("Faro",name, birthdate,stoi(nif),m_avail,stoi(n_maintenances)));
                continue;
            }
        }
    }
    else
        cerr << "Tecs.txt could not be opened!" << endl;
    tecfile.close();

}



