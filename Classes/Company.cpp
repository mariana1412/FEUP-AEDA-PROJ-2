#include "Company.h"


Company::Company(string Boss, int boss_nif, Base Porto, Base Lisboa, Base Faro){
    boss = "Rui Teixeira";
    this->boss_nif = boss_nif;
    this->Porto = Porto;
    this->Lisboa = Lisboa;
    this->Faro = Faro;
}
void Company::setBoss(string boss){
    this->boss = boss;
}

string Company::getBoss()const{
    return boss;
}
void Company ::setBossNif(int nif) {
    this->boss_nif=nif;
}
int Company::getBossNif() const {
    return boss_nif;
}