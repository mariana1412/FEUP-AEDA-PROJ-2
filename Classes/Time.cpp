#include "Time.h"
Time::Time(){
    this-> hour=0;
    this-> minutes=0;
    this-> day=0;
    this-> month=0;
    this-> year=0;
}

Time::Time(int hour, int minutes, int day, int month, int year){
    this-> hour=hour;
    this-> minutes=minutes;
    this-> day=day;
    this-> month=month;
    this-> year=year;
}
int Time::getHour() const{
    return hour;
}
int Time::getMinutes() const{
    return minutes;
}
int Time::getDay() const{
    return day;
}
int Time::getMonth() const{
    return month;
}
int Time::getYear() const{
    return year;
}

void Time::setHour(int hour){
    this->hour=hour;
}

void Time::setMinutes(int minutes){
    this->minutes = minutes;
}

void Time::setDay(int day){
    this->day = day;
}

void Time::setMonth(int month){
    this->month = month;
}

void Time::setYear(int year) {
    this->year = year;
}

bool Time::isValid() {// verifica se a data é valida,ou seja, nao tem um n maior de mês do que o possivel e o mesmo com os dias
    if (month > 12 || day > numberOfDays(month, year) || hour > 23 || minutes > 59) {
        return false;
    }
    return true;
}
bool Time::operator==(const Time& date) { // verifica se duas datas sao iguais

    return (date.day == day && date.month == month && date.year == year && date.hour == hour && date.minutes == minutes && date.hour == hour && date.minutes == minutes);
}

bool Time::operator>(const Time& date) {// verifica se a data é depois da outra
    return (date.year < year || (date.year == year && date.month < month) || (date.year == year && date.month == month && date.day < day) || (date.year == year && date.month == month && date.day == day && date.hour < hour) || (date.year == year && date.month == month && date.day == day && date.hour == hour && date.minutes < minutes));
}

ostream &operator <<(ostream &os, const Time t){
    os << setw(2) << setfill('0') << to_string(t.getDay()) << "/" << setw(2) << setfill('0') << to_string(t.getMonth()) << "/" << setw(4) << setfill('0') << to_string(t.getYear());
    return os;
}

//--------------------------------------------------------------------------------------------------------------------------------

bool leap_year(int year) { // verifica se é um ano bissexto ou nao
    if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) {//forma de determinar se um ano é bissexto ou nao
        return true;
    }
    return false;
}

int numberOfDays(int month, int year) {// retorna o n de dias que o respetivo mês tem
    switch (month) {
        case 2:
        {
            if (leap_year(year)) {//fevereiro
                return 29;
            }
            else {
                return 28;
            }
        }
        case 4:
            return 30;

        case 6:
            return 30;

        case 9:
            return 30;

        case 11:
            return 30;

        default:
            return 31;
    }
}

