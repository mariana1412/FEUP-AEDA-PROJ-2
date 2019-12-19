#include "Menus.h"

int Admin_MainMenu(){//admins can't manage employees, only the boss and the managers can do that
    int option;
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "---------------- MENU ----------------" << endl << endl;
    cout << "1. Clients Management" << endl;
    cout << "2. Restaurants Management" << endl;
    cout << "3. Profits Calculation" << endl;
    cout << "4. Visualize Information"<<endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}

int Manager_MainMenu(){
    int option;
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "---------------- MENU ----------------" << endl << endl;
    cout << "1. Clients Management" << endl;
    cout << "2. Employees Management " << endl;
    cout << "3. Restaurants Management" << endl;
    cout << "4. Profits Calculation" << endl;
    cout << "5. Visualize Information"<<endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,5);

    cin.ignore(1000,'\n');
    return option;
}

int Boss_MainMenu(){
    int option;
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "---------------- MENU ----------------" << endl << endl;
    cout << "1. Clients Management" << endl;
    cout << "2. Employees Management " << endl;
    cout << "3. Restaurants Management " << endl;
    cout << "4. Profits Calculation " << endl;
    cout << "5. Visualize Information "<<endl;
    cout << "6. Change Manager " <<endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,6);

    cin.ignore(1000,'\n');
    return option;
}

int Client_MainMenu(){
    int option;
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "---------------- MENU ----------------" << endl << endl;
    cout << "1. Account Management" << endl;
    cout << "2. Order" << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,2);

    cin.ignore(1000,'\n');
    return option;
}

int AccountManagement(){
    int option;
    system("cls");
    cout << "--------------------------------------" << endl;
    cout << "---------------- MENU ----------------" << endl << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Modify Data" << endl;
    cout << "3. Remove Account" << endl;
    cout << "4. Return to the Main Menu" << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}

int ClientsManagement(){
    int option;
    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "---------------- CLIENTS MANAGEMENT ----------------" << endl << endl;
    cout << "1. Create Client " << endl;
    cout << "2. Modify Client" << endl;
    cout << "3. Remove Client " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}

int EmployeesManagement(){
    int option;
    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "---------------- EMPLOYEE MANAGEMENT ----------------" << endl << endl;
    cout << "1. Create Employee " << endl;
    cout << "2. Modify Employee" << endl;
    cout << "3. Remove Employee " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;

    menu_int_options(option,0,4);

    cin.ignore(1000,'\n');
    return option;
}

int RestaurantsManagement(){
    int option;
    system("cls");
    cout << "-------------------------------------------------------" << endl;
    cout << "---------------- RESTAURANT MANAGEMENT ----------------" << endl << endl;
    cout << "1. Create Restaurant " << endl;
    cout << "2. Modify Restaurant" << endl;
    cout << "3. Remove Restaurant " << endl;
    cout << "4. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "--------------------------------------" << endl;
    menu_int_options(option,0,4);
    cin.ignore(1000,'\n');
    return option;
}

int ProfitsCalculation(){
    int option;
    system("cls");
    cout << "-------------------------------------------------------" << endl;
    cout << "---------------- PROFIT CALCULATION BY ----------------" << endl << endl;
    cout << "1. Base " << endl;
    cout << "2. Restaurant" << endl;
    cout << "3. Client " << endl;
    cout << "4. Time Interval " << endl;
    cout << "5. Return to the main menu " << endl;
    cout << "0. Exit" << endl;
    cout << "-------------------------------------------------------" << endl;
    menu_int_options(option,0,5);
    cin.ignore(1000,'\n');
    return option;
}

int VisualizeInformation(){
    int option;
    system("cls");
    cout << "-------------------------------------------------------"<<endl;
    cout << "---------------- VISUALIZE INFORMATION ----------------" << endl<<endl;
    cout << "1. View all clients " << endl;
    cout << "2. View clients in the blacklist" << endl;
    cout << "3. View all employees" << endl;
    cout << "4. View all restaurants " << endl;
    cout << "5. View all deliveries " << endl;
    cout << "6. Return to the main menu"<<endl;
    cout << "0. Exit" << endl;
    cout << "-------------------------------------------------------"<<endl;
    menu_int_options(option,0,6);
    cin.ignore(1000,'\n');
    return option;
}