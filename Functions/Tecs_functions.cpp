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

    cout << "NIF (Enter 0 to quit): ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_nif(aux);

    if(stoi(aux) != 0){
        do{
            try{
                tec_already_exists(aux, Porto, Lisboa, Faro);
                is_Valid = true;
            }
            catch(TecAlreadyExists &msg){
                cout << endl << "ATENTION: Tec with NIF "<< msg.getNIF() << " already exists." << endl;
                is_Valid = false;
                cout << "Try again!"<<endl;
                cout << "NIF (Enter 0 to quit): ";
                getline(cin, aux);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, aux);
                }
                verification_nif(aux);
            }

        } while(!is_Valid && stoi(aux)!=0);
        if(stoi(aux)!=0) new_tec.setNif(stoi(aux));
    }
    if(stoi(aux) ==0){
        return 2;
    }

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
    cout << "2. Return to Tec Management." << endl;
    menu_int_options(option,1,2);

    return option;
}



int modify_tec(Base &Porto, Base &Lisboa, Base &Faro){

}


int remove_tec(Base &Porto, Base &Lisboa, Base &Faro){
    string base, auxiliar;
    int option;
    TecPriorityQueue v;
    Tec t;

    system("cls");
    cout << "---------------- REMOVE TEC ---------------- " << endl;

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
    verification_nif(auxiliar);
    if(stoi(auxiliar)!= 0){
        t = Tec_sequential_search_t(v, stoi(auxiliar));
        if (t.getName() == "aaaaaa") {
            cout << "The tec inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
            while (t.getName() == "aaaaaa") {
                cout << "NIF (Enter 0 to quit): ";
                getline(cin, auxiliar);
                while(cin.fail() && cin.eof()){
                    cin.clear();
                    cout << "Invalid character. Please insert a valid input: ";
                    getline(cin, auxiliar);
                }
                verification_nif(auxiliar);
                if(stoi(auxiliar)!= 0){
                    t = Tec_sequential_search_t(v, stoi(auxiliar));
                }
            }
        }
    }
    if(stoi(auxiliar)==0){
        return 2;
    }
    system("cls");
    cout << t <<endl;
    cout << endl << endl << "-----------------------------------------------" << endl;
    if(confirm_modifications("remove","tec")){
        if (base == "Porto") {
            Porto.removeTec(t);
        }
        else if (base == "Lisboa") {
            Lisboa.removeTec(t);
        }
        else if (base == "Faro") {
            Faro.removeTec(t);

        }
        system("cls");
        cout << "Tec was successfully removed!" << endl << endl;
    }
    else {//caso de nao se confirmar a remoçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Tec Management. " << endl;
    menu_int_options(option,1,2);
    return option;
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

Tec Tec_sequential_search_t( TecPriorityQueue tec , int x) {//retorna o tecnico com nif=x
    TecPriorityQueue aux=tec;
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
