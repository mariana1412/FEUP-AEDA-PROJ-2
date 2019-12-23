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



pair<int,int> subtractTimes(Time t1, Time t2){//assumimos que no máximo a encomenda chega um mês depois de ter sido feito, sendo que tal ja nao é realista
    int hour =0;
    int minutes =0;
    if((t1.getMonth() == t2.getMonth()) && (t1.getYear() ==t2.getYear())){
        if((t1.getDay() ==t2.getDay()) ){//mesmo dia
            if(t1.getHour() == t2.getHour()){//mesma hora
                hour =0;
                minutes = t2.getMinutes() - t1.getMinutes();
                return make_pair(hour, minutes);
            }
            else{//nao sao a mesma hora
                if(t1.getMinutes()>t2.getMinutes()){
                    hour= (t2.getHour() -t1.getHour())-1;
                    minutes = (60-t1.getMinutes()) + t2.getMinutes();
                    return make_pair(hour, minutes);
                }
                else if(t1.getMinutes()==t2.getMinutes()){
                    hour = t2.getHour() -t1.getHour();
                    minutes =0;
                    return make_pair(hour, minutes);
                }
                else{
                    hour = t2.getHour() -t1.getHour();
                    minutes = (60-t1.getMinutes()) + t2.getMinutes();
                    return make_pair(hour, minutes);
                }
            }
        }
        else{//mesmo mês, mesmo ano, dias diferentes
           if(t1.getHour() == t2.getHour()){//mesma hora dias diferentes
               if(t1.getMinutes() == t2.getMinutes()){ // dias inteiros depois
                   hour=24*(t2.getDay()-t1.getDay());
                   minutes =0;
                   return make_pair(hour, minutes);
               }
               else if(t1.getMinutes()>t2.getMinutes()){//
                   hour = 24*(t2.getDay() -t1.getDay())-1;
                   minutes = (60-t1.getMinutes())+t2.getMinutes();
                   return make_pair(hour, minutes);
               }
               else{
                   hour = 24*(t2.getDay() -t1.getDay());
                   minutes = (60-t1.getMinutes())+t2.getMinutes();
                   return make_pair(hour, minutes);
               }
           }

        }

    }
    else if((t1.getYear()==t2.getYear()) && ((t1.getMonth()+1)==t2.getMonth())){
        if(t1.getDay()==t2.getDay()){//mesmo dia, mês seguinte
            int aux= numberOfDays(t1.getMonth(),t1.getYear());
            if(t1.getHour() == t2.getHour()){ //mesma hora
                hour = 24 * aux;
                minutes = t2.getMinutes() - t1.getMinutes();
                return make_pair(hour, minutes);
            }
            else if(t1.getHour()>t2.getHour()){
                hour = 24 * (aux-1);
                minutes = t2.getMinutes() - t1.getMinutes();
                return make_pair(hour, minutes);
            }
        }

        else if(t1.getDay()>t2.getDay()){//menos de um mês depois
            int aux= numberOfDays(t1.getMonth(),t1.getYear());
            int days= aux-t1.getDay() +t2.getDay();
            if(t1.getHour() == t2.getHour()){ //mesma hora
                hour = 24 * days;
                minutes = t2.getMinutes() - t1.getMinutes();
                return make_pair(hour, minutes);
            }
            else if(t1.getHour()>t2.getHour()){
                hour = 24 * (days-1);
                minutes = t2.getMinutes() - t1.getMinutes();
                return make_pair(hour, minutes);
            }


        }
    }
    else if(t1.getYear() != t2.getYear()){
        if((t2.getMonth() == 1) && (t1.getMonth() == 12)){
            if(t1.getDay()==t2.getDay()){ //exatamente um mês depois
                if(t1.getHour() == t2.getHour()){//mesma hora
                    hour =0;
                    minutes = t2.getMinutes() - t1.getMinutes();
                    return make_pair(hour, minutes);
                }
                else{//nao sao a mesma hora
                    if(t1.getMinutes()>t2.getMinutes()){
                        hour= (t2.getHour() -t1.getHour())-1;
                        minutes = (60-t1.getMinutes()) + t2.getMinutes();
                        return make_pair(hour, minutes);
                    }
                    else if(t1.getMinutes()==t2.getMinutes()){
                        hour = t2.getHour() -t1.getHour();
                        minutes =0;
                        return make_pair(hour, minutes);
                    }
                    else{
                        hour = t2.getHour() -t1.getHour();
                        minutes = (60-t1.getMinutes()) + t2.getMinutes();
                        return make_pair(hour, minutes);
                    }
                }
            }
            else if(t1.getDay()>t2.getDay()){//anos diferentes mas ainda menos de um mês depois
                int aux= numberOfDays(t1.getMonth(),t1.getYear());
                int days= aux-t1.getDay() +t2.getDay();
                if(t1.getHour() == t2.getHour()){ //mesma hora
                    hour = 24 * days;
                    minutes = t2.getMinutes() - t1.getMinutes();
                    return make_pair(hour, minutes);
                }
                else if(t1.getHour()>t2.getHour()){
                    hour = 24 * (days-1);
                    minutes = t2.getMinutes() - t1.getMinutes();
                    return make_pair(hour, minutes);
                }
            }
        }
    }
    cout<<"Something went wrong, it's not possible to receive the order more than one month after you order"<<endl;
    return make_pair (NULL, NULL);
}
pair<int,int>  updateMntTime (int m1,int h1,int m2, int h2 ){
    int minutes=0;
    int hours =h1;

    minutes = m1-m2;
    if(minutes >0){ // se esta atualizaçao fez passar mais uma hora apenas com os minutos
        minutes = 60-abs(minutes);
        hours--;
    }
    hours = hours - h2;

    return make_pair(hours, minutes);
}
