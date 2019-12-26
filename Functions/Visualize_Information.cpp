#include "Visualize_Information.h"

int visualize_clients(const Base &Porto, const Base &Lisboa, const Base &Faro){

    string b;
    int size;

    system("cls");
    cout << endl << "---------------- VISUALIZE CLIENTS ---------------- "<< endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE CLIENTS ---------------- "<< endl << endl;
        cout << "Base: Porto" << endl << endl;
        size = Porto.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Porto.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE CLIENTS ---------------- "<< endl << endl;
        cout << "Base: Lisboa" << endl << endl;
        size = Lisboa.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 << endl;
                cout << Lisboa.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE CLIENTS ---------------- "<< endl << endl;
        cout << "Base: Faro" << endl << endl;
        size = Faro.getClients().size();
        if(size != 0){
            for(int i =0; i < size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Faro.getClients()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }


    int option;
    cout << endl << endl << "--------------------------------------------------- "<< endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_blacklist(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    int size;
    system("cls");
    cout << endl << "---------------- VISUALIZE BLACKLIST ---------------- "<< endl << endl;


    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE BLACKLIST ---------------- "<< endl << endl;
        cout << "Base: Porto" << endl << endl;
        size = Porto.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Porto.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE BLACKLIST ---------------- "<< endl << endl;
        cout << "Base: Lisboa" << endl << endl;
        size = Lisboa.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Lisboa.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE BLACKLIST ---------------- "<< endl << endl;
        cout << "Base: Faro" << endl << endl;
        size = Faro.getBlackList().size();
        if(size!=0){
            for(int i =0; i<size; i++){
                cout << "--> Client " << i+1 <<endl;
                cout << Faro.getBlackList()[i] << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << endl << "--------------------------------------------------- "<< endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_employees(Base Porto, Base Lisboa, Base Faro){
    string b;
    int size;
    int number;

    system("cls");

    cout << endl << "---------------- VISUALIZE EMPLOYEES ---------------- "<< endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);


    if (b == "Porto"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE EMPLOYEES ---------------- "<< endl << endl;
        size = Porto.getEmployeesHash().size();
        if(size != 0){
            cout << "Do you wish to visualize: " << endl;
            cout << "1. All Employees" << endl;
            cout << "2. Former Employees" << endl;
            cout << "3. Current Employees" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 3);
            cin.ignore(1000, '\n');

            if(number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE ALL EMPLOYEES ---------------- "<< endl << endl;
                cout << "Base: Porto" << endl << endl;
                Porto.printEmployees(true, true, true, true);
            }
            else if (number == 2){
                system("cls");
                cout << endl << "---------------- VISUALIZE FORMER EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Former Employees" << endl;
                cout << "2. Former Administrators" << endl;
                cout << "3. Former Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL FORMER EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(true, false, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(true, false, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(true, false, false, true);
                }

            }
            else if (number == 3){
                system("cls");
                cout << endl << "---------------- VISUALIZE CURRENT EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Current Employees" << endl;
                cout << "2. Current Administrators" << endl;
                cout << "3. Current Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL CURRENT EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(false, true, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(false, true, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Porto" << endl << endl;
                    Porto.printEmployees(false, true, false, true);
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }

    else if (b == "Lisboa"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE EMPLOYEES ---------------- "<< endl << endl;
        size = Lisboa.getEmployeesHash().size();
        if(size != 0){
            cout << "Do you wish to visualize: " << endl;
            cout << "1. All Employees" << endl;
            cout << "2. Former Employees" << endl;
            cout << "3. Current Employees" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 3);
            cin.ignore(1000, '\n');

            if(number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE ALL EMPLOYEES ---------------- "<< endl << endl;
                cout << "Base: Lisboa" << endl << endl;
                Lisboa.printEmployees(true, true, true, true);
            }
            else if (number == 2){
                system("cls");
                cout << endl << "---------------- VISUALIZE FORMER EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Former Employees" << endl;
                cout << "2. Former Administrators" << endl;
                cout << "3. Former Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL FORMER EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(true, false, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(true, false, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(true, false, false, true);
                }

            }
            else if (number == 3){
                system("cls");
                cout << endl << "---------------- VISUALIZE CURRENT EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Current Employees" << endl;
                cout << "2. Current Administrators" << endl;
                cout << "3. Current Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL CURRENT EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(false, true, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(false, true, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Lisboa" << endl << endl;
                    Lisboa.printEmployees(false, true, false, true);
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    else if (b == "Faro"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE EMPLOYEES ---------------- "<< endl << endl;
        size = Faro.getEmployeesHash().size();
        if(size != 0){
            cout << "Do you wish to visualize: " << endl;
            cout << "1. All Employees" << endl;
            cout << "2. Former Employees" << endl;
            cout << "3. Current Employees" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 3);
            cin.ignore(1000, '\n');

            if(number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE ALL EMPLOYEES ---------------- "<< endl << endl;
                cout << "Base: Faro" << endl << endl;
                Faro.printEmployees(true, true, true, true);
            }
            else if (number == 2){
                system("cls");
                cout << endl << "---------------- VISUALIZE FORMER EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Former Employees" << endl;
                cout << "2. Former Administrators" << endl;
                cout << "3. Former Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL FORMER EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(true, false, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(true, false, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE FORMER DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(true, false, false, true);
                }

            }
            else if (number == 3){
                system("cls");
                cout << endl << "---------------- VISUALIZE CURRENT EMPLOYEES ---------------- "<< endl << endl;
                cout << "Do you wish to visualize: " << endl;
                cout << "1. All Current Employees" << endl;
                cout << "2. Current Administrators" << endl;
                cout << "3. Current Deliverers" << endl;
                cout << "0. Return to Main Menu" << endl;
                menu_int_options(number, 0, 3);

                if(number == 0) return 1;

                if (number == 1){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE ALL CURRENT EMPLOYEES ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(false, true, true, true);
                }
                else if(number == 2){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT ADMINISTRATORS ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(false, true, true, false);
                }
                else if(number == 3){
                    system("cls");
                    cout << endl << "---------------- VISUALIZE CURRENT DELIVERERS ---------------- "<< endl << endl;
                    cout << "Base: Faro" << endl << endl;
                    Faro.printEmployees(false, true, false, true);
                }
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }


    int option;
    cout << endl << endl << "----------------------------------------------------- " << endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_restaurants(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;

    system("cls");
    cout << endl << "---------------- VISUALIZE RESTAURANTS ---------------- "<< endl << endl;

    int size;
    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }
    verification_base(b);

    if (b == "Porto"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE RESTAURANTS ---------------- "<< endl << endl;
        cout << "Base: Porto" << endl << endl;
        size = Porto.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Porto.getRestaurants()[i] << endl << endl;
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }

    }
    else if (b == "Lisboa"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE RESTAURANTS ---------------- "<< endl << endl;
        cout << "Base: Lisboa" << endl << endl;
        size = Lisboa.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Lisboa.getRestaurants()[i] << endl << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE RESTAURANTS ---------------- "<< endl << endl;
        cout << "Base: Faro" << endl << endl;
        size = Faro.getRestaurants().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << "--> Restaurant " << i+1 << endl;
                cout << Faro.getRestaurants()[i] << endl << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << endl << "------------------------------------------------------- "<< endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}

int visualize_deliveries(const Base &Porto, const Base &Lisboa, const Base &Faro){
    string b;
    int size;

    system ("cls");
    cout << endl << "---------------- VISUALIZE DELIVERIES ---------------- "<< endl << endl;


    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);
    if (b == "Porto"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE DELIVERIES ---------------- "<< endl << endl;
        cout << "Base: Porto" << endl << endl;
        size = Porto.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << Porto.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    else if (b == "Lisboa"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE DELIVERIES ---------------- "<< endl << endl;
        cout << "Base: Lisboa" << endl << endl;
        size = Lisboa.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << Lisboa.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }
    if (b == "Faro"){
        system ("cls");
        cout << endl << "---------------- VISUALIZE DELIVERIES ---------------- "<< endl << endl;
        cout << "Base: Faro" << endl << endl;
        size = Faro.getDeliveries().size();
        if(size != 0){
            for(int i =0; i< size; i++){
                cout << Faro.getDeliveries()[i] << endl;
            }
        }
        else {
            cout << endl << "We do not have informations to show! " << endl;
        }
    }

    int option;

    cout << endl << endl << "------------------------------------------------------ "<< endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}
bool SortById ( Tec tec1, Tec tec2){
    return tec1.getId()<tec2.getId();
}

int visualize_tecs(Base Porto,Base Lisboa,Base Faro){
    string b;
    int size;
    int number;

    system("cls");

    cout << endl << "---------------- VISUALIZE TECS ---------------- "<< endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }

    verification_base(b);


    if (b == "Porto") {
        system("cls");
        cout << endl << "---------------- VISUALIZE TECS ---------------- " << endl << endl;
        size = Porto.getTecs().size();
        if (size != 0) {
            cout << "Do you wish to visualize the tecs: " << endl;
            cout << "1. Ordered by ID" << endl;
            cout << "2. Ordered by next available" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 2);
            cin.ignore(1000, '\n');

            if (number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY ID ---------------- " << endl << endl;
                vector<Tec> aux = Porto.getTecs();
                sort(aux.begin(), aux.end(), SortById);
                Porto.printTecs(aux);
            } else if (number == 2) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY AVAILABILITY ---------------- " << endl
                     << endl;
                vector<Tec> aux = Porto.getTecs();
                sort(aux.begin(), aux.end());
                Porto.printTecs(aux);
            }
        } else {
            cout << "We do not have informations to show! " << endl;
        }
    }


    else if (b == "Lisboa"){
        system("cls");
        cout << endl << "---------------- VISUALIZE TECS ---------------- " << endl << endl;
        size = Lisboa.getTecs().size();
        if (size != 0) {
            cout << "Do you wish to visualize the tecs: " << endl;
            cout << "1. Ordered by ID" << endl;
            cout << "2. Ordered by next available" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 2);
            cin.ignore(1000, '\n');

            if (number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY ID ---------------- " << endl << endl;
                vector<Tec> aux = Lisboa.getTecs();
                sort(aux.begin(), aux.end(), SortById);
                Porto.printTecs(aux);
            } else if (number == 2) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY AVAILABILITY ---------------- " << endl
                     << endl;
                vector<Tec> aux = Lisboa.getTecs();
                sort(aux.begin(), aux.end());
                Lisboa.printTecs(aux);
            }
        }
        else {
            cout << "We do not have informations to show! " << endl;
        }
    }
    else if (b == "Faro"){
        system("cls");
        cout << endl << "---------------- VISUALIZE TECS ---------------- " << endl << endl;
        size = Faro.getTecs().size();
        if (size != 0) {
            cout << "Do you wish to visualize the tecs: " << endl;
            cout << "1. Ordered by ID" << endl;
            cout << "2. Ordered by next available" << endl;
            cout << "0. Return to Main Menu" << endl;
            menu_int_options(number, 0, 2);
            cin.ignore(1000, '\n');

            if (number == 0) return 1;


            if (number == 1) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY ID ---------------- " << endl << endl;
                vector<Tec> aux = Faro.getTecs();
                sort(aux.begin(), aux.end(), SortById);
                Faro.printTecs(aux);
            } else if (number == 2) {
                system("cls");
                cout << endl << "---------------- VISUALIZE TECS ORDERED BY AVAILABILITY ---------------- " << endl
                     << endl;
                vector<Tec> aux = Faro.getTecs();
                sort(aux.begin(), aux.end());
                Faro.printTecs(aux);
            }
        } else {
            cout << "We do not have informations to show! " << endl;
        }
    }

    int option;
    cout << endl << endl << "----------------------------------------------------- " << endl;
    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Visualize Information. " << endl;
    menu_int_options(option, 1, 2);
    return option;
}