#include <iostream>
#include <Windows.h>
#include "Functions/ReadingFiles.h"
#include "Functions/WriteToFile.h"
#include "Functions/Verification_Inputs.h"
#include "Functions/Menus.h"
#include "Functions/Clients_functions.h"
#include "Functions/Employees_functions.h"
#include "Functions/Restaurants_functions.h"
#include "Functions/Order_functions.h"
#include "Functions/ProfitsCalculation.h"
#include "Functions/Visualize_Information.h"
#include "Classes/Company.h"

const vector<string> nearby_Porto = { "Matosinhos", "Vila Nova De Gaia", "Maia", "Gondomar", "Porto" };
const vector<string> nearby_Lisboa = { "Oeiras", "Loures", "Amadora", "Odivelas","Lisboa" };
const vector<string> nearby_Faro = { "Loule","Olhao", "Sao Bras De Alportel","Faro" };

using namespace std;

int main() {

    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);
    Base Porto, Lisboa, Faro;
    bool is_client=false;
    string boss_name;
    int op, boss_nif, user;
    string verification;

    system("cls");

    cout << endl << endl << "Welcome to Ugh Eats! We are going to tranform your lunch/dinner in a unforgetable gastronomical experience!\n"<< endl << endl;
    extract_Clients(Porto, Lisboa, Faro);
    extract_Restaurants(Porto, Lisboa, Faro);
    extract_Deliveries(Porto, Lisboa, Faro);
    extract_Employees(Porto, Lisboa, Faro);
    extract_Bases(Porto, Lisboa, Faro, boss_name, boss_nif);
    Company comp(boss_name, boss_nif, Porto, Lisboa, Faro);

    cout << "What are you?\n";
    cout << "1. Boss \n";
    cout << "2. Manager \n";
    cout << "3. Administrator\n";
    cout << "4. Client\n";
    menu_int_options(user, 1, 4);
    cin.ignore(1000, '\n');
    if (user != 4) {
        cout << "Please enter your NIF (insert 0 to exit the program): ";
        while (true) {
            getline(cin, verification);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, verification);
            }
            verification_int(verification);
            if (stoi(verification) == 0) {
                return 0;
                break;
            }
            verification_nif(verification);
            if (user == 1) {
                if (comp.getBossNif() == stoi(verification)) {
                    cout << endl << endl << "Logged in as Boss!" << endl;
                    Sleep(900);
                    break;
                }
            }
            else if (user == 2) {
                if (Porto.getManagerNif() == stoi(verification) || Lisboa.getManagerNif() == stoi(verification) ||
                    Faro.getManagerNif() == stoi(verification)) {
                    cout << endl << endl << "Logged in as Manager! " << endl;
                    Sleep(900);
                    break;
                }
            }
            else if (user == 3) {
                if (stringToAdminSearch(verification, Porto) || stringToAdminSearch(verification, Lisboa) ||
                    stringToAdminSearch(verification, Faro)) {
                    cout << endl << endl << "Logged in as an admin! " << endl;
                    Sleep(900);
                    break;
                }
            }
            cout << "That NIF that's not correspond to that kind of user! Please enter the corresponding NIF or enter 0 to login as a client: ";
        }
    }
    if(user ==4){
        is_client = true;
        system("cls");
    }

    int menu;
    if (user == 1) {
        do {
            menu = Boss_MainMenu();
            if (menu == 1) {
                int choice, aux;
                do {
                    choice = ClientsManagement();
                    if (choice == 1) {
                        aux = create_client(Porto, Lisboa, Faro, is_client);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }

                    }
                    else if (choice == 2) {
                        aux = modify_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 3) {
                        aux = remove_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }

                } while (choice != 4);

            }
            else if (menu == 2) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = EmployeesManagement();
                        if (choice == 1) {
                            aux = create_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 2) {
                            aux = modify_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 3) {
                            aux = remove_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 4);
            }
            else if (menu == 3) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = RestaurantsManagement();
                        if (choice == 1) {
                            aux = create_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 2) {
                            aux = modify_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }

                        }
                        else if (choice == 3) {
                            aux = remove_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }

                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 4);
            }
            else if (menu == 4) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = ProfitsCalculation();
                        if (choice == 1) {
                            aux = ProfitsByBase(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }

                        }
                        else if (choice == 2) {
                            aux = ProfitsByRestaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 3) {
                            aux = ProfitsByClient(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 4) {
                            aux = ProfitByTimeInterval(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 5);
            }
            else if (menu == 5) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = VisualizeInformation();
                        if (choice == 1) {
                            aux = visualize_clients(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }

                        }
                        else if (choice == 2) {
                            aux = visualize_blacklist(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 3) {
                            aux = visualize_employees(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 4) {
                            aux = visualize_restaurants(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 5) {
                            aux = visualize_deliveries(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 6);
            }
            else if (menu == 6) {
                changeManager(Porto, Lisboa, Faro);
            }

        } while (menu != 0);

    }
    else if (user == 2) {
        do {
            menu = Manager_MainMenu();
            if (menu == 1) {
                int choice, aux;
                do {
                    choice = ClientsManagement();
                    if (choice == 1) {
                        aux = create_client(Porto, Lisboa, Faro,is_client);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }

                    }
                    else if (choice == 2) {
                        aux = modify_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 3) {
                        aux = remove_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }

                } while (choice != 4);
            }
            else if (menu == 2) {
                int choice, aux;
                do {
                        choice = EmployeesManagement();
                        if (choice == 1) {
                            aux = create_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 2) {
                            aux = modify_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 3) {
                            aux = remove_employee(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                } while (choice != 4);
            }
            else if (menu == 3) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = RestaurantsManagement();
                        if (choice == 1) {
                            aux = create_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 2) {
                            aux = modify_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 3) {
                            aux = remove_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 4);
            }
            else if (menu == 4) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = ProfitsCalculation();
                        if (choice == 1) {
                            aux = ProfitsByBase(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 2) {
                            aux = ProfitsByRestaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 3) {
                            aux = ProfitsByClient(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 4) {
                            aux = ProfitByTimeInterval(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }

                    }
                } while (choice != 5);
            }
            else if (menu == 5) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = VisualizeInformation();
                        if (choice == 1) {
                            aux = visualize_clients(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }

                        }
                        else if (choice == 2) {
                            aux = visualize_blacklist(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 3) {
                            aux = visualize_employees(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 4) {
                            aux = visualize_restaurants(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 5) {
                            aux = visualize_deliveries(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 5;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }

                    }
                } while (choice != 6);
            }
        } while (menu != 0);
    }
    else if (user == 3) {
        do {
            menu = Admin_MainMenu();
            if (menu == 1) {
                int choice, aux;
                do {
                    choice = ClientsManagement();
                    if (choice == 1) {
                        aux = create_client(Porto, Lisboa, Faro,is_client);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }

                    }
                    else if (choice == 2) {
                        aux = modify_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 3) {
                        aux = remove_client(Porto, Lisboa, Faro);
                        if (aux == 1) {
                            break;
                        }
                        else if (aux == 2) {
                            menu = 1;
                        }
                    }
                    else if (choice == 0) {
                        menu = 0;
                        break;
                    }

                } while (choice != 4);
            }
            else if (menu == 2) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = RestaurantsManagement();
                        if (choice == 1) {
                            aux = create_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 2) {
                            aux = modify_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 3) {
                            aux = remove_restaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 2;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 4);
            }
            else if (menu == 3) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = ProfitsCalculation();
                        if (choice == 1) {
                            aux = ProfitsByBase(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 2) {
                            aux = ProfitsByRestaurant(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 3) {
                            aux = ProfitsByClient(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 4) {
                            aux = ProfitByTimeInterval(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 3;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }
                    }
                } while (choice != 5);
            }
            else if (menu == 4) {
                int choice, aux;
                do {
                    if (is_client) {
                        cout << endl << "ATENTION: You do not have access to this functionality.\n" << endl;
                        choice = 0;
                        break;
                    }
                    else {
                        choice = VisualizeInformation();
                        if (choice == 1) {
                            aux = visualize_clients(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 2) {
                            aux = visualize_blacklist(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 3) {
                            aux = visualize_employees(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 4) {
                            aux = visualize_restaurants(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 5) {
                            aux = visualize_deliveries(Porto, Lisboa, Faro);
                            if (aux == 1) {
                                break;
                            }
                            else if (aux == 2) {
                                menu = 4;
                            }
                        }
                        else if (choice == 0) {
                            menu = 0;
                            break;
                        }

                    }
                } while (choice != 6);
            }
        } while (menu != 0);
    }
    else if (user == 4){
        int choice, aux;
        do{
            menu=Client_MainMenu();
            if(menu == 1){
                do{
                    choice = AccountManagement();
                    if(choice == 1){
                        aux= create_client(Porto, Lisboa, Faro,is_client);
                        if(aux==1){
                            break;
                        }
                        else if(aux ==2){
                            menu =1;
                        }
                    }
                    else if(choice == 2){
                        aux = modifyData(Porto, Lisboa, Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu =1;
                        }
                    }
                    else if(choice ==3){
                        aux = removeAccount(Porto, Lisboa,Faro);
                        if(aux==1){
                            break;
                        }
                        else if(aux==2){
                            menu = 1;
                        }
                    }
                    else if(choice == 0){
                        menu = 0;
                        break;
                    }
                }while(choice != 4);

            }
            else if(menu == 2){
                aux=create_order(Porto, Lisboa, Faro);
                if (aux == 1) {
                    continue;
                }
                else if(aux==0){
                    menu = 0;
                    break;
                }
            }
        }while(menu !=0);
    }
    cout << endl;
    system("cls");
    cout << endl << "Thank you! We hope you've enjoyed your experience with Ugh Eats!" << endl;
    Porto.updateBases();
    Lisboa.updateBases();
    Faro.updateBases();
    write_Clients(Porto, Lisboa, Faro);
    write_Restaurants(Porto, Lisboa, Faro);
    write_Deliveries(Porto, Lisboa, Faro);
    write_Employees(Porto, Lisboa, Faro);
    write_Bases(boss_name,boss_nif,Porto, Lisboa, Faro);
    Sleep(10000);
    return 0;
}


