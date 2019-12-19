#include "WriteToFile.h"

void write_Clients(const Base& baseP,const Base& baseL,const Base& baseF){
    ofstream clientfile;
    clientfile.open("../Clients.txt");
    int count = 0;
    vector<Client> clientes_porto = baseP.getClients();
    vector<Client> clientes_lisboa = baseL.getClients();
    vector<Client> clientes_faro = baseF.getClients();
    if (clientfile.is_open()){
        for (vector<Client>::const_iterator it = clientes_porto.begin() ; it != clientes_porto.end(); it++) {
            if (it != clientes_porto.begin())
                clientfile << endl << "::::::::" << endl;
            clientfile << "Porto" << endl;
            clientfile << it->getName() << endl;
            clientfile << it->getNif() << endl;
            clientfile << it->getAddress() << ", " << it->getCounty() << endl;
            if (it->getBlack() == true){
                clientfile << "true" ;
            }
            else
                clientfile << "false";
        }

        if (clientes_porto.size() != 0) {
            if (clientes_lisboa.size() != 0 || clientes_faro.size() != 0)
                clientfile << endl << "::::::::" << endl;
        }

        for (vector<Client>::const_iterator it = clientes_lisboa.begin() ; it != clientes_lisboa.end(); it++)
        {
            if (it != clientes_lisboa.begin())
                clientfile << endl << "::::::::" << endl;
            clientfile << "Lisboa" << endl;
            clientfile << it->getName() << endl;
            clientfile << it->getNif() << endl;
            clientfile << it->getAddress() << ", " << it->getCounty() << endl;
            if (it->getBlack() == true){
                clientfile << "true" ;
            }
            else
                clientfile << "false" ;
        }
        if (clientes_lisboa.size() != 0) {
            if (clientes_faro.size() != 0)
                clientfile << endl << "::::::::" << endl;
        }

        for (vector<Client>::const_iterator it = clientes_faro.begin() ; it != clientes_faro.end(); it++)
        {
            count++;
            clientfile << "Faro" << endl;
            clientfile << it->getName() << endl;
            clientfile << it->getNif() << endl;
            clientfile << it->getAddress() << ", " << it->getCounty() << endl;
            if (it->getBlack() == true){
                clientfile << "true";
            }
            else
                clientfile << "false";
            if (count != (clientes_faro.size()))
                clientfile << endl << "::::::::" << endl;
        }
    }
    else
        cerr << "File could not be opened";
    clientfile.close();
}
void write_Restaurants(const Base& baseP,const Base& baseL,const Base& baseF){
    ofstream restaurantfile;
    restaurantfile.open("../Restaurants.txt");
    int count = 0;
    int count1 = 0;
    vector<Restaurant> restaurantes_porto = baseP.getRestaurants();
    vector<Restaurant> restaurantes_lisboa = baseL.getRestaurants();
    vector<Restaurant> restaurantes_faro = baseF.getRestaurants();
    if (restaurantfile.is_open()) {
        for (vector<Restaurant>::const_iterator it = restaurantes_porto.begin(); it != restaurantes_porto.end(); it++) {
            if (it != restaurantes_porto.begin())
                restaurantfile << endl << "::::::::" << endl;
            restaurantfile << "Porto" << endl;
            restaurantfile << it->getName() << endl;
            restaurantfile << it->getAddress() << ", " << it->getCounty() << endl;
            vector<string> toF = it->getTypes_of_food();
            for (vector<string>::const_iterator it1 = toF.begin(); it1 != toF.end(); it1++) {
                count++;
                if (count != toF.size())
                    restaurantfile << (*it1) << ", ";
                else
                    restaurantfile << (*it1);
            }
            count = 0;
            restaurantfile << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (count != products.size())
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice() << " / ";
                else
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice();
            }
            count = 0;
            restaurantfile << endl;
            restaurantfile << it->getRevenue();
        }
        if (restaurantes_porto.size() != 0) {
            if (restaurantes_lisboa.size() != 0 || restaurantes_faro.size() != 0)
                restaurantfile << endl << "::::::::" << endl;
        }

        for (vector<Restaurant>::const_iterator it = restaurantes_lisboa.begin(); it != restaurantes_lisboa.end(); it++) {
            if (it != restaurantes_lisboa.begin())
                restaurantfile << endl << "::::::::" << endl;
            restaurantfile << "Lisboa" << endl;
            restaurantfile << it->getName() << endl;
            restaurantfile << it->getAddress() << ", " << it->getCounty() << endl;
            vector<string> toF = it->getTypes_of_food();
            for (vector<string>::const_iterator it1 = toF.begin(); it1 != toF.end(); it1++) {
                count++;
                if (count != toF.size())
                    restaurantfile << (*it1) << ", ";
                else
                    restaurantfile << (*it1);
            }
            count = 0;
            restaurantfile << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (count != products.size())
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice() << " / ";
                else
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice();
            }
            count = 0;
            restaurantfile << endl;
            restaurantfile << it->getRevenue();
        }

        if (restaurantes_lisboa.size() != 0) {
            if (restaurantes_faro.size() != 0)
                restaurantfile << endl << "::::::::" << endl;
        }

        for (vector<Restaurant>::const_iterator it = restaurantes_faro.begin(); it != restaurantes_faro.end(); it++) {
            count1++;
            restaurantfile << "Faro" << endl;
            restaurantfile << it->getName() << endl;
            restaurantfile << it->getAddress() << ", " << it->getCounty() << endl;
            vector<string> toF = it->getTypes_of_food();
            for (vector<string>::const_iterator it1 = toF.begin(); it1 != toF.end(); it1++) {
                count++;
                if (count != toF.size())
                    restaurantfile << (*it1) << ", ";
                else
                    restaurantfile << (*it1);
            }
            count = 0;
            restaurantfile << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (count != products.size())
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice() << " / ";
                else
                    restaurantfile << it1->getName() << ", " << it1->getType_of_food() << ", " << it1->getPrice();
            }
            count = 0;
            restaurantfile << endl;
            restaurantfile << it->getRevenue();
            if (count1 != restaurantes_faro.size())
                restaurantfile << endl << "::::::::" << endl;
        }
    }
    else
        cerr << "File could not be opened";
    restaurantfile.close();
}


void write_Deliveries(const Base& baseP,const Base& baseL,const Base& baseF){
    ofstream deliveryfile;
    deliveryfile.open("../Orders.txt");
    int count = 0;
    int count1 = 0;
    vector<Delivery> deliveries_porto = baseP.getDeliveries();
    vector<Delivery> deliveries_lisboa = baseL.getDeliveries();
    vector<Delivery> deliveries_faro = baseF.getDeliveries();
    if (deliveryfile.is_open()) {
        for (vector<Delivery>::const_iterator it = deliveries_porto.begin(); it != deliveries_porto.end(); it++) {
            if (it != deliveries_porto.begin())
                deliveryfile << endl << "::::::::" << endl;
            deliveryfile << "Porto" << endl;
            deliveryfile << it->getId() << endl;
            deliveryfile << it->getNif() <<endl;
            deliveryfile << it->getRestaurant().getName()<< endl;
            deliveryfile << setw(2) << setfill('0') << it->getTime().getDay() << "/" << setw(2) << setfill('0') <<  it->getTime().getMonth() << "/" << it->getTime().getYear() << ", " << setw(2) << setfill('0') << it->getTime().getHour() << ":" << setw(2) << setfill('0') << it->getTime().getMinutes() << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (products.size() == count)
                    deliveryfile << it1->getName() << endl;
                else
                    deliveryfile << it1->getName() << ", ";
            }
            count = 0;
            if (it->getSuccess()){
                deliveryfile << "Success" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            else {
                deliveryfile << "Insuccess" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            deliveryfile << setw(2) << setfill('0') << it->getDeliver_time().getDay() << "/" << setw(2) << setfill('0') <<  it->getDeliver_time().getMonth() << "/" << setw(4) << setfill('0') << it->getDeliver_time().getYear() << ", " << setw(2) << setfill('0') << it->getDeliver_time().getHour() << ":" << setw(2) << setfill('0') << it->getDeliver_time().getMinutes() << endl;
            deliveryfile << it->getTax();
        }
        if (deliveries_porto.size() != 0) {
            if (deliveries_lisboa.size() != 0 || deliveries_faro.size() != 0)
                deliveryfile << endl << "::::::::" << endl;
        }

        for (vector<Delivery>::const_iterator it = deliveries_lisboa.begin(); it != deliveries_lisboa.end(); it++) {
            if (it != deliveries_lisboa.begin())
                deliveryfile << endl << "::::::::" << endl;
            deliveryfile << "Lisboa" << endl;
            deliveryfile << it->getId() << endl;
            deliveryfile << it->getNif()<<endl;
            deliveryfile << it->getRestaurant().getName()<< endl;
            deliveryfile << setw(2) << setfill('0') << it->getTime().getDay() << "/" << setw(2) << setfill('0') << it->getTime().getMonth() << "/" << it->getTime().getYear() << ", " << setw(2) << setfill('0') << it->getTime().getHour() << ":" <<setw(2) << setfill('0') << it->getTime().getMinutes() << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (products.size() == count)
                    deliveryfile << it1->getName() << endl;
                else
                    deliveryfile << it1->getName() << ", ";
            }
            count = 0;
            if (it->getSuccess()){
                deliveryfile << "Success" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            else {
                deliveryfile << "Insuccess" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            deliveryfile << setw(2) << setfill('0') << it->getDeliver_time().getDay() << "/" << setw(2) << setfill('0') <<  it->getDeliver_time().getMonth() << "/" << setw(4) << setfill('0') <<  it->getDeliver_time().getYear() << ", " << setw(2) << setfill('0') << it->getDeliver_time().getHour() << ":" << setw(2) << setfill('0') << it->getDeliver_time().getMinutes() << endl;
            deliveryfile << it->getTax();
        }
        if (deliveries_lisboa.size() != 0) {
            if (deliveries_faro.size() != 0)
                deliveryfile << endl << "::::::::" << endl;
        }

        for (vector<Delivery>::const_iterator it = deliveries_faro.begin(); it != deliveries_faro.end(); it++) {
            count1++;
            deliveryfile << "Faro" << endl;
            deliveryfile << it->getId() << endl;
            deliveryfile << it->getNif()<<endl;
            deliveryfile << it->getRestaurant().getName()<< endl;
            deliveryfile << setw(2) << setfill('0') << it->getTime().getDay() << "/" << setw(2) << setfill('0') << it->getTime().getMonth() << "/" << it->getTime().getYear() << ", " << setw(2) << setfill('0') << it->getTime().getHour() << ":" << setw(2) << setfill('0') << it->getTime().getMinutes() << endl;
            vector<Product> products = it->getProducts();
            for (vector<Product>::const_iterator it1 = products.begin(); it1 != products.end(); it1++) {
                count++;
                if (products.size() == count)
                    deliveryfile << it1->getName() << endl;
                else
                    deliveryfile << it1->getName() << ", ";
            }
            count = 0;
            if (it->getSuccess()){
                deliveryfile << "Success" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            else {
                deliveryfile << "Insuccess" << endl;
                deliveryfile << it->getReason_insuccess() << endl;
            }
            deliveryfile << setw(2) << setfill('0') << it->getDeliver_time().getDay() << "/" << setw(2) << setfill('0') <<  it->getDeliver_time().getMonth() << "/" << setw(4) << setfill('0') << it->getDeliver_time().getYear() << ", " << setw(2) << setfill('0') << it->getDeliver_time().getHour() << ":" << setw(2) << setfill('0') << it->getDeliver_time().getMinutes() << endl;
            deliveryfile << it->getTax();
            if (count1 != (deliveries_faro.size()))
                deliveryfile << endl << "::::::::" << endl;
        }
    }
    else
        cerr << "File could not be opened";
    deliveryfile.close();
}


void write_Employees(const Base& baseP,const Base& baseL,const Base& baseF){
    ofstream employeefile;
    employeefile.open("../Employees.txt");
    int count = 0;
    int count1 = 0;
    vector<Employee*> employees_porto = baseP.getEmployees();
    vector<Employee*> employees_lisboa = baseL.getEmployees();
    vector<Employee*> employees_faro = baseF.getEmployees();
    if (employeefile.is_open()) {
        for (Employee* e: employees_porto){
            count++;
            Admin* na = dynamic_cast<Admin*>(e);
            Deliverer* nd = dynamic_cast<Deliverer*>(e);
            if (count != 1)
                employeefile << endl << "::::::::" << endl;
            if (na != nullptr){
                employeefile << "Porto" << endl;
                employeefile << "Admin" << endl;
                employeefile << na->getName() << endl;
                employeefile << na->getNif() << endl;
                employeefile << setw(2) << setfill('0') << na->getBirthdate().getDay() << "/" << setw(2) << setfill('0') <<na->getBirthdate().getMonth() << "/" << na->getBirthdate().getYear() << endl;
                employeefile << na->getIncome() << endl;
                employeefile << na->getTask();
            }
            else{
                employeefile << "Porto" << endl;
                employeefile << "Deliverer" << endl;
                employeefile << nd->getName() << endl;
                employeefile << nd->getNif() << endl;
                employeefile <<setw(2) << setfill('0') << nd->getBirthdate().getDay() << "/" <<setw(2) << setfill('0') << nd->getBirthdate().getMonth() << "/" << setw(4) << setfill('0') << nd->getBirthdate().getYear() << endl;
                employeefile << nd->getIncome() << endl;
                employeefile << nd->getVehicle().getBrand() << ", " << nd->getVehicle().getType() << ", " <<setw(2) << setfill('0') << nd->getVehicle().getDate().getDay() << "/" <<setw(2) << setfill('0') << nd->getVehicle().getDate().getMonth() << "/" << setw(4) << setfill('0') << nd->getVehicle().getDate().getYear() << endl;
                if (nd->getBackground().size() == 0)
                    employeefile << "0";
                else {
                    vector<Delivery> deliveries = nd->getBackground();
                    count1 = 0;
                    for (vector<Delivery>::const_iterator it = deliveries.begin(); it != deliveries.end(); it++) {
                        count1++;
                        if (count1 != deliveries.size())
                            employeefile << it->getId() << ", ";
                        else
                            employeefile << it->getId();
                    }
                }
            }
        }

        count = 0;
        if (employees_porto.size() != 0) {
            if (employees_lisboa.size() != 0 || employees_faro.size() != 0)
                employeefile << endl << "::::::::" << endl;
        }

        for (Employee* e: employees_lisboa){
            count++;
            Admin* na = dynamic_cast<Admin*>(e);
            Deliverer* nd = dynamic_cast<Deliverer*>(e);
            if (count != 1)
                employeefile << endl <<"::::::::" << endl;
            if (na != nullptr){
                employeefile << "Lisboa" << endl;
                employeefile << "Admin" << endl;
                employeefile << na->getName() << endl;
                employeefile << na->getNif() << endl;
                employeefile << setw(2) << setfill('0') <<na->getBirthdate().getDay() << "/" <<setw(2) << setfill('0') << na->getBirthdate().getMonth() << "/" << setw(4) << setfill('0') << na->getBirthdate().getYear() << endl;
                employeefile << na->getIncome() << endl;
                employeefile << na->getTask();
            }
            else{
                employeefile << "Lisboa" << endl;
                employeefile << "Deliverer" << endl;
                employeefile << nd->getName() << endl;
                employeefile << nd->getNif() << endl;
                employeefile <<setw(2) << setfill('0') << nd->getBirthdate().getDay() << "/" <<setw(2) << setfill('0') << nd->getBirthdate().getMonth() << "/" << setw(4) << setfill('0') << nd->getBirthdate().getYear() << endl;
                employeefile << nd->getIncome() << endl;
                employeefile << nd->getVehicle().getBrand() << ", " << nd->getVehicle().getType() << ", " << setw(2) << setfill('0') <<nd->getVehicle().getDate().getDay() << "/" <<setw(2) << setfill('0') << nd->getVehicle().getDate().getMonth() << "/" << setw(4) << setfill('0') << nd->getVehicle().getDate().getYear() << endl;
                if (nd->getBackground().size() == 0)
                    employeefile << "0";
                else {
                    vector<Delivery> deliveries = nd->getBackground();
                    count1 = 0;
                    for (vector<Delivery>::const_iterator it = deliveries.begin(); it != deliveries.end(); it++) {
                        count1++;
                        if (count1 != deliveries.size())
                            employeefile << it->getId() << ", ";
                        else
                            employeefile << it->getId();
                    }
                }
            }
        }

        count = 0;

        if (employees_lisboa.size() != 0) {
            if (employees_faro.size() != 0)
                employeefile << endl << "::::::::" << endl;
        }

        for (Employee* e: employees_faro){
            count++;
            Admin* na = dynamic_cast<Admin*>(e);
            Deliverer* nd = dynamic_cast<Deliverer*>(e);
            if (na != nullptr){
                employeefile << "Faro" << endl;
                employeefile << "Admin" << endl;
                employeefile << na->getName() << endl;
                employeefile << na->getNif() << endl;
                employeefile << setw(2) << setfill('0') <<na->getBirthdate().getDay() << "/" <<setw(2) << setfill('0') << na->getBirthdate().getMonth() << "/" << setw(4) << setfill('0') << na->getBirthdate().getYear() << endl;
                employeefile << na->getIncome() << endl;
                employeefile << na->getTask();
            }
            else{
                employeefile << "Faro" << endl;
                employeefile << "Deliverer" << endl;
                employeefile << nd->getName() << endl;
                employeefile << nd->getNif() << endl;
                employeefile << nd->getBirthdate().getDay() << "/" << nd->getBirthdate().getMonth() << "/" << setw(4) << setfill('0') << nd->getBirthdate().getYear() << endl;
                employeefile << nd->getIncome() << endl;
                employeefile << nd->getVehicle().getBrand() << ", " << nd->getVehicle().getType() << ", " <<setw(2) << setfill('0') << nd->getVehicle().getDate().getDay() << "/" <<setw(2) << setfill('0') << nd->getVehicle().getDate().getMonth() << "/" << setw(4) << setfill('0') << nd->getVehicle().getDate().getYear() << endl;
                if (nd->getBackground().size() == 0)
                    employeefile << "0";
                else {
                    vector<Delivery> deliveries = nd->getBackground();
                    count1 = 0;
                    for (vector<Delivery>::const_iterator it = deliveries.begin(); it != deliveries.end(); it++) {
                        count1++;
                        if (count1 != deliveries.size())
                            employeefile << it->getId() << ", ";
                        else
                            employeefile << it->getId();
                    }
                }
            }
            if (count != employees_faro.size())
                employeefile << endl << "::::::::" << endl;
        }
    }
    else
        cerr << "File could not be opened";
    employeefile.close();
}

void write_Bases(string boss, int nif, Base& baseP,const Base& baseL,const Base& baseF){
    ofstream basefile;
    basefile.open("../Base.txt");
    int count = 0;
    if (basefile.is_open()){
        basefile << boss <<endl;
        basefile << nif <<endl;
        basefile << "::::::::" << endl;
        basefile << "Porto" << endl;
        basefile << baseP.getLocation().getAddress() << ", " << baseP.getLocation().getCounty() << ", " << baseP.getLocation().getGps() << endl;
        basefile << baseP.getManager() << endl;
        basefile << baseP.getManagerNif()<<endl;
        if (baseP.getBlackList().size() != 0) {
            vector<Client> blacklist = baseP.getBlackList();
            for (vector<Client>::const_iterator it = blacklist.begin(); it != blacklist.end(); it++) {
                count++;
                if (count != blacklist.size())
                    basefile << it->getNif() << ", ";
                else
                    basefile << it->getNif() << endl;
            }
        }
        else
            basefile << "0" << endl;
        basefile << "::::::::" << endl;

        count = 0;
        basefile << "Lisboa" << endl;
        basefile << baseL.getLocation().getAddress() << ", " << baseL.getLocation().getCounty() << ", " << baseL.getLocation().getGps() << endl;
        basefile << baseL.getManager() << endl;
        basefile << baseL.getManagerNif()<<endl;
        if (baseL.getBlackList().size() != 0) {
            vector<Client> blacklist1 = baseL.getBlackList();
            for (vector<Client>::const_iterator it = blacklist1.begin(); it != blacklist1.end(); it++) {
                count++;
                if (count != blacklist1.size())
                    basefile << it->getNif() << ", ";
                else
                    basefile << it->getNif() << endl;
            }
        }
        else
            basefile << "0" << endl;
        basefile << "::::::::" << endl;

        count = 0;
        basefile << "Faro" << endl;
        basefile << baseF.getLocation().getAddress() << ", " << baseF.getLocation().getCounty() << ", " << baseF.getLocation().getGps() << endl;
        basefile << baseF.getManager() << endl;
        basefile << baseF.getManagerNif()<<endl;
        if (baseF.getBlackList().size() != 0) {
            vector<Client> blacklist2 = baseF.getBlackList();
            for (vector<Client>::const_iterator it = blacklist2.begin(); it != blacklist2.end(); it++) {
                count++;
                if (count != blacklist2.size())
                    basefile << it->getNif() << ", ";
                else
                    basefile << it->getNif();
            }
        }
        else
            basefile << "0";
    }

    else
        cerr << "File could not be opened";
    basefile.close();
}