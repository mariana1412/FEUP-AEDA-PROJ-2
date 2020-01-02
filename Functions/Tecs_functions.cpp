#include "Tecs_functions.h"
int hire_tec(Base &Porto, Base &Lisboa, Base &Faro){
    string aux,b;
    vector<Tec> v;
    Tec new_tec;
    Base base;
    bool is_Valid;
    int option;

    system("cls");
    cout << endl << "---------------- HIRE TEC ----------------" << endl << endl;

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

    cout << "NIF: ";
    getline(cin, aux);
    cout <<aux;
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_nif(aux);

    do{
        try{
            tec_already_exists(aux, Porto, Lisboa, Faro);
            is_Valid = true;
        }
        catch(TecAlreadyExists &msg){
            cout << endl << "ATENTION: Tec with NIF "<< msg.getNIF() << " already exists." << endl;
            is_Valid = false;
            cout << "Try again!"<<endl;
            cout << "NIF: ";
            getline(cin, aux);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
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
    new_tec.setTimeToAvailable(0);
    new_tec.setNumberOfMaintenances(0);

    system("cls");

    cout << new_tec;//para confirmar  a informaçao
    cout << endl << "-----------------------------------------------"  << endl;
    if (confirm_modifications("create", "client")) {
        cout << endl << endl;

        if (new_tec.getBase() == "Porto") {
            Porto.addTec(new_tec);
            system("cls");
            cout << "Tec was successfully hired!" << endl << endl;
        }
        else if (new_tec.getBase() == "Lisboa") {
            Lisboa.addTec(new_tec);
            system("cls");
            cout << "Tec was successfully hired!" << endl << endl;
        }
        else if(new_tec.getBase() == "Faro"){
            Faro.addTec(new_tec);
            system("cls");
            cout << "Tec was successfully hired!" << endl << endl;
        }
    }
    else {    //caso de nao se confirmar a criaçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    //voltar para o menu
    cout << "1. Return to Main Menu." << endl;
    cout << "2. Return to Employees Management." << endl;
    menu_int_options(option,1,2);

    return option;
}



int modify_tec(Base &Porto, Base &Lisboa, Base &Faro){

}


int remove_tec(Base &Porto, Base &Lisboa, Base &Faro){

}



void tec_already_exists(string nif, const Base &p, const Base &l, const Base &f){
    vector<Tec>::const_iterator p_it = p.getTecs().begin();
    vector <Tec>::const_iterator l_it = l.getTecs().begin();
    vector <Tec>::const_iterator f_it = f.getTecs().begin();
    while(p_it != p.getTecs().end()){
        if (stoi(nif) == (*p_it).getNif()){
            throw TecAlreadyExists(nif);
        }
        advance(p_it, 1);
    }
    while(l_it != l.getTecs().end()){
        if (stoi(nif) == (*l_it).getNif()){
            throw TecAlreadyExists(nif);
        }
        advance(l_it, 1);
    }

    while(f_it != f.getTecs().end()){
        if (stoi(nif) == (*f_it).getNif()){
            throw TecAlreadyExists(nif);
        }
        advance(f_it, 1);
    }
    return;
}