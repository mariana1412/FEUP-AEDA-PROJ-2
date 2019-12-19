#include "Clients_functions.h"

int create_client(Base &Porto, Base &Lisboa, Base &Faro, bool is_Client) {
    string aux,b;
    vector<Client> v;
    Client new_client;
    Base base;
    bool is_Valid;
    int option;

    system("cls");
    cout << endl << "---------------- CREATE CLIENT ----------------" << endl << endl;

    cout << "Base: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_base(aux);
    new_client.setBase(aux);

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
    v = base.getClients();

    cout << "Name: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    new_client.setName(aux);

    cout << "NIF: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_nif(aux);

    do{
        try{
            client_already_exists(aux, Porto, Lisboa, Faro);
            is_Valid = true;
        }
        catch(ClientAlreadyExists &msg){
            cout << endl << "ATENTION: Client with NIF "<< msg.getNIF() << " already exists." << endl;
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
    new_client.setNif(stoi(aux));


    cout << "Address: "; //nao ha verificaçao porque pode ter tanto letras como numeros
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    formatting_string(aux);
    new_client.setAddress(aux);

    cout << "County: ";
    getline(cin, aux);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    new_client.setCounty(aux);

    new_client.setBlack(false);

    system("cls");

    cout << new_client;//para confirmar  a informaçao
    cout << endl << "-----------------------------------------------"  << endl;
    if (confirm_modifications("create", "client")) {
        cout << endl << endl;
        try {
            black_list(base, new_client.getNif()); //se o cliente estiver na black_list é rejeitado
        }
        catch (BlackList &e) {
            cout << e.getMsg() << endl<<endl;
            if(is_Client){
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Account Management. " << endl;
                menu_int_options(option,1,2);
                return option;
            }
            else{
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Clients Management." << endl;
                menu_int_options(option,1,2);
                return option;
            }
        }
        try {
            out_of_area(v, new_client.getCounty(),b); //caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
        }
        catch (OutOfArea &b) {
            system("cls");
            cout << b.getMsg() << endl << endl;

            if(is_Client){
                cout << "1. Return to Main Menu. " << endl;
                cout << "2. Return to Account Management. " << endl;
                menu_int_options(option,1,2);
                return option;
            }
            else{
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Clients Management." << endl;
                menu_int_options(option,1,2);
                return option;
            }
        }

        if (new_client.getBase() == "Porto") {
            Porto.addClient(new_client);
            system("cls");
            cout << "Client was successfully created!" << endl << endl;
        }
        else if (new_client.getBase() == "Lisboa") {
            Lisboa.addClient(new_client);
            system("cls");
            cout << "Client was successfully created!" << endl << endl;
        }
        else if(new_client.getBase() == "Faro"){
            Faro.addClient(new_client);
            system("cls");
            cout << "Client was successfully created!" << endl << endl;
        }
    }
    else {    //caso de nao se confirmar a criaçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    //voltar para o menu
    if(is_Client){
        cout << "1. Return to Main Menu. " << endl;
        cout << "2. Return to Account Management. " << endl;
        menu_int_options(option,1,2);
    }
    else{
        cout << "1. Return to Main Menu. " << endl;
        cout << "2. Return to Clients Management. " << endl;
        menu_int_options(option,1,2);
    }

    return option;
}

int modify_client(Base &Porto, Base &Lisboa, Base &Faro) {

    vector<Client> v;
    string base;
    int i = 0;
    string auxiliar, change, name ;
    int number, option, op, nif;
    Client cl;

    system("cls");
    cout << endl << "---------------- MODIFY CLIENT ----------------" << endl << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    } else if (base == "Lisboa") {
        v = Lisboa.getClients();
    } else if (base == "Faro") {
        v = Faro.getClients();
    }


    cout << endl << "What do you know about this client?\n"
         << endl; //so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1. Name\n" << "2. NIF\n" << "0. Return to the main menu\n";
    menu_int_options(number, 0, 2);
    cin.ignore(1000, '\n');

    switch (number) {
        case 0:
            return 1;
        case 1:
            cout << "Name: ";
            getline(cin, auxiliar);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_all_letters(auxiliar);
            i = string_sequential_search_c(v, auxiliar);
            break;
        case 2:
            cout << "NIF: ";
            getline(cin, auxiliar);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_c(v, stoi(auxiliar));
            break;
    }

    if (i == -1) {
        cout << endl << endl << "The client inserted does not exist. Try again:" << endl; //dar opçao de tentar outra vez
        while (i == -1) {
            cout << "What do you know about this client?\n"
                 << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
            cout << "1. Name\n" << "2. NIF\n" << "0. Return to the main menu\n";
            menu_int_options(number, 0, 2);
            cin.ignore(1000, '\n');

            switch (number) {
                case 0:
                    return 1;
                case 1:
                    cout << "Name: ";
                    getline(cin, auxiliar);
                    while (cin.fail() && cin.eof()) {
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, auxiliar);
                    }
                    verification_all_letters(auxiliar);
                    i = string_sequential_search_c(v, auxiliar);
                    break;
                case 2:
                    cout << "NIF:";
                    getline(cin, auxiliar);
                    while (cin.fail() && cin.eof()) {
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, auxiliar);
                    }
                    verification_nif(auxiliar);
                    i = int_sequential_search_c(v, stoi(auxiliar));
                    break;

            }

        }
    }
    if(i != -1) {
        system("cls");
        string new_info, new_info2, new_info3;
        name = v[i].getName();
        nif= v[i].getNif();
        cout << v[i];        //mostrar o cliente para saber o que quer mudar
        cout << endl << "-----------------------------------------------" << endl;
        cout << "What do you want to change?\n";
        cout << "1. Base\n" << "2. Address\n" << "0. Return to the main menu" << endl;
        menu_int_options(option, 0, 2);
        cin.ignore(1000, '\n');

        if(option == 0){
            return 1;
        }
        else if (option == 1) {
            cout << "Base: ";
            getline(cin, new_info);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }
            verification_base(new_info);

            if (new_info == "Porto") {
                v = Porto.getClients();
            } else if (new_info == "Lisboa") {
                v = Lisboa.getClients();
            } else if (new_info == "Faro") {
                v = Faro.getClients();
            }

            cout << "Address: ";
            getline(cin, new_info2);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            formatting_string(new_info2);

            cout << "County: ";
            getline(cin, new_info3);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info3);
            }
            verification_all_letters(new_info3);

            cout << endl << endl << "-----------------------------------------------"  << endl;
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info3, new_info);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    system("cls");
                    cout << b.getMsg() << endl << endl;
                    cout << "1. Return to Main Menu." << endl;
                    cout << "2. Return to Clients Management." << endl;
                    menu_int_options(op, 1, 2);
                    return op;
                }
                cl.setName(name);
                cl.setNif(nif);
                cl.setBase(new_info);
                cl.setAddress(new_info2);
                cl.setCounty(new_info3);
                if (base == "Porto") {
                    if (new_info == "Porto") {
                        Porto.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Porto.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Porto.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    if (new_info == "Porto") {
                        Lisboa.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Lisboa.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Lisboa.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    if (new_info == "Porto") {
                        Faro.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Faro.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Faro.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
            } else {//caso de nao se confirmar a mudança
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
            }
        }
        else if (option == 2) {
            cout << "Address: ";
            getline(cin, new_info);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }

            cout << "County: ";
            getline(cin, new_info2);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            verification_all_letters(new_info2);

            cout << endl << endl << "-----------------------------------------------"  << endl;
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info2,base);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    system("cls");
                    cout << b.getMsg() << endl;
                    cout << "1. Return to Main Menu." << endl;
                    cout << "2. Return to Clients Management." << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
                cl.setBase(base);
                cl.setName(name);
                cl.setNif(nif);
                cl.setAddress(new_info);
                cl.setCounty(new_info2);
                if (base == "Porto") {
                    Porto.removeClient(i);
                    Porto.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    Lisboa.removeClient(i);
                    Lisboa.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    Faro.removeClient(i);
                    Faro.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }

            }
            else {//caso de nao se confirmar a mudança
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Clients Management." << endl;
                menu_int_options(op, 1, 2);
                cin.ignore(1000, '\n');
                return op;
            }
        }

        //voltar para o menu
        cout << "1. Return to Main Menu." << endl;
        cout << "2. Return to Clients Management." << endl;
        menu_int_options(op, 1, 2);
        return op;
    }

    return op;
}

int remove_client(Base &Porto, Base &Lisboa, Base &Faro) {
    vector<Client> v;
    string base, auxiliar;
    int i=0, number,option;

    system("cls");
    cout << endl << "----------------  REMOVE CLIENT ----------------" << endl << endl;

    cout << "Client's Base: ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "Faro") {
        v = Faro.getClients();
    }


    cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
    cout << "1. Name\n" << "2. NIF\n"<<"0. Return to the main menu\n";
    menu_int_options(number,1,2);
    cin.ignore(1000, '\n');


    if(number == 1){
        cout << "Name: ";
        getline(cin, auxiliar);
        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input: ";
            getline(cin, auxiliar);
        }
        verification_all_letters(auxiliar);
        i = string_sequential_search_c(v, auxiliar);
    }
    else if(number == 2){
        cout << "NIF: ";
        getline(cin, auxiliar);
        while(cin.fail() && cin.eof()){
            cin.clear();
            cout << "Invalid character. Please insert a valid input:";
            getline(cin, auxiliar);
        }
        verification_nif(auxiliar);
        i = int_sequential_search_c(v, stoi(auxiliar));
    }
    else if(number == 0){
        return number;
    }

    if (i == -1) {
        cout << "The client inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (i == -1) {
            cout << "What do you know about this client?\n" << endl;//so vamos ter estas duas opçoes porque sao os atributos nao mutaveis do cliente
            cout << "1. Name\n" << "2. NIF\n"<<"0. Return to the main menu\n";
            menu_int_options(number,1,2);
            cin.ignore(1000, '\n');
            switch (number) {
                case 0:
                    return number;
                case 1:
                    cout << "Name: ";
                    getline(cin, auxiliar);
                    while(cin.fail() && cin.eof()){
                        cin.clear();
                        cout << "Invalid character. Please insert a valid input: ";
                        getline(cin, auxiliar);
                    }
                    verification_all_letters(auxiliar);
                    i = string_sequential_search_c(v, auxiliar);
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
                    i = int_sequential_search_c(v, stoi(auxiliar));
                    break;
            }
        }
    }
    else {
        system("cls");
        cout<< v[i];//mostrar o cliente
        cout << endl << endl << "-----------------------------------------------" << endl;
        if (confirm_modifications("remove", "client")) {
            if (base == "Porto") {
                Porto.removeClient(i);
            }
            else if (base == "Lisboa") {
                Lisboa.removeClient(i);
            }
            else if (base == "Faro") {
                Faro.removeClient(i);

            }
            system("cls");
            cout << "Client was successfully removed!" << endl << endl;
        }
        else {//caso de nao se confirmar a remoçao
            system("cls");
            cout << "Operation was canceled! " << endl << endl;
        }
    }
    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Clients Management. " << endl;
    menu_int_options(option,1,2);
    return option;

}

int modifyData(Base &Porto, Base &Lisboa, Base &Faro){
    vector<Client> v;
    string base;
    int i = 0;
    string auxiliar, change, name ;
    int number, option, op, nif;
    Client cl;

    system("cls");
    cout << endl << "---------------- MODIFY DATA ----------------" << endl << endl;

    cout << "What is your base? ";
    getline(cin, base);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    } else if (base == "Lisboa") {
        v = Lisboa.getClients();
    } else if (base == "Faro") {
        v = Faro.getClients();
    }
    
    cout << "What is your NIF? ";
    getline(cin, auxiliar);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, auxiliar);
    }
    verification_nif(auxiliar);
    i = int_sequential_search_c(v, stoi(auxiliar));


    if (i == -1) {
        cout << "The client inserted does not exist. Try again:" << endl;//dar opçao de tentar outra vez
        while (i == -1) {
            cout << "NIF: ";
            getline(cin, auxiliar);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_c(v, stoi(auxiliar));
        }
    }
    if( i != -1) {
        string new_info, new_info2, new_info3;
        name = v[i].getName();
        nif= v[i].getNif();
        system("cls");
        cout << v[i] << endl;        //mostrar o cliente para saber o que quer mudar
        cout << "-----------------------------------------------" << endl;
        cout << "What do you want to change?\n";
        cout << "1. Base\n" << "2. Address\n" << "0. Return to the main menu" << endl;
        menu_int_options(option, 0, 2);
        cin.ignore(1000, '\n');
        if(option == 0){
            return 1;
        }
        else if (option == 1) {
            cout << "Base: ";
            getline(cin, new_info);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }
            verification_base(new_info);

            if (new_info == "Porto") {
                v = Porto.getClients();
            } else if (new_info == "Lisboa") {
                v = Lisboa.getClients();
            } else if (new_info == "Faro") {
                v = Faro.getClients();
            }

            cout << "County: ";
            getline(cin, new_info3);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info3);
            }
            verification_all_letters(new_info3);

            cout << "Address: ";
            getline(cin, new_info2);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            formatting_string(new_info2);

            cout << endl << endl << "-----------------------------------------------" << endl;
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info3, new_info);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    system("cls");
                    cout << b.getMsg() << endl << endl;
                    cout << "1. Return to Main Menu." << endl;
                    cout << "2. Return to Account Management." << endl;
                    menu_int_options(op, 1, 2);
                    return op;
                }
                cl.setName(name);
                cl.setNif(nif);
                cl.setBase(new_info);
                cl.setAddress(new_info2);
                cl.setCounty(new_info3);
                if (base == "Porto") {
                    if (new_info == "Porto") {
                        Porto.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Porto.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Porto.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    if (new_info == "Porto") {
                        Lisboa.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Lisboa.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Lisboa.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    if (new_info == "Porto") {
                        Faro.removeClient(i);
                        Porto.addClient(cl);
                    } else if (new_info == "Lisboa") {
                        Faro.removeClient(i);
                        Lisboa.addClient(cl);
                    } else if (new_info == "Faro") {
                        Faro.removeClient(i);
                        Faro.addClient(cl);
                    }
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
            } else {//caso de nao se confirmar a mudança
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
            }
        }
        else if (option == 2) {
            cout << "County: ";
            getline(cin, new_info2);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info2);
            }
            verification_all_letters(new_info2);

            cout << "Address: ";
            getline(cin, new_info);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, new_info);
            }

            cout << endl << endl << "-----------------------------------------------" << endl;
            if (confirm_modifications("modify", "client")) {
                try {
                    out_of_area(v, new_info2,base);//caso o cliente nao resida no concelho da base ou nos concelhos fronteira tambem é rejeitado
                }
                catch (OutOfArea &b) {
                    system("cls");
                    cout << b.getMsg() << endl;
                    cout << "1. Return to Main Menu." << endl;
                    cout << "2. Return to Account Management." << endl;
                    menu_int_options(option, 1, 2);
                    return option;
                }
                cl.setBase(base);
                cl.setName(name);
                cl.setNif(nif);
                cl.setAddress(new_info);
                cl.setCounty(new_info2);
                if (base == "Porto") {
                    Porto.removeClient(i);
                    Porto.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Lisboa") {
                    Lisboa.removeClient(i);
                    Lisboa.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }
                else if (base == "Faro") {
                    Faro.removeClient(i);
                    Faro.addClient(cl);
                    system("cls");
                    cout << "Client was successfully modified!" << endl << endl;
                }

            }
            else {//caso de nao se confirmar a mudança
                system("cls");
                cout << "Operation was canceled!" << endl << endl;
                cout << "1. Return to Main Menu." << endl;
                cout << "2. Return to Account Management." << endl;
                menu_int_options(op, 1, 2);
                cin.ignore(1000, '\n');
                return op;
            }
        }

        //voltar para o menu
        cout << "1. Return to Main Menu." << endl;
        cout << "2. Return to Account Management." << endl;
        menu_int_options(op, 1, 2);
        return op;
    }

    cout << "1. Return to Main Menu." << endl;
    cout << "2. Return to Account Management." << endl;
    menu_int_options(op, 1, 2);
    return op;
}

int removeAccount(Base &Porto,Base &Lisboa,Base &Faro){
    string base, auxiliar;
    int i,option;
    vector <Client> v;

    system("cls");
    cout << "---------------- REMOVE ACCOUNT ---------------- " << endl;

    cout << "What's your base? ";
    getline(cin, base);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, base);
    }
    verification_base(base);

    if (base == "Porto") {
        v = Porto.getClients();
    }
    else if (base == "Lisboa") {
        v = Lisboa.getClients();
    }
    else if (base == "Faro") {
        v = Faro.getClients();
    }

    cout << "What's your nif? ";
    getline(cin, auxiliar);
    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, auxiliar);
    }
    verification_nif(auxiliar);
    i = int_sequential_search_c(v, stoi(auxiliar));


    if (i == -1) {
        cout << "The client inserted does not exist. Try again:"<<endl;//dar opçao de tentar outra
        while (i == -1) {
            cout << "What's your nif? ";
            getline(cin, auxiliar);
            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, auxiliar);
            }
            verification_nif(auxiliar);
            i = int_sequential_search_c(v, stoi(auxiliar));
        }
    }
    system("cls");
    cout << v[i]<<endl;
    cout << endl << endl << "-----------------------------------------------" << endl;
    if(confirm_modifications("remove","account")){
        if (base == "Porto") {
            Porto.removeClient(i);
        }
        else if (base == "Lisboa") {
            Lisboa.removeClient(i);
        }
        else if (base == "Faro") {
            Faro.removeClient(i);

        }
        system("cls");
        cout << "Client was successfully removed!" << endl << endl;
    }
    else {//caso de nao se confirmar a remoçao
        system("cls");
        cout << "Operation was canceled! " << endl << endl;
    }

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Account Management. " << endl;
    menu_int_options(option,1,2);
    return option;
}

//Funcoes relativas às excecoes

void black_list(const Base &base, int nif) {
    vector<Client> black_list = base.getBlackList();
    if (int_sequential_search_c(black_list, nif) == -1) {
        return ;
    }
    throw (BlackList());

}

void out_of_area(const vector<Client> &v,string county,string b) {
    if(b=="Porto"){
        if(find(nearby_Porto.begin(),nearby_Porto.end(), county) == nearby_Porto.end()){
            throw(OutOfArea());
        }
    }
    else if (b=="Lisboa"){
        if (find(nearby_Lisboa.begin(),nearby_Lisboa.end(), county) == nearby_Lisboa.end()) {
            throw(OutOfArea());
        }
    }
    else if (b=="Faro"){
        if (find(nearby_Faro.begin(),nearby_Faro.end(), county) == nearby_Faro.end()) {
            throw(OutOfArea());
        }
    }
    return;
}

void client_already_exists(string nif, const Base &p, const Base &l, const Base &f){
    vector<Client>::const_iterator p_it = p.getClients().begin();
    vector <Client>::const_iterator l_it = l.getClients().begin();
    vector <Client>::const_iterator f_it = f.getClients().begin();
    while(p_it != p.getClients().end()){
        if (stoi(nif) == (*p_it).getNif()){
            throw ClientAlreadyExists(nif);
        }
        advance(p_it, 1);
    }
    while(l_it != l.getClients().end()){
        if (stoi(nif) == (*l_it).getNif()){
            throw ClientAlreadyExists(nif);
        }
        advance(l_it, 1);
    }

    while(f_it != f.getClients().end()){
        if (stoi(nif) == (*f_it).getNif()){
            throw ClientAlreadyExists(nif);
        }
        advance(f_it, 1);
    }
    return;
}

int string_sequential_search_c(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}

int int_sequential_search_c(const vector<Client> &v, int x) {//retorna o indice do vetor onde se encontra x
    for (unsigned int i = 0; i < v.size(); i++)
        if (v[i].getNif() == x)
            return i; // encontrou
    return -1; // não encontrou
}
