#include "Tecs_functions.h"
int hire_tec(Base &Porto, Base &Lisboa, Base &Faro){
    string aux,b;
    vector<Tec> v;
    Tec new_tec;
    Base base;
    bool is_Valid;
    int option;

    system("cls");
    cout << endl << "---------------- HIRE TECHNICIAN ----------------" << endl << endl;

    cout << "Base: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_base(aux);
    new_tec.setBase(aux);

    if (aux == "Porto") {
        base = Porto;
        b = "Porto";
    }
    else if (aux == "Lisboa") {
        base = Lisboa;
        b = "Lisboa";
    }
    else if(aux == "Faro"){
        base = Faro;
        b = "Faro";
    }
    v = base.getTecs();

    cout << "Name: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    new_tec.setName(aux);

    cout << "NIF (Enter 0 to quit): ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_int(aux);

    if(stoi(aux) == 0){
        return 2;
    }

    verification_nif(aux);

    do{
        try{
            tec_already_exists(aux, Porto, Lisboa, Faro);
            is_Valid = true;
        }
        catch(TecAlreadyExists &msg){
            cout << endl << "ATENTION: Technician with NIF "<< msg.getNIF() << " already exists." << endl;
            is_Valid = false;
            cout << "Try again!" << endl;
            cout << "NIF (Enter 0 to quit): ";
            getline(cin, aux);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            verification_int(aux);

            if(stoi(aux) == 0){
                return 2;
            }
            verification_nif(aux);
        }

    } while(!is_Valid);


    new_tec.setNif(stoi(aux));

    cout << "Birthdate: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }

    new_tec.setBirthdate(verification_date(aux));

    cout << "Number of maintenances: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_int(aux);
    new_tec.setNumberOfMaintenances(stoi(aux));

    new_tec.setTimeToAvailable(0);

    system("cls");

    cout << new_tec;//para confirmar  a informaçao
    cout << endl << "-----------------------------------------------"  << endl;
    if (confirm_modifications("hire", "technician")) {
        cout << endl << endl;

        if (new_tec.getBase() == "Porto") {
            Porto.addTec(new_tec);
            system("cls");
            cout << "Technician was successfully hired!" << endl << endl;
        }
        else if (new_tec.getBase() == "Lisboa") {
            Lisboa.addTec(new_tec);
            system("cls");
            cout << "Technician was successfully hired!" << endl << endl;
        }
        else if(new_tec.getBase() == "Faro"){
            Faro.addTec(new_tec);
            system("cls");
            cout << "Technician was successfully hired!" << endl << endl;
        }
    }
    else {    //caso de nao se confirmar a criaçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    //voltar para o menu
    cout << "1. Return to Main Menu." << endl;
    cout << "2. Return to Technicians Management." << endl;
    menu_int_options(option,1,2);

    return option;
}

int modify_tec(Base &Porto, Base &Lisboa, Base &Faro){

    string aux, base;
    TecPriorityQueue v;
    Tec t;

    system("cls");
    cout << endl << "---------------- MODIFY TECHNICIAN ----------------" << endl << endl;

    cout << "Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getTecs_q();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getTecs_q();
    }
    else if (base == "Faro") {
        v = Faro.getTecs_q();
    }

    int number, index;
    string nif, auxiliar;

    cout << "NIF (Enter 0 to quit): ";
    getline(cin, auxiliar);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, auxiliar);
    }
    verification_int(auxiliar);

    if(auxiliar == "0"){
        return 2;
    }
    verification_nif(auxiliar);
    t = Tec_sequential_search_t(v, stoi(auxiliar));



    if (t.getName() == "aaaaaa") {
        cout << "The technician inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (t.getName() == "aaaaaa") {
            cout << "NIF (En    ter 0 to quit): ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_int(auxiliar);

            if(auxiliar == "0"){
                return 2;
            }
            verification_nif(auxiliar);
            t = Tec_sequential_search_t(v, stoi(auxiliar));
        }
    }

    system("cls");



    cout << t << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "You can only change the number of maintenances. What do you wish to do? "<< endl << endl;
    cout<< "1. Change the number of maintenances\n2. Return to the Main Menu"<<endl;
    menu_int_options(number, 1, 2);
    cin.ignore(1000, '\n');

    if(number == 2) return 1;

    else if (number == 1){
        cout << "Number of maintenances: ";
        getline(cin, aux);
        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, aux);
        }
        verification_int(aux);

    }

    cout << endl << "-----------------------------------------------" << endl;
    if(confirm_modifications("modify","technician")){
        if(base == "Porto"){
            Porto.removeTec(t);
            t.setNumberOfMaintenances(stoi(aux));
            Porto.addTec(t);
        }
        else if(base == "Lisboa"){
            Lisboa.removeTec(t);
            t.setNumberOfMaintenances(stoi(aux));
            Lisboa.addTec(t);
        }
        else if (base == "Faro"){
            Faro.removeTec(t);
            t.setNumberOfMaintenances(stoi(aux));
            Faro.addTec(t);
        }


        system("cls");
        cout << "Technician was successfully modified!" << endl << endl;
    }
    else{
        system("cls");
        cout << "Operation was canceled!" << endl << endl;
    }


    int option;
    cout << "1. Return to Main Menu." << endl;
    cout << "2. Return to Technicians Management." << endl;
    menu_int_options(option,1,2);

    return option;
}

int remove_tec(Base &Porto, Base &Lisboa, Base &Faro){
    string base, auxiliar;
    int option;
    TecPriorityQueue v;
    Tec t;

    system("cls");
    cout << "---------------- REMOVE TECHNICIAN ---------------- " << endl;

    cout << "Base:  ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getTecs_q();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getTecs_q();
    }
    else if (base == "Faro") {
        v = Faro.getTecs_q();
    }

    cout << "NIF (Enter 0 to quit): ";
    getline(cin, auxiliar);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, auxiliar);
    }
    verification_int(auxiliar);

    if(auxiliar == "0"){
        return 2;
    }
    verification_nif(auxiliar);

    t = Tec_sequential_search_t(v, stoi(auxiliar));
    if (t.getName() == "aaaaaa") {
        cout << "The technician inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (t.getName() == "aaaaaa") {
            cout << "NIF (Enter 0 to quit): ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_int(auxiliar);

            if(auxiliar == "0"){
                return 2;
            }
            verification_nif(auxiliar);
            t = Tec_sequential_search_t(v, stoi(auxiliar));
        }
    }

    system("cls");
    cout << t <<endl;

    if(t.getTimeToAvailable() != 0){
        cout << endl << "Atention: This technician has an unfinished maintenance. The vehicle will be attributed to another available technician." << endl;
    }

    cout << endl << endl << "-----------------------------------------------" << endl;
    if(confirm_modifications("remove","technician")){
        if (base == "Porto") {
            Porto.removeTec(t);
            if(t.getTimeToAvailable() != 0){
                Tec aux = Porto.getTecs_q().top();
                Porto.removeTec(aux);
                aux.setTimeToAvailable(t.getTimeToAvailable());
                Porto.addTec(aux);
            }
        }
        else if (base == "Lisboa") {
            Lisboa.removeTec(t);
            if(t.getTimeToAvailable() != 0){
                Tec aux = Lisboa.getTecs_q().top();
                Lisboa.removeTec(aux);
                aux.setTimeToAvailable(t.getTimeToAvailable());
                Lisboa.addTec(aux);
            }
        }
        else if (base == "Faro") {
            Faro.removeTec(t);
            if(t.getTimeToAvailable() != 0){
                Tec aux = Faro.getTecs_q().top();
                Faro.removeTec(aux);
                aux.setTimeToAvailable(t.getTimeToAvailable());
                Faro.addTec(aux);
            }
        }
        system("cls");
        cout << "Technician was successfully removed!" << endl << endl;
    }
    else {//caso de nao se confirmar a remoçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Technicians Management. " << endl;
    menu_int_options(option,1,2);
    return option;
}

void tec_already_exists(string nif, const Base &p, const Base &l, const Base &f){

    vector<Tec> p_aux = p.getTecs(), l_aux = l.getTecs(), f_aux = f.getTecs();

    vector<Tec>::const_iterator p_it = p_aux.begin();
    vector<Tec>::const_iterator l_it = l_aux.begin();
    vector<Tec>::const_iterator f_it = f_aux.begin();

    while(p_it != p_aux.end()){
        if (stoi(nif) == (*p_it).getNif()){
            throw TecAlreadyExists(nif);
        }
        advance(p_it, 1);
    }

    while(l_it != l_aux.end()) {
        if (stoi(nif) == (*l_it).getNif()) {
            throw TecAlreadyExists(nif);
        }
        advance(l_it, 1);
    }

    while(f_it != f_aux.end()){
        if (stoi(nif) == (*f_it).getNif()){
            throw TecAlreadyExists(nif);
        }
        advance(f_it, 1);
    }
    return;
}

Tec Tec_sequential_search_t(TecPriorityQueue tec , int x) { //retorna o tecnico com nif=x
    TecPriorityQueue aux = tec;
    Tec t;
    while(!aux.empty()){
        t =aux.top();
        aux.pop();
        if(t.getNif() == x) {
            return t;
        }
    }
    t.setName("aaaaaa");
    return t; // não encontrou
}
