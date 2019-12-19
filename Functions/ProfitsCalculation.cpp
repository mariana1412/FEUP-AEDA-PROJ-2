#include "ProfitsCalculation.h"

int ProfitsByBase(Base p, Base l, Base f){
    float profit=0;
    int option,op;
    Base b;
    vector<Delivery> v;

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY BASE ----------------" << endl << endl;


    cout << "From which base do you want to know the profit?" << endl;
    cout << "  1. Porto \t 2. Lisboa \t 3. Faro " << endl;
    menu_int_options(op, 1,3);
    cin.ignore(1000, '\n');

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY BASE ----------------" << endl << endl;

    switch (op){
        case 1:
            for(int i = 0; i < p.getDeliveries().size(); i++){
                profit += p.getDeliveries()[i].getFinalPrice();
            }
            cout << "The profit of Porto is "<< profit<<" euros." << endl;
            break;
        case 2:
            for(int i = 0; i < l.getDeliveries().size(); i++){
                profit += l.getDeliveries()[i].getFinalPrice();
            }
            cout << "The profit of Lisboa is "<< profit<<" euros." << endl;
            break;
        case 3:
            for(int i = 0; i < f.getDeliveries().size(); i++){
                profit += f.getDeliveries()[i].getFinalPrice();
            }
            cout << "The profit of Faro is "<< profit<<" euros." << endl;
            break;
    }


    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int ProfitsByRestaurant(Base p, Base l , Base f){
    int option,op;
    string base,aux;
    Restaurant restaurant;
    bool isValid;
    float profit;
    Base b;

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY RESTAURANT ----------------" << endl << endl;


    cout << "From which base is the restaurant you want to know the profit?"<<endl;
    cout << "  1. Porto \t 2. Lisboa \t 3. Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore(1000,'\n');
    switch (op) {
        case 1:
            base = "Porto";
            break;
        case 2:
            base = "Lisboa";
            break;
        case 3:
            base = "Faro";
            break;
    }

    cout << "Insert the name of the restaurant: ";
    getline(cin, aux);

    while(cin.fail() && cin.eof()){
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    formatting_string(aux);
    do{
        try {
            if (base == "Porto") restaurant = p.searchRestaurant(aux);
            else if (base == "Lisboa") restaurant = l.searchRestaurant(aux);
            else if(base == "Faro") restaurant = f.searchRestaurant(aux);
            isValid = true;
        }
        catch (RestaurantNotFound &msg){
            cout << endl << endl << "ATENTION: Restaurant '" << msg.getName() << "' does not exist." << endl << endl;
            isValid = false;
            cout << "Try again. Insert the name of the restaurant: ";
            getline(cin, aux);

            while(cin.fail() && cin.eof()){
                cin.clear();
                cout << "Invalid character. Please insert a valid input: ";
                getline(cin, aux);
            }
            formatting_string(aux);
        }
    } while(!isValid);

    profit = restaurant.getRevenue();

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY RESTAURANT ----------------" << endl << endl;

    cout << restaurant << endl;
    cout << endl << "------------------------------------------------------------------" << endl << endl;
    cout << "The profit of this restaurant is " << profit << " euros." << endl;


    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int ProfitsByClient(Base p, Base l, Base f){
    int op,option,i;
    Base b;
    string aux;
    float profit=0;

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY CLIENT ----------------" << endl << endl;

    cout << "From which base is the client you want to know the outlay?"<<endl;
    cout << "  1. Porto \t 2. Lisboa \t 3. Faro "<<endl;
    menu_int_options(op, 1,3);
    cin.ignore (1000, '\n');
    switch (op){
        case 1:
            b= p;
            break;
        case 2:
            b=l;
            break;
        case 3:
            b=f;
            break;
    }

    cout << "What is the name of the client you want to know the outlay? ";
    getline(cin, aux);
    while (cin.fail() && cin.eof()) {
        cin.clear();
        cout << "Invalid character. Please insert a valid input: ";
        getline(cin, aux);
    }
    verification_all_letters(aux);
    i = string_sequential_search_aux(b.getClients(), aux);
    if (i == -1) {
        cout << "The client inserted does not exist. Try again: "<<endl;//dar opçao de tentar outra
        while (i == -1) {
            cout << "What is the name of the client you want to know the outlay? ";
            getline(cin, aux);
            while (cin.fail() && cin.eof()) {
                cin.clear();
                cout << "Invalid character. Please insert a valid input:";
                getline(cin, aux);
            }
            verification_all_letters(aux);
            i = string_sequential_search_aux(b.getClients(), aux);
        }
    }
    int nif = b.getClients()[i].getNif();
    vector<Delivery>:: const_iterator it_d = b.getDeliveries().begin();
    for (it_d; it_d != b.getDeliveries().end(); it_d++){
        if((*it_d).getNif()==nif){
            profit += (*it_d).getFinalPrice();
        }

    }

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY CLIENT ----------------" << endl << endl;

    cout << b.getClients().at(i) << endl;
    cout << endl << "---------------------------------------------------------------" << endl << endl;
    cout << "The profit of this client is "<< profit << " euros."<<endl;

    cout << endl << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int ProfitByTimeInterval(Base p, Base l , Base f){
    int option,op;
    string s;
    Time d1,d2;
    float profit = 0;

    system("cls");
    cout << endl << "---------------- PROFIT CALCULATION BY TIME INTERVAL ----------------" << endl << endl;

    cout << "Inferior limit of the interval.";
    cout << "Date (in the dd/mm/yyy format): ";
    getline(cin, s),
    d1=verification_date(s);
    cout << "Hour (in the hh:mm format ): ";
    getline(cin,s);
    verification_hour(s);
    stringToHours(d1,s);
    cout << "Superior limit of the interval.";
    cout << "Date (in the dd/mm/yyy format): ";
    getline(cin, s),
    d2=verification_date(s);
    cout << "Hour (in the hh:mm format ): ";
    getline(cin,s);
    verification_hour(s);
    stringToHours(d2,s);
    while(d1>d2){
        cout << "This interval is not valid. Please, try again:"<<endl;
        cout << "Inferior limit of the interval.";
        cout << "Date (format: dd/mm/yyy): ";
        getline(cin, s),
                d1=verification_date(s);
        cout << "Hour (format: hh:mm ): ";
        getline(cin,s);
        verification_hour(s);
        stringToHours(d1,s);
        cout << "Superior limit of the interval.";
        cout << "Date (format: dd/mm/yyy): ";
        getline(cin, s),
                d2=verification_date(s);
        cout << "Hour (format: hh:mm ): ";
        getline(cin,s);
        verification_hour(s);
        stringToHours(d2,s);
    }
    cout << endl << "From which base do you want to know the profit in this interval?"<<endl;
    cout << "  1. Porto \t 2. Lisboa \t 3. Faro "<<endl;
    menu_int_options(op, 1,3);
    switch (op){
        case 1:
            for(int i = 0; i < p.getDeliveries().size(); i++){
                if((p.getDeliveries()[i].getTime()>d1) &&(d2>p.getDeliveries()[i].getTime())){
                    profit += p.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }

            }
            break;
        case 2:
            for(int i = 0; i < l.getDeliveries().size(); i++){
                if((l.getDeliveries()[i].getTime()>d1) &&(d2>l.getDeliveries()[i].getTime())){
                    profit += l.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }
            }
            break;
        case 3:
            for(int i = 0; i < f.getDeliveries().size(); i++){
                if((f.getDeliveries()[i].getTime()>d1) &&(d2>f.getDeliveries()[i].getTime())){
                    profit += f.getDeliveries()[i].getFinalPrice();
                }
                else{
                    continue;
                }
            }
            break;
    }

    cout << endl << "---------------------------------------------------------------------" << endl << endl;
    cout << "The profit in general in this time interval is "<< profit << " euros." <<endl;

    cout << "1. Return to Main Menu. " << endl;
    cout << "2. Return to Profit Calculation. " << endl;
    menu_int_options(option,1,2);
    return option;
}

int string_sequential_search_aux(const vector<Client> &v, string x) {//retorna o indice do vetor onde se encontra x
    for ( unsigned int i = 0; i < v.size(); i++)
        if (v[i].getName() == x)
            return i; // encontrou
    return -1; // não encontrou
}