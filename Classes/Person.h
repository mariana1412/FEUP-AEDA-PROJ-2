#ifndef UGH_EATS_PERSON_H
#define UGH_EATS_PERSON_H

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Order.h"

using namespace std;
/**
 * Pessoa
 */
class Person{
private:
    string name;/**< nome da pessoa*/
    int nif;/**<NIF da pessoa*/
    string base;/**<base a que a pessoa pertence*/
public:
    /**
* @brief Construtor por default da classe Person
*/
    Person(){};
    /**
* @brief Construtor da classe Person
     * @param base - base a que a pessoa pertence
     * @param name - nome da pessoa
     * @param nif- NIF da pessoa
*/
    Person(string base, string name, int nif);
    /**
* @brief Permite obter a base da pessoa
     * @return Retorna a base da pessoa
*/
    string getBase() const;
    /**
* @brief Permite obter o nome da pessoa
 * @return Retorna o nome da pessoa
*/
    string getName() const;
    /**
* @brief Permite obter o NIF da pessoa
 * @return Retorna o NIF da pessoa
*/
    int getNif() const;
    /**
* @brief Permite definir o nome da pessoa
 * @param name - nome da pessoa
*/
    void setName(string name);
    /**
* @brief Permite definir o NIF da pessoa
* @param nif - NIF da pessoa
*/
    void setNif(int nif);
    /**
* @brief Permite definir a base da pessoa
* @param base - base da pessoa
*/
    void setBase(string base);

};
/**
 * Cliente
 */

class Client:public Person{
private:
    string address;/**< morada do cliente*/
    bool black;/**< pertence ou nao pertence à blacklist da empresa*/
    string county;/**< concelho do cliente*/
public:
    /**
* @brief Construtor por default da classe Client
*/
    Client(){};
    /**
* @brief Construtor da classe Client
     * @param base - base do cliente
     * @param name - nome do cliente
     * @param nif - NIF do cliente
     * @param address - morada do cliente
     * @param black - verdadeiro se o cliente pertencer à blacklist da empresa, falso caso contrário
     * @param county - concelho do cliente
*/
    Client(string base, string name, int nif, string address, bool black, string county);
    /**
* @brief Permite obter se pertence ou não à blacklist da empresa
     * @return Retorna verdadeiro se pertencer à blacklist da empresa, falso caso contrário
*/
    bool getBlack() const;
    /**
* @brief Permite obter a morda do cliente
     * @return Retorna a morada do cliente
*/
    string getAddress() const;
    /**
* @brief Permite obter o concelho do cliente
 * @return Retorna o concelho do cliente
*/
    string getCounty() const;
    /**
* @brief Permite definir a morda do cliente
 * @param address - morada do cliente
*/

    void setAddress(string address);
    /**
* @brief Permite definir se pertence ou não à blacklist da empresa
 * @param black - verdadeiro se pertencer à blacklist da empresa, falso caso contrário
*/
    void setBlack(bool black);
    /**
* @brief Permite definir o concelho do cliente
* @param county - concelho do cliente
*/
    void setCounty(string county);
    /**
* @brief Permite mostrar no ecrã o cliente de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param cl - cliente que pretendemos mostrar no ecrã
*/
    friend ostream & operator<<(ostream &os, const Client cl);
};
/**
 * Funcionário
 */

class Employee: public Person{
private:
    Time birthdate;/**< data de nascimento do funcionário*/
    float income;/**< salário do funcionário*/
public:
    /**
* @brief Construtor por default da classe Employee
*/
    Employee(){};
    /**
* @brief Destrutor da classe
*/
    virtual ~Employee(){};
    /**
* @brief Construtor da classe Employee
     * @param base - base do funcionário
     * @param name - nome do funcionário
     * @param nif - NIF do funcionário
     * @param birthdate - data de nascimento do funcionário
     * @param income - salário do funcionário
*/
    Employee(string base, string name, int nif, Time birthdate, float income);
    /**
* @brief Permite obter a data de nascimento do funcionário
     * @return Retorna a data de nascimento do funcionário
*/
    Time getBirthdate() const;
    /**
* @brief Permite obter o salário do funcionário
 * @return Retorna o salário do funcionário
*/
    float getIncome() const;
    /**
* @brief Permite definir a data de nascimento do funcionário
 * @param birthdate - data de nascimento do funcionário
*/
    void setBirthdate(Time birthdate);
    /**
* @brief Permite definir o salário do funcionário
* @param income - salário do funcionário
*/
    void setIncome(float income);
};

/**
 * Administrador
 */
class Admin: public Employee{
private:
    string task;/**< função do administrador*/
public:
    /**
* @brief Construtor por default da classe Admin
*/
    Admin(){};
    /**
* @brief Construtor da classe Admin
     * @param base - base do administrador
     * @param name - nome do administrador
     * @param nif - NIF do administrador
     * @param birthdate - data de nascimento do administrador
     * @param income - salário do administrador
     * @param task - função do administrador
*/
    Admin(string base, string name, int nif, Time birthdate, float income, string task);
    /**
* @brief Permite obter a função do administrador
     * @return Retorna a função do administrador
*/
    string getTask() const;
    /**
* @brief Permite definir a função do administrador
 * @param task - função do administrador
*/
    void setTask(string task);
    /**
* @brief Permite mostrar no ecrã o administrador de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param a - administrador que pretendemos mostrar no ecrã
*/
    friend ostream & operator<<(ostream &os, const Admin *a);
};
/**
 * Entregador
 */
class Deliverer: public Employee{
private:
    Vehicle vehicle;
    vector<Delivery> background;
public:
    /**
* @brief Construtor por default da classe Deliverer
*/
    Deliverer() {};
    /**
* @brief Construtor da classe Deliverer
     * @param base - base do entregador
     * @param name - nome do entregador
     * @param nif - NIF do entregador
     * @param birthdate - data de nascimento do entregador
     * @param income - salário do entregador
     * @param vehicle - veículo do entregador
     * @param background - historial de entregas do entregador
*/
    Deliverer(string base, string name, int nif, Time birthdate, float income, Vehicle vehicle, vector<Delivery> background);
    /**
* @brief Permite obter o veículo do entregador
     * @return Retorna o veículo do entregador
*/
    Vehicle getVehicle() const;
    /**
* @brief Permite obter o historial de entregas do entregador
  * @return Retorna o historial de entregas do entregador
*/
    vector<Delivery> getBackground() const;
    /**
* @brief Permite definir o veículo do entregador
  * @param vehicle - veículo do entregador
*/
    void setVehicle(Vehicle vehicle);
    /**
* @brief Permite definir o historial de entregas do entregador
* @param background - historial de entregas do entregador
*/
    void setBackground(vector<Delivery> background);
    /**
* @brief Permite mostrar no ecrã o entregador de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param d - entregador que pretendemos mostrar no ecrã
*/
    friend ostream & operator<<(ostream &os, const Deliverer *d);
/**
     * @brief Permite adicionar uma encomenda a um deliverer
    * @param delivery - encomenda a adicionar
     */
    void addDelivery(Delivery delivery);

};




#endif //UGH_EATS_PERSON_H
