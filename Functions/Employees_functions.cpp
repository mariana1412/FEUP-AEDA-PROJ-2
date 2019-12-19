#include "Employees_functions.h"

int create_employee(Base &Porto, Base &Lisboa, Base &Faro){

    string name, b, nif, birthdate, task, brand, type, date;
    int number,option;
    vector<Delivery> background;
    string income;
    Admin a;
    bool is_Valid=false;
    Admin* f;
    Deliverer* g;

    system("cls");
    cout << endl << "---------------- CREATE EMPLOYEE ----------------" << endl << endl;

    cout << "What kind of Employee do you wish to create?\n";
    cout << "1. Admin\n" << "2. Deliverer\n";
    menu_int_options(number,1, 2);
    cin.ignore(1000, '\n');

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, b);
    }
    verification_base(b);

    cout << "Name: ";
    getline(cin, name);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, name);
    }
    verification_all_letters(name);

    cout << "NIF: ";
    getline(cin, nif);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, nif);
    }
    verification_nif(nif);

    //check if already exists
    do{
        try{
            employee_already_exists(nif, Porto, Lisboa, Faro);
            is_Valid = true;
        }
        catch(EmployeeAlreadyExists &msg){
            cout <<endl<< "ATENTION: Employee with NIF "<< msg.getNIF()<<" already exists."<<endl;
            is_Valid = false;
            cout << "Try again!"<<endl;
            cout << "NIF:";
            getline(cin, nif);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, nif);
            }
            verification_nif(nif);
        }

    } while(!is_Valid);


    cout << "Birthdate: ";
    getline(cin, birthdate);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, birthdate);
    }
    Time b_date = verification_date(birthdate);


    switch (number) {
        case 1:
            cout << "Task: ";
            getline(cin, task);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, task);
            }
            verification_all_letters(task);

            cout << "Income: ";
            getline(cin, income);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, income);
            }
            verification_float(income);


            f = new Admin(b, name, stoi(nif), b_date, stof(income), task);

            system("cls");
            cout << f;
            cout << endl << "-----------------------------------------------" << endl;
            if (confirm_modifications("create", "admin")) {
                if (b == "Porto") Porto.addEmployee(f);
                else if (b == "Lisboa") Lisboa.addEmployee(f);
                else if (b == "Faro") Faro.addEmployee(f);
                system("cls");
                cout << endl << "Admin was successfully created!" << endl << endl;

            }
            else {    //caso de nao se confirmar a criaçao
                system("cls");
                cout << endl << "Operation was canceled!" << endl << endl;
                //voltar para o menu
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Employees Management." << endl;
                menu_int_options(option, 1, 2);
                return option;
            }
            break;
        case 2:
            cout << "Information of the vehicle alocated to this deliverer:\n";
            cout << "Brand: ";
            getline(cin, brand);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, brand);
            }
            verification_all_letters(brand);

            cout << "Type: ";
            getline(cin, type);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, type);
            }
            verification_all_letters(type);

            cout << "Date: ";
            getline(cin, date);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, date);
            }
            Time v_bdate = verification_date(date);
            Vehicle v(brand, type, v_bdate);
            g = new Deliverer(b, name, stoi(nif), v_bdate, 0, v, background);
            system("cls");
            cout << g;
            cout << endl << "-----------------------------------------------" << endl;
            if (confirm_modifications("create","deliverer")){
                if (b == "Porto") Porto.addEmployee(g);
                else if (b == "Lisboa") Lisboa.addEmployee(g);
                else if (b == "Faro") Faro.addEmployee(g);
                system("cls");
                cout << endl << "Deliverer was successfully created!" << endl << endl;

            }
            else{    //caso de nao se confirmar a criaçao
                system("cls");
                cout << endl << "Operation was canceled! " << endl << endl;
            }

            break;
    }
    //voltar para o menu
    cout << "1. Return to Main Menu." << endl;
    cout << "2. Return to Employees Management." << endl;
    menu_int_options(option,1,2);

    return option;
}

int modify_employee(Base &Porto, Base &Lisboa, Base &Faro){

    string b, auxiliar, aux;
    int number,i;
    vector <Employee*> v;
    bool is_valid = false;
    string income;

    system("cls");
    cout << endl << "---------------- MODIFY EMPLOYEE ----------------" << endl << endl;

    cout << "Base: ";
    getline(cin, b);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout <<  "Invalid base. Please insert a valid input: ";
        getline(cin, b);
    }
    verification_base(b);

    if (b == "Porto") {
        v = Porto.getEmployees();
    }
    else if (b == "Lisboa") {
        v = Lisboa.getEmployees();
    }
    else if (b == "Faro") {
        v = Faro.getEmployees();
    }

    cout << endl << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do employee
    cout << "1. Name\n"<< "2. NIF\n" <<"0. Return to the main menu\n" ;
    menu_int_options(number,0,2);
    cin.ignore(1000, '\n');
    string name;

    switch (number) {
        case 0:
            return 1;
        case 1:
            cout << "Name: ";
            getline(cin, name);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, name);
            }
            verification_all_letters(name);
            i = string_sequential_search_e(v, name);
            break;
        case 2:
            cout << "NIF: ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_e(v, stoi(auxiliar));
            break;
    }


    while(i == -1){
        cout << endl << "The employee inserted does not exist. Try again:" << endl;//dar opçao de tentar outra vez
        cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do employee
        cout << "1. Name\n" << "2. NIF\n"<<"0. Return to the main menu\n";
        menu_int_options(number,0,2);
        cin.ignore(1000, '\n');

        switch(number){
            case 0:
                return 1;
            case 1:
                cout << "Name: ";
                getline(cin, name);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, name);
                }
                verification_all_letters(name);
                i = string_sequential_search_e(v, name);
                break;
            case 2:
                cout << "NIF: ";
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_nif(auxiliar);
                i = int_sequential_search_e(v, stoi(auxiliar));
                break;
        }
    }

    system("cls");

    Admin *a= dynamic_cast<Admin *> (v[i]);
    if(a!=NULL){//quer dizer que é admin
        int op;
        cout << a << endl;        //mostrar o employee para saber o que quer mudar
        cout << "-----------------------------------------------" << endl;
        cout << "You can only change the task."<<endl;
        cout<< "What do you wish to do? "<<endl;
        cout<< "1. Change the task\t 2. Return to the Main Menu"<<endl;
        menu_int_options(op,1,2);
        cin.ignore(1000, '\n');
        switch(op){
            case 1:{
                cout << "Task: ";
                getline(cin, aux);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                verification_all_letters(aux);

                cout << "Income: ";
                getline(cin, income);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, income);
                }
                verification_float(income);

                cout << endl << "-----------------------------------------------" << endl;
                if(confirm_modifications("modify","admin")){
                    a->setTask(aux);
                    a->setIncome(stof(income));
                    system("cls");
                    cout << "Admin was successfully modified!" << endl << endl;
                }
                else{
                    system("cls");
                    cout << "Operation was canceled!" << endl << endl;
                }
                //voltar para o menu
                int option;
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Employees Management." << endl;
                menu_int_options(option,1,2);

                return option;
            }
            case 2:
            {
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
                return 1;
            }
        }

    }
    else{

        Deliverer *d= dynamic_cast<Deliverer*>(v[i]);
        int op;

        cout << d << endl;        //mostrar o employee para saber o que quer mudar
        cout << "-----------------------------------------------" << endl;

        cout << "You can only change the allocated vehicle."<<endl;
        cout<< "What do you wish to do? "<<endl;
        cout<< "1. Change the allocated vehicle\n 2. Return to the Main Menu"<<endl;
        menu_int_options(op,1,2);
        cin.ignore(1000, '\n');
        switch(op){
            case 1:{
                string brand, type, date;
                cout << "Information of the vehicle alocated to this deliverer:\n";
                cout << "Brand: ";
                getline(cin, brand);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, brand);
                }
                verification_all_letters(brand);

                cout << "Type: ";
                getline(cin, type);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, type);
                }
                verification_all_letters(type);

                cout << "Date: ";
                getline(cin, date);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, date);
                }
                Time v_bdate = verification_date(date);
                Vehicle ve(brand, type, v_bdate);

                cout << endl << "-----------------------------------------------" << endl;
                if(confirm_modifications("modify","employee")){
                    d->setVehicle(ve);
                    system("cls");
                    cout << "Employee was successfully created!" << endl << endl;
                }
                else{
                    system("cls");
                    cout << "Operation was canceled!" << endl << endl;
                }

                //voltar para o menu
                int option;
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Employees Management." << endl;
                menu_int_options(option,1,2);

                return option;
            }
            case 2:
            {
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
                return 1;
            }
        }
    }
    return 1;
}

int remove_employee(Base &Porto, Base &Lisboa, Base &Faro){
    vector<Employee*> v;
    string base, auxiliar;
    int i=0, number,option;

    system("cls");
    cout << endl << "---------------- REMOVE EMPLOYEE ----------------" << endl << endl;

    cout << "Employee's base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getEmployees();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getEmployees();
    }
    else if (base == "Faro") {
        v = Faro.getEmployees();
    }
    cout << endl << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do employee
    cout << "1. Name\n"<< "2. NIF\n" <<"0. Return to the main menu\n" ;
    menu_int_options(number,0,2);
    cin.ignore(1000, '\n');

    switch (number) {
        case 0:
            return 1;
        case 1:
            cout << "Name: ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);
            i = string_sequential_search_e(v, auxiliar);
            break;
        case 2:
            cout << "NIF: ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_e(v, stoi(auxiliar));
            break;
    }

    while (i == -1) {
        cout << endl << "The employee inserted does not exist. Try again:";//dar opçao de tentar outra
        cout << "What do you know about this employee?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do employee
        cout << "1. Name\n" << "2. NIF\n"<<"0. Return to the main menu\n";
        menu_int_options(number,1,2);
        cin.ignore(1000, '\n');
        switch (number) {
            case 0:
                return 1;
            case 1:
                cout << "Name:";
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_all_letters(auxiliar);
                i = string_sequential_search_e(v, auxiliar);
                break;
            case 2:
                cout << "NIF: ";
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_nif(auxiliar);
                i = int_sequential_search_e(v, stoi(auxiliar));
                break;
        }
    }

    system("cls");

    Admin *a= dynamic_cast<Admin *> (v[i]);
    if(a != NULL){ //é um administrador
        cout << a;
    }
    else { //é um entregador
        Deliverer *d = dynamic_cast<Deliverer *> (v[i]);
        cout << d;
    }

    cout << endl << "-----------------------------------------------" << endl;
    if (confirm_modifications("remove", "employee")) {
        if (base == "Porto") Porto.removeEmployee(i);
        else if (base == "Lisboa") Lisboa.removeEmployee(i);
        else if (base == "Faro") Faro.removeEmployee(i);
        system("cls");
        cout << "Employee was successfully removed!" << endl << endl;
    }
    else {//caso de nao se confirmar a remoçao
        system("cls");
        cout <<  "Operation was canceled! " << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Employees Management. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int changeManager(Base& Porto, Base& Lisboa, Base& Faro){
    int op1,op2,counter=1,option;
    Base b;
    vector<Admin*> admins = {};
    system("cls");
    cout << endl << "---------------- CHANGE MANAGER ----------------" << endl;

    cout << "From which base do you want to change the manager? \n";
    cout << "1. Porto \t 2. Lisboa \t 3. Faro \t 0. Return to the Main Menu"<<endl;
    menu_int_options(op1,0,3);
    switch(op1){
        case 0:
            return 1;
        case 1:
            system("cls");
            cout<< "The actual manager of Porto is "<< Porto.getManager() << endl;
            cout << endl << "-----------------------------------------------" << endl;
            if(confirm_modifications("remove","manager")){
                cout << endl << endl << "-----------------------------------------------" << endl;
                cout << "These are the current admins. Choose one of them: ";
                vector<Employee*> employees = Porto.getEmployees();
                for( vector<Employee*>::const_iterator it = employees.begin(); it!= employees.end(); it++){
                    Admin *a= dynamic_cast<Admin *> (*it);
                    if(a!= nullptr) {
                        admins.push_back(a);
                        cout << counter << ":" << endl << a << endl << endl;
                        counter++;
                    }
                }
                menu_int_options(op2,1,counter);
                Porto.setManager(admins.at(op2-1)->getName());
                Porto.setManagerNif(admins.at(op2-1)->getNif());
                int i = int_sequential_search_e(employees, admins.at(op2-1)->getNif());
                Porto.removeEmployee(i);
                system("cls");
                cout << "Manager was changed successfully!" << endl;
            }
            else{
                system("cls");
                cout <<  "Operation was canceled! " << endl << endl;
            }
            break;
        case 2:
            system("cls");
            cout<< "The actual manager of Lisboa is "<< Lisboa.getManager() << endl;
            cout << endl << "-----------------------------------------------" << endl;
            if(confirm_modifications("remove","manager")){
                cout << endl << endl << "-----------------------------------------------" << endl;
                cout << "These are the current admins. Choose one of them:";
                vector<Employee*> employees = Lisboa.getEmployees();
                for( vector<Employee*>::const_iterator it = employees.begin(); it!= employees.end(); it++){
                    Admin *a= dynamic_cast<Admin *> (*it);
                    if(a!= nullptr){
                        admins.push_back(a);
                        cout << counter << ":" <<endl<<a<<endl<<endl;
                        counter ++;
                    }
                }
                menu_int_options(op2,1,counter);
                Lisboa.setManager(admins.at(op2-1)->getName());
                Lisboa.setManagerNif(admins.at(op2-1)->getNif());
                int i = int_sequential_search_e(employees, admins.at(op2-1)->getNif());
                Lisboa.removeEmployee(i);
                system("cls");
                cout << "Manager was changed successfully!"<< endl;
            }
            else{
                system("cls");
                cout << endl << "Operation was canceled! " << endl << endl;
            }
            break;
        case 3:
            system("cls");
            cout<< "The actual manager of Faro is "<< Faro.getManager()<<endl;
            cout << endl << "-----------------------------------------------" << endl;
            if(confirm_modifications("remove","manager")){
                cout << endl << endl << "-----------------------------------------------" << endl;
                cout << "These are the current admins. Choose one of them:";
                vector<Employee*> employees = Faro.getEmployees();
                for( vector<Employee*>::const_iterator it = employees.begin(); it!= employees.end(); it++){
                    Admin *a= dynamic_cast<Admin *> (*it);
                    if(a!= nullptr) {
                        admins.push_back(a);
                        cout << counter << ":" << endl << a << endl << endl;
                        counter++;
                    }
                }
                menu_int_options(op2,1,counter);
                Faro.setManager(admins.at(op2-1)->getName());
                Faro.setManagerNif(admins.at(op2-1)->getNif());
                int i = int_sequential_search_e(employees, admins.at(op2-1)->getNif());
                Faro.removeEmployee(i);
                system("cls");
                cout << "Manager was changed successfully!" << endl;
            }
            else{
                system("cls");
                cout << endl << "Operation was canceled! " << endl << endl;
            }
            break;
    }

    cout << "We are going to return to the Main Menu"<<endl;
    return 1;

}

//Funcoes relativas às excecoes
bool employee_already_exists(string nif, const Base &p, const Base &l, const Base &f){
    if((p.getIndexEmployee(nif) == -1) && (l.getIndexEmployee(nif) == -1) && (f.getIndexEmployee(nif) == -1)) return false;
    throw EmployeeAlreadyExists(nif);

}

int string_sequential_search_e(const vector<Employee*> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i]->getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}

int int_sequential_search_e(const vector<Employee*> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i]->getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}