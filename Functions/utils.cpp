#include "utils.h"

bool isNumber(string n){

    for(int i = 0; i<n.size(); i++){
        if(!isAlgarism(n[i])) return false;
    }

    return true;
}

bool isAlgarism(char n){
    string numbers = "0123456789";
    n = toupper(n);

    if (numbers.find(n) != string::npos) {
        return true;
    }
    return false;
}

bool isLetter(char a) {
    string alphabet = "abcdefghijklmnopqrstuvwxyzãáàâçéêíõóôúüÃÁÀÂÇÉÊÍÕÓÔÚÜ";
    a = tolower(a);

    if (alphabet.find(a) != string::npos) {
        return true;
    }

    return false;
}

void trim(string &str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
}

void formatting_string(string &str) { //formatar a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra

    str = remove_extra_whitespaces(str);

    transform(str.begin(), str.end(), str.begin(), ::tolower);//toda a string é colocada em minusculas

    str = " " + str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ' && isLetter(str[i + 1])) {
            str[i + 1] = toupper(str[i + 1]);// coloca a primeira letra de cada palavra a maiuscula
        }
    }
    trim(str);
}

void remove_all_whitespaces(string &aux){
    aux.erase(remove(aux.begin(), aux.end(), ' '), aux.end());
}

string remove_extra_whitespaces(string aux) {
    string auxiliar;
    bool spacefound = false;
    trim(aux);

    for (int i = 0; i < aux.size(); i++) {
        if (aux[i] == ' ' && !spacefound) {
            auxiliar += ' ';
            spacefound = true;
        }
        else if (aux[i] != ' ') {
            auxiliar += aux[i];
            spacefound = false;
        }
    }

    return auxiliar;
}

bool confirm_modifications(string action, string str){

    string cancel;

    if (action == "create") {
        cout << endl << endl << "Are you sure you want to create a " << str << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }

    else if (action == "modify") {
        cout << endl << endl << "Are you sure you want to modify this " << str << " with this information? " << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }
    else if (action == "remove") {
        cout << endl << endl << "Are you sure you want to remove this " << str << "?" << endl
             << "Insert 'yes' to continue. " << endl << "Insert 'no' to cancel. " << endl << "Answer: ";
        cin >> cancel;
    }

    while (cin.fail()) {
        if (cin.eof()) {
            cin.clear();
            cout << "Invalid operation, please insert a valid one: ";
            cin >> cancel;
        }
    }

    formatting_string(cancel);

    while (cin.fail() || (cancel != "Yes" && cancel != "No")) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid operation, please insert a valid one: ";
        cin >> cancel;
        while (cin.fail()) {
            if (cin.eof()) {
                cin.clear();
                cout << "Invalid operation, please insert a valid one: ";
                cin >> cancel;
            }
        }

        formatting_string(cancel);
    }


    if(cancel == "Yes") return true;

    return false;
}

void stringToHours(Time &d, string str){
    string delimiter = ":";
    vector<string> data;
    vector<int> data_clean;
    Time result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        trim(i);
        data_clean.push_back(stoi(i));
    }
    d.setHour(data_clean.at(0));
    d.setMinutes(data_clean.at(1));
}
void verification_hour(string &aux){
    bool isValid = false;

    while (!isValid || aux == "") {
        if (aux != "") {
            remove_all_whitespaces(aux);
            int del1 = aux.find_first_of(':');
            if(aux.size() !=5  || count(aux.begin(), aux.end(), ':') != 1 || del1 !=2 || !(isNumber(aux.substr(0, 2)) && isNumber(aux.substr(3, 2)) )) {
                isValid = false;
            }
            else if (stoi(aux.substr(0,2))>24 || stoi(aux.substr(0,2))<0||stoi(aux.substr(3,2))>60 ||stoi(aux.substr(0,2))<0){
                isValid = false;
            }
            else {
                isValid = true;
            }
        }
        if (!isValid) {
            cout << "Invalid hour (format: hh:mm). Please insert a valid one: ";
            getline(cin, aux);
            if (cin.fail() && cin.eof()) {
                cin.clear();
                continue;
            }
        }
    }

}


