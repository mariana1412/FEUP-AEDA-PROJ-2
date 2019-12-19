#include "Restaurants_functions.h"

int create_restaurant(Base &Porto, Base &Lisboa, Base &Faro){
    Restaurant new_restaurant;
    string aux;
    string b;
    Base base;
    vector<Restaurant> restaurants;
    bool isValid;

    system("cls");
    cout << endl << "---------------- CREATE RESTAURANT ----------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);

    if (b == "Porto") base = Porto;
    else if (b == "Lisboa") base = Lisboa;
    else if(b == "Faro") base = Faro;

    restaurants = base.getRestaurants();

    cout << endl << "Name: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);

    do{
        try {
            new_restaurant.setName(aux, base.getRestaurants());
            isValid = true;
        }
        catch (RestaurantAlreadyExists &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' already exists." << endl << endl;
            isValid = false;
            cout << "Try again. Name: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_all_letters(aux);
        }
    } while(!isValid);

    int option;

    cout << endl << "County: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    verification_all_letters(aux);

    try {
        new_restaurant.setCounty(aux, b);
    }
    catch (RestaurantOutOfArea &msg){
        system("cls");
        cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
        cout << "1. Return to Main Menu. " << endl;
        cout << "2. Return to Restaurants Management. " << endl;
        menu_int_options(option, 1, 2);
        return option;
    }


    cout << endl << "Address: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    formatting_string(aux);
    new_restaurant.setAddress(aux);

    int n, i = 0;

    cout << endl << "How many products does the restaurant have? Please insert an integer number: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof() && n == 0){
        cin.clear();
        cout << "Invalid number. Please insert a valid input: ";
        cin >> n;
    }

    verification_int(aux);
    n = stoi(aux);

    Product product;
    while (n != i){
        cout << i + 1 <<  ". Product name: ";
        getline(cin, aux);

        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_all_letters(aux);
        product.setName(aux);

        cout << endl  << "Type of food: ";
        getline(cin, aux);
        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_all_letters(aux);
        product.setType_of_food(aux);
        new_restaurant.addType_of_food(aux);

        cout << endl << "Price: ";
        getline(cin, aux);
        while (cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_float(aux);
        product.setPrice(stof(aux));

        try{
            new_restaurant.addProduct(product);
        }
        catch (ProductAlreadyExists &msg){
            cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
            cout << "Try again! " << endl;
            i--;
        }

        i++;
    }

    new_restaurant.setRevenue(0.0);

    system("cls");

    cout << endl << "---------------- CREATE RESTAURANT ----------------" << endl << endl;

    cout  << new_restaurant << endl;

    cout << endl << endl << "---------------------------------------------------" <<  endl;


    if(confirm_modifications("create", "restaurant")){
        if (b == "Porto") Porto.addRestaurant(new_restaurant);
        else if (b == "Lisboa") Lisboa.addRestaurant(new_restaurant);
        else if(b == "Faro") Faro.addRestaurant(new_restaurant);

        system("cls");
        cout << endl << endl << "Restaurant was successfully created!" << endl << endl;
    }

    else {
        system("cls");
        cout << endl << endl << "Operation was canceled!" << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Restaurants Management. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int modify_restaurant(Base &Porto, Base &Lisboa, Base &Faro) {

    string base, aux;
    bool isValid;
    int res;
    Restaurant restaurant;

    system("cls");
    cout << endl << "---------------- MODIFY RESTAURANT ----------------" << endl << endl;


    cout << "Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);

    cout << "Insert the name of the restaurant you want to modify: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    formatting_string(aux);

    do{
        try {
            if (base == "Porto") restaurant = Porto.searchRestaurant(aux);
            else if (base == "Lisboa") restaurant = Lisboa.searchRestaurant(aux);
            else if(base == "Faro") restaurant = Faro.searchRestaurant(aux);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant you want to modify: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            formatting_string(aux);
        }
    } while(!isValid);


    if (base == "Porto") res = Porto.getIndexrestaurant(restaurant);
    else if (base == "Lisboa") res = Lisboa.getIndexrestaurant(restaurant);
    else if(base == "Faro") res = Faro.getIndexrestaurant(restaurant);

    system("cls");
    cout << endl << "---------------- MODIFY RESTAURANT ----------------" << endl << endl;
    cout  << restaurant << endl;
    cout << endl << endl << "---------------------------------------------------" <<  endl;

    int choice = 0;
    int option = 0;

    cout << endl << endl << "What do you want to change? "<< endl;
    cout << "1. Address" << endl;
    cout << "2. Products" << endl;
    cout << "3. Everything" << endl;
    menu_int_options(option, 1, 3);
    cin.ignore(1000, '\n');
    string change;
    Product product;
    int c = 0, prod;

    system("cls");
    cout << endl << "---------------- MODIFY RESTAURANT ----------------" << endl << endl;
    cout  << restaurant << endl;
    cout << endl << endl << "---------------------------------------------------" <<  endl;

    switch(option){
        case 1:
            cout << "The current county is " << restaurant.getCounty() << ". Do you want to change it? ";
            cout << "Insert 'yes' to change it. " << endl << "Insert 'no' to continue. " << endl << "Answer: ";
            getline(cin, change);
            isValid = false;

            while (!isValid || change == "") {
                if (change != "") {
                    formatting_string(change);
                    isValid = ((change == "Yes") || (change == "No"));
                }
                if (!isValid) {
                    cout << "Invalid operation. Please insert a valid one: ";
                    getline(cin, change);
                    if (cin.fail() && cin.eof()) {
                        cin.clear();
                        continue;
                    }
                }
            }

            if(change == "Yes"){
                cout << endl << endl << "County: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }

                verification_all_letters(aux);

                try {
                    restaurant.setCounty(aux, base);
                }
                catch (RestaurantOutOfArea &msg){
                    system("cls");
                    cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }

            }

            cout << endl << "Address: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }

            formatting_string(aux);
            restaurant.setAddress(aux);

            break;
        case 2:
            cout << "Do you want to: "<< endl;
            cout << "1. Add a new product" << endl;
            cout << "2. Modify a product" << endl;
            cout << "3. Remove a product" << endl;

            menu_int_options(choice, 1, 3);
            cin.ignore(1000, '\n');

            if(choice == 1){
                do{
                    system("cls");
                    cout << endl << "---------------- CREATE PRODUCT ----------------" << endl << endl;

                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);

                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                    restaurant.addType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));

                    try{
                        restaurant.addProduct(product);
                        isValid = true;
                    }
                    catch (ProductAlreadyExists &msg){
                        isValid = false;
                        cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
                        cout << "Try again! " << endl;
                    }
                } while( !isValid);
            }

            else if(choice == 2){

                cout << "Insert the name of the product you want to modify: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                prod = restaurant.getIndexProduct(product);

                system("cls");
                cout << endl << "---------------- MODIFY PRODUCT ----------------" << endl << endl;
                cout << "Name: " << product.getName() << endl;
                cout << "Type of food: " << product.getType_of_food() << endl;
                cout << "Price: " << product.getPrice() << " euros" << endl;
                cout << endl << "---------------------------------------------------" << endl;

                cout << endl << endl << endl << "What do you want to modify: "<< endl;
                cout << "1. Name" << endl;
                cout << "2. Type of food" << endl;
                cout << "3. Price" << endl;
                cout << "4. Everything" << endl;
                menu_int_options(c, 1, 4);
                cin.ignore(1000, '\n');

                if(c == 1){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);
                }

                else if (c == 2){
                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                }

                else if( c == 3){
                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));
                }

                else if (c == 4){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);


                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));
                }

                if(confirm_modifications("modify", "product")){
                    if(c == 2 || c == 4) restaurant.updateTypes_of_food();
                    restaurant.changeProduct(product, prod);

                    system("cls");
                    cout << endl << "Product was successfully modified!" << endl << endl;

                }
                else {
                    system("cls");
                    cout << endl << "Operation was canceled!" << endl << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
            }

            else if(choice == 3){
                cout << "Insert the name of the product you want to remove: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                system("cls");
                cout << endl << "---------------- REMOVE PRODUCT ----------------" << endl << endl;
                cout << "Name: " << product.getName() << endl;
                cout << "Type of food: " << product.getType_of_food() << endl;
                cout << "Price: " << product.getPrice() << " euros" << endl;
                cout << endl << "---------------------------------------------------" << endl;

                prod = restaurant.getIndexProduct(product);

                if (confirm_modifications("remove", "product")){
                    restaurant.removeProduct(prod);
                    system("cls");
                    cout << endl << "Product was successfully removed!" << endl << endl;

                }
                else {
                    system("cls");
                    cout << endl << "Operation was canceled!" << endl << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
            }
            break;
        case 3:

            cout << "The current county is " << restaurant.getCounty() << ". Do you want to change it? ";
            cout << "Insert 'yes' to change it. " << endl << "Insert 'no' to continue. " << endl << "Answer: ";
            getline(cin, change);
            isValid = false;

            while (!isValid || change == "") {
                if (change != "") {
                    formatting_string(change);
                    isValid = ((change == "Yes") || (change == "No"));
                }
                if (!isValid) {
                    cout << "Invalid operation. Please insert a valid one: ";
                    getline(cin, change);
                    if (cin.fail() && cin.eof()) {
                        cin.clear();
                        continue;
                    }
                }
            }

            if(change == "Yes"){
                cout << endl << endl << "County: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }

                verification_all_letters(aux);

                try {
                    restaurant.setCounty(aux, base);
                }
                catch (RestaurantOutOfArea &msg){
                    system("cls");
                    cout << endl << endl << "ATENTION: " << msg.getCounty() << " does not belong to the base area." << endl << endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }

            }

            cout << endl << "Address: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }

            formatting_string(aux);
            restaurant.setAddress(aux);

            cout << "Do you want to: "<< endl;
            cout << "1. Add a new product" << endl;
            cout << "2. Modify a product" << endl;
            cout << "3. Remove a product" << endl;

            menu_int_options(choice, 1, 3);
            cin.ignore(1000, '\n');

            if(choice == 1){
                do{
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);

                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                    restaurant.addType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));

                    try{
                        restaurant.addProduct(product);
                        isValid = true;
                    }
                    catch (ProductAlreadyExists &msg){
                        isValid = false;
                        cout << endl << endl << "ATENTION: " << msg.getName() << " already exists." << endl;
                        cout << "Try again! " << endl;
                    }
                } while( !isValid);
            }

            else if(choice == 2){
                cout << "Insert the name of the product you want to modify: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                prod = restaurant.getIndexProduct(product);

                cout << endl << endl << endl << "What do you want to modify: "<< endl;
                cout << "1. Name" << endl;
                cout << "2. Type of food" << endl;
                cout << "3. Price" << endl;
                cout << "4. Everything" << endl;
                menu_int_options(c, 1, 4);
                cin.ignore(1000, '\n');

                if(c == 1){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);
                }

                else if (c == 2){
                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);
                }

                else if( c == 3){
                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));
                }

                else if (c == 4){
                    cout << endl << "Product name: ";
                    getline(cin, aux);

                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setName(aux);


                    cout << endl  << "Type of food: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_all_letters(aux);
                    product.setType_of_food(aux);

                    cout << endl << "Price: ";
                    getline(cin, aux);
                    while (cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, aux);
                    }
                    verification_float(aux);
                    product.setPrice(stof(aux));
                }

                if(confirm_modifications("modify", "product")){
                    if(c == 2 || c == 4) restaurant.updateTypes_of_food();
                    restaurant.changeProduct(product, prod);
                    cout << endl << "Product was successfully modified!" << endl << endl;
                }
                else {
                    system("cls");
                    cout << endl <<  "Operation was canceled!" << endl << endl;
                    cout << endl << endl << "---------------------------------------------------" <<  endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
            }

            else if(choice == 3){
                cout << "Insert the name of the product you want to remove: ";
                getline(cin, aux);

                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                formatting_string(aux);

                do{
                    try {
                        product = restaurant.searchProduct(aux);
                        isValid = true;
                    }
                    catch (ProductNotFound &msg){
                        cout << endl << endl << "ATENTION: Product '" << msg.getName() << "' does not exist." << endl << endl;
                        isValid = false;
                        cout << "Try again. Insert the name of the product you want to modify: ";
                        getline(cin, aux);

                        while(cin.fail() && cin.eof()){
                            cin.clear();
                            cout << "Invalid character. Please insert a valid input: ";
                            getline(cin, aux);
                        }
                        formatting_string(aux);
                    }
                } while(!isValid);

                prod = restaurant.getIndexProduct(product);

                if (confirm_modifications("remove", "product")){
                    restaurant.removeProduct(prod);
                    cout << endl << "Product was successfully removed!" << endl << endl;

                }
                else {
                    system("cls");
                    cout << endl << "Operation was canceled!" << endl << endl;
                    cout << endl << endl << "---------------------------------------------------" <<  endl;
                    cout << "1. Return to Main Menu. " << endl;
                    cout << "2. Return to Restaurants Management. " << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
            }
            break;
    }

    system("cls");
    cout << endl << "---------------- MODIFY RESTAURANT ----------------" << endl << endl;
    cout  << restaurant << endl;
    cout << endl << endl << "---------------------------------------------------" <<  endl;

    if(confirm_modifications("modify", "restaurant")){
        if (base == "Porto") Porto.changeRestaurant(restaurant, res);
        else if (base == "Lisboa") Lisboa.changeRestaurant(restaurant, res);
        else if(base == "Faro") Faro.changeRestaurant(restaurant, res);
        system("cls");
        cout << endl << "Restaurant was successfully modified!" << endl << endl;
    }

    else {
        system("cls");
        cout << endl << "Operation was canceled!" << endl << endl;
    }


    cout << endl << endl << "---------------------------------------------------" <<  endl;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Restaurants Management. " << endl;
    menu_int_options(option, 1, 2);
    return option;

}

int remove_restaurant(Base &Porto, Base &Lisboa, Base &Faro){

    string aux, base;
    vector<Restaurant> restaurants;
    bool isValid, confirm;
    int option;

    system("cls");
    cout << endl << "---------------- REMOVE RESTAURANT ----------------" << endl << endl;


    cout << "Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, base);
    }

    verification_base(base);


    cout << endl << endl << "Insert the name of the restaurant you want to remove: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    formatting_string(aux);

    try {
        if (base == "Porto") confirm = Porto.removeRestaurant(aux);
        else if (base == "Lisboa") confirm  = Lisboa.removeRestaurant(aux);
        else if(base == "Faro") confirm = Faro.removeRestaurant(aux);
    }
    catch (RestaurantNotFound &msg){
        cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
        cout << "1. Return to Main Menu. " << endl;
        cout << "2. Return to Restaurants Management. " << endl;
        menu_int_options(option, 1, 2);
        return option;
    }

    system("cls");
    if (confirm) cout << endl << endl << "Restaurant was successfully removed!" << endl << endl;
    else cout << endl << endl << "Operation was canceled!" << endl << endl;

    cout << endl << endl << "---------------------------------------------------" << endl;
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Restaurants Management. " << endl;
    menu_int_options(option, 1, 2);
    return option;

}