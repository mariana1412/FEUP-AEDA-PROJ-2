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
    Time birthdate;/**< data de nascimento da pessoa*/
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
     * @param birthdate - data de aniversário da pessoa
*/
    Person(string base, string name, int nif, Time birthdate);

    /**
    * @brief Permite obter a data de nascimento da pessoa
     * @return Retorna a data de nascimento da pessoa
    */
    Time getBirthdate() const;

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
    * @brief Permite definir a data de nascimento do funcionário
    * @param birthdate - data de nascimento do funcionário
    */
    void setBirthdate(Time birthdate);
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
     * @param birthdate - data de aniversário do cliente
*/
    Client(string base, string name, int nif, string address, bool black, string county, Time birthdate);
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
    float income;/**< salário do funcionário*/
    bool former;/**< true se for um antigo funcionário; falso se for um funcionário atual*/
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
     * @param former - funcionário antigo ou não
*/
    Employee(string base, string name, int nif, Time birthdate, float income, bool former);

    /**
    * @brief Permite obter o salário do funcionário
     * @return Retorna o salário do funcionário
    */
    float getIncome() const;

    /**
     * @brief Permite saber se o funcionário é antigo ou atual
     * @return retorna true se o funcionário for antigo; falso caso contrário
     */
    bool getFormer() const;

    /**
    * @brief Permite definir o salário do funcionário
    * @param income - salário do funcionário
    */
    void setIncome(float income);

    /**
     * @brief Permite definir se o funcionário é antigo ou atual
     * @param f - funcionário antigo ou atual
     */
    void setFormer(bool f);

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
     * @param former - funcionário antigo ou atual
    */
    Admin(string base, string name, int nif, Time birthdate, float income, string task, bool former);
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
    Vehicle vehicle;/**< veiculo do entregador*/
    vector<Delivery> background;/**< historial de entregas do entregador*/
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
     * @param former - funcionário antigo ou atual
*/
    Deliverer(string base, string name, int nif, Time birthdate, float income, Vehicle vehicle, vector<Delivery> background, bool former);
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

    /**
     * @brief Permite adicionar uma encomenda a um veiculo
     */
    void addDeliveryToVehicle();

};
/**
 * Tecnico
 */
class Tec:public Person{
private:
    int time_to_available;/**< numero de minutos ate o tecnico estar disponivel*/
    int number_of_maintenances;/**< numero de manutençoes efetuadas pelo tecnico*/
public:

    /**
* @brief Construtor por default da classe Tec
*/
    Tec(){};
    /**
* @brief Construtor da classe Tec
* @param base - base a que o tecnico pertence
     * @param name -nome do tecnico
     * @param birthdate - data de aniversario do tecnico
     * @param nif - NIF do tecnico
* @param m - numero de minutos ate o tecnico estar disponivel
* @param n - numero de manutençoes efetuadas pelo tecnico
*/

    Tec(string base,string name,Time birthdate,int nif, int m, int n);

    /**
     * @brief Permite definir o numero de minutos ate o tecnico estar disponivel
     * @param m - numero de minutos ate o tecnico estar dispnonivel
     */
    void setTimeToAvailable(int m);
    /**
  * @brief Permite definir o numero de manutençoes efetuadas pelo tecnico
  * @param n - numero de manutençoes efetuadas pelo tecnico
  */
    void setNumberOfMaintenances(int n);

    /**
  * @brief Permite obter o numero de minutos ate o tecnico estar disponivel
  * @return Retorna o numero de minutos ate o tecnico estar disponivel
  */
    int getTimeToAvailable() const;
    /**
  * @brief Permite obter  o numero de manutençoes efetuadas pelo tecnico
  * @return Retorna o numero de manutençoes efetuadas pelo tecnico
  */
    int getNumberOfMaintenances() const;

/**
 * @brief Adiciona um ao numero de manutenções efetuadas pelo tecnico
 */
    void addMaintenance();
    /**
     * @brief Operador < para comparar Técnicos
     * @param tec1 - um outro tecnico para comparar com o tecnico em questao
     * @return Retorna verdadeiro se o tecnico em questao tiver menos horas ate estar disponivel, no caso do numero de horas ate estar disponivel ser igual retorna verdadeiro se o tecnico em questao tiver maior numero de manutençoes efetuadas , caso contrário retorna falso
     */
    bool operator<(const Tec & tec1) const;
/**
 * @brief Operador == para comparar Tecnicos
 * @param tec1 - um outro tecnico para comparar com o tecnico em questão
 * @return Retorna verdadeiro se os tecnicos forem iguais, caso contrário retorna falso
 */
    bool operator==(const Tec & tec1) const;
/**
 * @brief Permite mostrar no ecrã o tecnico de forma formatada
 * @param os - ostream para onde é enviada a mensagem formatada
 * @param tecnico  - tecnico que pretendemos mostrat no ecrã
 */
    friend ostream & operator<<(ostream &os, const Tec & tecnico);
};



#endif //UGH_EATS_PERSON_H
