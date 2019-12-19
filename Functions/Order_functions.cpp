#include "Order_functions.h"

bool comparePrice(const pair<Restaurant, int> &p1, const pair<Restaurant, int> &p2){
    if(p1.first.getProducts().at(p1.second).getPrice() < p2.first.getProducts().at(p2.second).getPrice()) return true;
    return false;
}

vector<int> searchByRestaurant(Base base, string name, Restaurant& restaurant)  {
    bool isValid;
    vector<int> result;
    int option;

    do{
        try {
            restaurant = base.searchRestaurant(name);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Do you want to:" << endl << "1. Try again" << endl << "2. Return to Main Menu" << endl;
            menu_int_options(option, 1, 2);
            cin.ignore(1000, '\n');
            cout << endl << "-----------------------------------------------" << endl;

            if(option == 2){
                return result;
            }
            else if (option == 1){
                cout << "Try again. Restaurant's name:";
                getline(cin, name);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input:";
                    getline(cin, name);
                }
                formatting_string(name);
            }
        }
    } while(!isValid);

    system("cls");
    cout  << endl << "---------------- SEARCH BY RESTAURANT ----------------" << endl;

    cout << endl << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl << endl;

    int size = restaurant.getProducts().size();
    for(int i = 0; i < size; i++){
        cout << "Product " << i+1 <<  ": " << restaurant.getProducts().at(i) << endl;
    }


    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');
    if (option == 0)
        return {};
    result.push_back(option-1);

    cout << endl;
    while (option != 0) {
        system("cls");
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i < size; i++){
            cout << "Product " << i+1 <<  ": " << restaurant.getProducts().at(i) << endl;
        }

        cout << endl << "Product added to the cart! You currenty have " << result.size() << " products: " << endl;
        float total = 0;
        for (int x: result){
            cout << restaurant.getProducts().at(x).getName() << " - " << restaurant.getProducts().at(x).getPrice() << "$" << endl;
            total += restaurant.getProducts().at(x).getPrice();
        }
        cout << endl << "Total price (w/o tax): " << total << endl;
        cout << endl << "Do you want to order another product? Choose the number of the product (insert 0 to finish the order): ";
        product_menu(option, 0, size);
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(option-1);
    }
    return result;
}

vector<int> searchByArea(Base b, string base, string county, Restaurant& restaurant){

    bool isValid;
    int option;
    vector<int> result;

    do{
        try {
            restaurant.setCounty(county, base);
            isValid = true;
        }
        catch (RestaurantOutOfArea &msg){
            cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
            isValid = false;
            cout << "Do you want to:" << endl << "1. Try again" << endl << "2. Return to Main Menu" << endl;
            menu_int_options(option, 1, 2);
            cin.ignore(1000, '\n');
            cout << endl << "-----------------------------------------------" << endl;

            if(option == 2){
                return result;
            }
            else if (option == 1){
                cout << "Try again. Restaurant's county: ";
                getline(cin, county);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input:";
                    getline(cin, county);
                }
                verification_all_letters(county);
            }

        }

    } while(!isValid);

    int size = b.getRestaurants().size();
    int counter = 0;
    vector<int> index;


    system("cls");
    cout  << endl << "---------------- SEARCH BY AREA ----------------" << endl;

    cout << endl;
    for(int i = 0; i < size; i++){
        if(b.getRestaurants().at(i).getCounty() == county){
            index.push_back(i);
            counter++;
            cout << "--> Restaurant " << counter << endl << b.getRestaurants().at(i) << endl;
        }
    }

    if(counter == 0){
        system("cls");
        cout << endl << "There are no restaurants in this county!" << endl;
        Sleep(900);
        return {};
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Now choose the restaurant: " ;
    product_menu(option, 0, counter);

    if(option == 0) return {};

    restaurant = b.getRestaurants().at(index.at(option-1));
    size = restaurant.getProducts().size();

    system("cls");
    cout  << endl << "---------------- SEARCH BY AREA ----------------" << endl;
    cout << endl << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl << endl;

    for(int i = 0; i < size; i++){
        cout << "Product " << i+1 <<  ": " << restaurant.getProducts().at(i) << endl;
    }

    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');
    if (option == 0)
        return {};

    result.push_back(option-1);

    cout << endl;
    while (option != 0) {
        system("cls");
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl;
        for(int i = 0; i < size; i++){
            cout << "Product " << i+1 <<  ": " << restaurant.getProducts().at(i) << endl;
        }

        cout << endl << "Product added to the cart! You currenty have " << result.size() << " products: " << endl;
        float total = 0;
        for (int x: result){
            cout << restaurant.getProducts().at(x).getName() << " - " << restaurant.getProducts().at(x).getPrice() << "$" << endl;
            total += restaurant.getProducts().at(x).getPrice();
        }
        cout << endl << "Total price (w/o tax): " << total << endl;
        cout << endl << "Do you want to order another product? Choose the number of the product (insert 0 to finish the order): ";
        product_menu(option, 0, size);
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(option-1);
    }
    return result;

}

vector<int> searchByPrice(Base base, float pmax, Restaurant& restaurant){

    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;
    vector<int> result;

    for(int i = 0; i < size1; i++){
        size2 = base.getRestaurants().at(i).getProducts().size();
        for(int j = 0; j < size2; j++){
            if(base.getRestaurants().at(i).getProducts().at(j).getPrice() <= pmax){
                products.push_back(make_pair(base.getRestaurants().at(i), j));
            }
        }
    }

    if(products.empty()){
        cout << endl << "There are no products in this price range." << endl;
        Sleep(1500);
        return {};
    }

    sort(products.begin(), products.end(), comparePrice);

    system("cls");
    cout  << endl << "---------------- SEARCH BY PRICE ----------------" << endl << endl;

    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << " --> " << products.at(i).first.getName() << ", " << products.at(i).first.getCounty() << endl;
        cout << "Product " << i+1 << ": " << products.at(i).first.getProducts().at(products.at(i).second) << endl << endl;

    }

    int option;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    if (option == 0)
        return {};

    result.push_back(products.at(option-1).second);
    restaurant = products.at(option-1).first;

    vector<int> index;

    system("cls");
    cout  << endl << "---------------- SEARCH BY PRICE ----------------" << endl << endl;

    while (option != 0) {
        int count = 1;
        system("cls");
        size = products.size();
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl << endl;
        for(int i = 0; i<size; i++){
            if(products.at(i).first == restaurant){
                index.push_back(products.at(i).second);
                cout << "Product " << count << ": " << restaurant.getProducts().at(products.at(i).second)  << endl;
                count++;
            }
        }

        cout << endl << "Product added to the cart! You currenty have " << result.size() << " products: " << endl;
        float total = 0;
        for (int x: result){
            cout << restaurant.getProducts().at(x).getName() << " - " << restaurant.getProducts().at(x).getPrice() << "$" << endl;
            total += restaurant.getProducts().at(x).getPrice();
        }
        cout << endl << "Total price (w/o tax): " << total << endl;
        cout << endl << "Do you want to order another product? Choose the number of the product (insert 0 to finish the order): ";
        product_menu(option, 0, index.size());
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(index.at(option - 1));

    }
    return result;
}

vector<int> searchByTypeOfFood(Base base, string type_of_food, Restaurant& restaurant){
    vector<pair<Restaurant, int>> products;
    int size1 = base.getRestaurants().size(), size2;
    vector<int> result;

    for(int i = 0; i < size1; i++){
        size2 = base.getRestaurants().at(i).getProducts().size();
        for(int j = 0; j < size2; j++){
            if(base.getRestaurants().at(i).getProducts().at(j).getType_of_food() == type_of_food){
                products.push_back(make_pair(base.getRestaurants().at(i), j));
            }
        }
    }

    if(products.empty()){
        cout << endl << "There are no products with this type of food." << endl;
        Sleep(1500);
        return {};
    }

    system("cls");
    cout  << endl << "---------------- SEARCH BY TYPE OF FOOD ----------------" << endl << endl;

    int size = products.size();
    for(int i = 0; i<size; i++){
        cout << " --> " << products.at(i).first.getName() << ", " << products.at(i).first.getCounty() << endl;
        cout << "Product " << i+1 << ": " << products.at(i).first.getProducts().at(products.at(i).second) << endl << endl;
    }

    int option;
    cout << endl << "Do you want to order a product? Choose the number of the product (insert 0 to return to the main menu): ";
    product_menu(option, 0, size);
    cin.ignore(1000, '\n');

    if (option == 0)
        return {};

    result.push_back(products.at(option-1).second);
    restaurant = products.at(option-1).first;

    vector<int> index;
    system("cls");
    cout  << endl << "---------------- SEARCH BY TYPE OF FOOD ----------------" << endl << endl;
    while (option != 0) {
        int count = 1;
        system("cls");
        size = products.size();
        cout << " --> " << restaurant.getName() << ", " << restaurant.getCounty() << endl << endl;
        for(int i = 0; i<size; i++){
            if(products.at(i).first == restaurant){
                index.push_back(products.at(i).second);
                cout << "Product " << count << ": " << restaurant.getProducts().at(products.at(i).second)  << endl;
                count++;
            }
        }

        cout << endl << "Product added to the cart! You currenty have " << result.size() << " products: " << endl;
        float total = 0;
        for (int x: result){
            cout << restaurant.getProducts().at(x).getName() << " - " << restaurant.getProducts().at(x).getPrice() << "$" << endl;
            total += restaurant.getProducts().at(x).getPrice();
        }
        cout << endl << "Total price (w/o tax): " << total << endl;
        cout << endl << "Do you want to order another product? Choose the number of the product (insert 0 to finish the order): ";
        product_menu(option, 0, index.size());
        cin.ignore(1000, '\n');
        if (option != 0)
            result.push_back(index.at(option - 1));

    }

    return result;
}

int create_order(Base &Porto, Base &Lisboa, Base &Faro){
    Client cliente;
    string base;
    int option;
    system("cls");
    cout << endl << "---------------- CREATE ORDER ----------------" << endl;

    cout << "What's your base? ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);

    string aux;
    int index;
    bool black;

    cout << "What's your nif? ";
    getline(cin, aux);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_nif(aux);
    if(base == "Porto") {
        index = int_sequential_search_c(Porto.getClients(), stoi(aux));
        if(index != -1){
            black = Porto.getClients().at(index).getBlack();
            cliente = Porto.getClients().at(index);
        }
    }
    else if(base == "Lisboa"){
        index = int_sequential_search_c(Lisboa.getClients(), stoi(aux));
        if(index != -1){
            black = Lisboa.getClients().at(index).getBlack();
            cliente = Lisboa.getClients().at(index);
        }
    }
    else if(base == "Faro"){
        index = int_sequential_search_c(Faro.getClients(), stoi(aux));
        if(index != -1){
            black = Faro.getClients().at(index).getBlack();
            cliente = Faro.getClients().at(index);
        }
    }

    if(black){
        cout << "You are in the blacklist! Blacklisted clients cannot order!" << endl;
        Sleep(1500);
        return 1;
    }

    while(index == -1){
        cout << endl << "-----------------------------------------------" << endl;
        cout << "The inserted client does not exist. You have to create an account to order a product." << endl
             << "Do you want to:" << endl << "1. Try again" << endl << "2. Return to Main Menu" << endl;

        menu_int_options(option, 1, 2);
        cin.ignore(1000, '\n');
        cout << endl << "-----------------------------------------------" << endl;

        if(option == 1){
            cout << endl << "What's your nif? ";
            getline(cin, aux);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_nif(aux);
            if(base == "Porto"){
                index = int_sequential_search_c(Porto.getClients(), stoi(aux));
                if(index != -1){
                    black = Porto.getClients().at(index).getBlack();
                    cliente = Porto.getClients().at(index);
                }

            }
            else if(base == "Lisboa"){
                index = int_sequential_search_c(Lisboa.getClients(), stoi(aux));
                if(index != -1){
                    black = Lisboa.getClients().at(index).getBlack();
                    cliente = Lisboa.getClients().at(index);
                }
            }
            else if(base == "Faro"){
                index = int_sequential_search_c(Faro.getClients(), stoi(aux));
                if(index != -1){
                    black = Faro.getClients().at(index).getBlack();
                    cliente = Faro.getClients().at(index);
                }
            }
        }

        else {
            return 1;
        }
    }

    int nif = stoi(aux);
    vector<int> indprod;
    Restaurant restaurant;
    string auxiliar;

    do{
        system("cls");
        cout << "Welcome, " << cliente.getName() << "!" << endl << endl;

        cout << "Which search method do you want?" << endl;
        cout << "1. Restaurant" << endl;
        cout << "2. Area" << endl;
        cout << "3. Price" << endl;
        cout << "4. Type of Food" << endl;
        cout << "5. Visualize All Restaurants" << endl;
        cout << "0. Return to Main Menu" << endl;

        menu_int_options(option, 0, 5);
        cin.ignore(1000, '\n');



        if(option == 0){
            return 1;
        }

        else if(option == 1){
            system("cls");
            cout  << endl << "---------------- SEARCH BY RESTAURANT ----------------" << endl;
            cout << "Restaurant's name: ";
            getline(cin, auxiliar);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            formatting_string(auxiliar);
            if(base == "Porto") indprod = searchByRestaurant(Porto, auxiliar, restaurant);
            else if(base == "Lisboa") indprod = searchByRestaurant(Lisboa, auxiliar, restaurant);
            else if(base == "Faro") indprod = searchByRestaurant(Faro, auxiliar, restaurant);
        }

        else if(option == 2){
            system("cls");
            cout  << endl << "---------------- SEARCH BY AREA ----------------" << endl;
            cout << "Restaurant's county: ";
            getline(cin, auxiliar);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);

            if(base == "Porto") indprod = searchByArea(Porto, base, auxiliar, restaurant);
            else if(base == "Lisboa") indprod = searchByArea(Lisboa, base, auxiliar, restaurant);
            else if(base == "Faro") indprod = searchByArea(Faro, base, auxiliar, restaurant);
        }

        else if(option == 3){
            system("cls");
            cout  << endl << "---------------- SEARCH BY PRICE ----------------" << endl;
            cout  << "Maximum price: ";
            getline(cin, auxiliar);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_float(auxiliar);

            if(base == "Porto") indprod = searchByPrice(Porto, stof(auxiliar), restaurant);
            else if(base == "Lisboa") indprod = searchByPrice(Lisboa, stof(auxiliar), restaurant);
            else if(base == "Faro") indprod = searchByPrice(Faro, stof(auxiliar), restaurant);
        }
        else if(option == 4){
            system("cls");
            cout  << endl << "---------------- SEARCH BY TYPE OF FOOD ----------------" << endl;
            cout <<  "Type of food: ";
            getline(cin, auxiliar);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);

            if(base == "Porto") indprod = searchByTypeOfFood(Porto, auxiliar, restaurant);
            else if(base == "Lisboa") indprod = searchByTypeOfFood(Lisboa, auxiliar, restaurant);
            else if(base == "Faro") indprod = searchByTypeOfFood(Faro, auxiliar, restaurant);
        }
        else if (option == 5){
            system("cls");
            cout  << endl << "---------------- VISUALIZE ALL RESTAURANTS ----------------" << endl << endl;
            if(base == "Porto"){
                for(int i = 0; i < Porto.getRestaurants().size(); i++){
                    cout << endl <<  "--> Restaurant " << i+1 << endl;
                    cout << Porto.getRestaurants().at(i) << endl;
                }
            }
            else if(base == "Lisboa"){
                for(int i = 0; i < Lisboa.getRestaurants().size(); i++){
                    cout << endl << "--> Restaurant " << i+1 << endl;
                    cout << Lisboa.getRestaurants().at(i) << endl;
                }
            }
            else if(base == "Faro"){
                for(int i = 0; i < Faro.getRestaurants().size(); i++){
                    cout << endl <<  "--> Restaurant " << i+1 << endl;
                    cout << Faro.getRestaurants().at(i) << endl;
                }
            }

            string a;
            cout << endl << endl << "-----------------------------------------------" << endl;
            cout << "Insert 0 to return to Order Management: ";
            getline(cin, a);

            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, a);
            }
            verification_int(a);

            while (stoi(a) != 0) {
                cout << "Invalid input. Please insert 0 to return to Order Management: ";
                getline(cin, a);

                while (cin.fail() && cin.eof()) {
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, a);
                }
                verification_int(a);
            }
        }
    } while(option == 5);


    if(indprod.size() == 0){
        system("cls");
        cout << "Operation was canceled." << endl;
        Sleep(900);
        return 1;
    }
    time_t now = time(0);
    tm* gmtm = gmtime(&now);
    Time order_time((*gmtm).tm_hour,(*gmtm).tm_min,(*gmtm).tm_mday,(*gmtm).tm_mon+1,(*gmtm).tm_year+1900);
    vector<Product> products;
    for (int i: indprod){
        products.push_back(restaurant.getProducts().at(i));
    }
    float tax;
    if (cliente.getCounty() != restaurant.getCounty())
        tax = 5;
    else
        tax = 3;
    string answer;
    Delivery delivery(restaurant, order_time, products, nif, tax);
    int a,c,choice;
    vector<string> reasons = {"It did not arrived.", "It was not what I ordered.", "I was not at home at the time of delivery", "Wrong address", "Other"};
    bool success;
    string s;
    Time delivery_time;
    vector<Employee*> employees;
    if (base == "Porto"){
        employees = Porto.getEmployees();
    }
    else if (base == "Lisboa") {
        employees = Lisboa.getEmployees();
    }
    else if (base == "Faro") {
        employees = Faro.getEmployees();
    }
    Deliverer* low_deliverer = new Deliverer;
    low_deliverer->setBackground({});
    bool low = false;
    for (vector<Employee*>::const_iterator it =  employees.begin(); it != employees.end(); it++){
        Deliverer* nd = dynamic_cast<Deliverer*>(*it);
        if (nd != nullptr){
            if (!low || low_deliverer->getBackground().size() > nd->getBackground().size()) {
                low_deliverer = nd;
                low = true;
            }
        }
    }
    Deliverer deliverer = *low_deliverer;

    system("cls");
    int go = 1;
    cout << "==============================" << endl;
    cout << "Order no " << delivery.getId() << " ordered successfully!" << endl;
    cout << "==============================" << endl;
    cout << "Restaurant: " << delivery.getRestaurant().getName() << endl;
    cout << "Order Time: " << delivery.getTime().getHour() << ":" << delivery.getTime().getMinutes() << endl;
    cout << "Products ordered: " << endl;
    vector<Product> productsl = delivery.getProducts();
    for (size_t i = 0; i < productsl.size(); i++){
        cout << i+1 << ": " << productsl.at(i).getName() << " - " << productsl.at(i).getPrice() << "$" << endl;
    }
    cout << endl << "==============================" << endl;
    cout << "Billing details" << endl;
    cout << "==============================" << endl;
    cout << "Client NIF: " << delivery.getNif() << endl;
    cout << "Delivery Tax: " << delivery.getTax() << "$ - From " << restaurant.getCounty() << " to " << cliente.getCounty() << endl;
    cout << "Total product price: " << delivery.getPrice() << "$" << endl;
    cout << "Total order price: " << delivery.getFinalPrice() << "$" << endl << endl;
    cout << "Deliverer " << deliverer.getName() << " will arrive shortly in a " << deliverer.getVehicle().getBrand() << " " << deliverer.getVehicle().getType() << " with your order" << endl << endl;
    cout << "Press ENTER to proceed to the Delivery Form" << endl;
    cin.ignore();

    system("cls");

    cout << "==================== Delivery Form ====================" << endl;
    cout << endl <<  "Was your delivery successfull? (Choose an integer number)" << endl;
    cout << "1. Yes\t 2. No"<<endl;
    menu_int_options(a,1,2);
    cin.ignore(1000, '\n');

    if(a==1){
        success=true;
        delivery.setSuccess(success);
        delivery.setReason_insuccess("Nothing to show");
    }
    else if(a==2) {
        success = false;
        delivery.setSuccess(success);
        cout << "What's the reason of the insuccess? (Choose an integer option)" << endl;
        for (int i = 0; i < reasons.size(); i++) {
            cout << i + 1 << ". " << reasons[i] << endl;
        }
        menu_int_options(choice, 1, 5);
        cin.ignore(1000,'\n');
        delivery.setReason_insuccess(reasons[choice-1]);
    }

    if(success){
        cout << "At what time did you get your order? (in the format 'dd/mm/yyyy, hh:mm') ";
        getline(cin,s);
        while (cin.fail() && cin.eof()) {
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, s);
        }
        verification_time(s);
        delivery_time = stringToTime(s);
        while(!(delivery_time > order_time)){
            cout << endl << "Invalid input. You ordered your product at " << order_time << ", " << setw(2) << setfill('0') << order_time.getHour() <<  ":" << setw(2) << setfill('0') << order_time.getMinutes() << ". Try again: ";
            getline(cin,s);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
            verification_time(s);
            delivery_time = stringToTime(s);
        }

        delivery.setDeliver_time(delivery_time);
    }

    cout << "Did you pay your delivery? (Choose an integer option)";
    cout<< " 1.Yes \t 2.No"<<endl;
    menu_int_options(c,1,2);
    cin.ignore(1000, '\n');

    if(c==2){
        if(base == "Porto"){
            Porto.addClientToBlacklist(Porto.getClients().at(index));
        }
        else if (base =="Lisboa"){
            Lisboa.addClientToBlacklist(Lisboa.getClients().at(index));
        }
        else if(base == "Faro") {
            Faro.addClientToBlacklist(Faro.getClients().at(index));
        }
    }
    if(a==1){
        system("cls");
        cout << "We have saved your order's data. Hope you're satisfied!"<<endl;
        Sleep(1500);
    }
    else if (a==2){
        system("cls");
        cout << "We have saved your order's data. We apologize for any inconvenience! "<<endl;
        Sleep(1500);
    }

    if (base == "Porto"){
        Porto.addDelivery(delivery);
        Porto.addDeliveryToDeliverer(delivery);
    }
    else if (base == "Lisboa") {
        Lisboa.addDelivery(delivery);
        Lisboa.addDeliveryToDeliverer(delivery);
    }
    else if (base == "Faro") {
        Faro.addDelivery(delivery);
        Faro.addDeliveryToDeliverer(delivery);
    }

    return 1;
}