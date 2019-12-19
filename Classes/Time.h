#ifndef UGH_EATS_TIME_H
#define UGH_EATS_TIME_H

#pragma once

#include<iostream>
#include<iomanip>

using namespace std;
/**
 * Time
 */

class Time{
private:
    int hour;/**< horas */
    int minutes;/**< minutos*/
    int day;/**< dia*/
    int month;/**< mês*/
    int year;/**< ano*/
public:
    /**
 * @brief Construtor por default da classe Time
 */
    Time();
    /**
 * @brief Construtor da classe Base
     * @param hour -  hora
     * @param minutes - minutos
     * @param day -dia
     * @param month - mês
     * @param year - ano
 */
    Time(int hour, int minutes, int day, int month, int year);
    /**
 * @brief Permite obter a hora
     * @return Retorna a hora
 */
    int getHour() const;
    /**
 * @brief Permite obter os minutos
     * @return Retorna os minutos
 */
    int getMinutes() const;
    /**
* @brief Permite obter o dia
 * @return Retorna o dia
*/
    int getDay() const;
    /**
* @brief Permite obter o mês
* @return Retorna o mês
*/
    int getMonth() const;
    /**
* @brief Permite obter o ano
* @return Retorna o ano
*/
    int getYear() const;
    /**
* @brief Permite definir a hora
* @param hour - hora
*/
    void setHour(int hour);
    /**
* @brief Permite definir os minutos
* @param minutes - minutos
*/
    void setMinutes(int minutes);
    /**
* @brief Permite definir o dia
* @param day - dia
*/
    void setDay(int day);
    /**
* @brief Permite definir o mês
* @param month - mês
*/
    void setMonth(int month);
    /**
* @brief Permite definir o ano
* @param year - ano
*/
    void setYear(int year);
    /**
* @brief Permite saber se uma tempo é válido
* @return Retorna verdadeiro se for válido, caso contrário retorna falso
*/
    bool isValid();
    /**
* @brief Permite saber se um tempo é igual a outro
* @param date - um outro tempo para comparar ao tempo em questão
* @return Retorna verdadeiro se forem iguais, caso contrário retorna falso
*/
    bool operator==(const Time& date);

    /**
*    @brief Permite saber se um tempo é depois do outro
 * @param date - um outro tempo para comparar ao tempo em questão
*   @return Retorna verdadeiro se  for depois, caso contrário retorna falso
*/
    bool operator>(const Time& date);

    /**
* @brief Permite mostrar a data no ecrã no formato dd/mm/yyyy
 * @param os - ostream para onde é enviada a mensagem formatada
* @param t - tempo que pretendemos mostrar no ecrã
*/
    friend ostream &operator <<(ostream &os,const Time t);

};
/**
* @brief Permite verificar se um ano é bissexto ou não
 * @param year - ano em questão
*/
bool leap_year(int year);
/**
* @brief Permite calcular o número de dias de um mês de um certo ano
 * @param month - mês em questão
 * @param year - ano em questão
*/
int numberOfDays(int month, int year);


#endif //UGH_EATS_TIME_H
