#ifndef UGH_EATS_BASE_H
#define UGH_EATS_BASE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Person.h"


using namespace std;
/**
 * Base da empresa Ugh Eats
 */

class Base{
private:
    Location location; /**< Localização exata da base*/
    string manager;/**<Gerente da base*/
    int manager_nif; /**<NIF do gerente da base*/
    vector<Client> clients;/**Clientes da base*/
    vector<Employee*> employees;/**Funcionários da base*/
    vector<Client> blacklist;/**Lista negra da organização*/
    vector<Restaurant> restaurants;/**Conjunto de fornecedores da base*/
    vector<Delivery> deliveries;/**Encomendas feitas a esta base*/

public:
    /**
	 * @brief Construtor por default da classe Base
	 */
    Base(){};
    /**
	 * @brief Construtor da classe Base
	 * @param location - Localização exata da base
	 * @param manager - gerente da base
	 * @param blacklist- lista negra da base
	 */
    Base(Location location, string manager, int manager_nif, vector<Client>blacklist);
    /**
 * @brief Permite obter a localização exata da base
 * @return Retorna a localização exata da base
 */
    Location getLocation() const;
    /**
* @brief Permite obter o gerente da base
* @return Retorna o gerente da base
*/
    string getManager() const;
    /*
     * @brief Permite obter o NIF do gerente da base
     * @return Retorna o NIF do gerente da base
     */
    int getManagerNif() const;
    /**
* @brief Permite obter os clientes da base
* @return Retorna um vetor de clientes da base
*/
    vector<Client> getClients() const;
    /**
* @brief Permite obter os clientes na blacklist da base
* @return Retorna um vetor de clientes que se encontram na blacklist da base
*/
    vector<Client> getBlackList() const;
    /**
* @brief Permite obter os restaurantes da base
* @return Retorna um vetor com os restaurantes da base
*/
    vector<Restaurant> getRestaurants()const;
    /**
* @brief Permite obter os funcionários da base
* @return Retorna um vetor com os funcionários da base
*/
    vector<Employee*> getEmployees() const;
    /**
* @brief Permite obter as encomendas da base
* @return Retorna um vetor com as encomendas da base
*/
    vector<Delivery> getDeliveries() const;
    /**
* @brief Permite definir a localização exata da base
* @param location - localização exata da base
*/
    void setLocation(Location location);
    /**
* @brief Permite definir o gerente da base
* @param manager - gerente da base
*/
    void setManager(string manager);
    /*
     * @brief Permite definir o NIF do gerente da base
     * @param nif - NIF do gerente da base
     */
    void setManagerNif(int nif);
    /**
* @brief Permite definir os clientes da base
* @param clients - vetor de clientes da base
*/
    void setClients(vector<Client>clients);
    /**
* @brief Permite definir os clientes na blacklist da base
* @param blacklist - vetor de clientes na blackslist da base
*/
    void setBlacklist(vector<Client> blacklist);
    /**
* @brief Permite definir os restaurantes da base
* @param restaurants - vetor de restaurantes da base
*/
    void setRestaurants(vector<Restaurant> restaurants);
    /**
* @brief Permite adicionar um cliente a base
* @param client - cliente que pretendemos adicionar à base
*/
    void addClient(Client client);
    /**
* @brief Permite adicionar um restaurante à base
* @param restaurant - restaurante que pretendemos adicionar à base
*/
    void addRestaurant(Restaurant restaurant);
    /**
* @brief Permite adicionar um funcionário à base
* @param Employee* employees - funcionário que pretendemos adicionar à base
*/
    void addEmployee(Employee* employees);
    /**
* @brief Permite adicionar uma encomenda à base
* @param delivery - encomenda que pretendemos adicionar à base
*/
    void addDelivery(Delivery delivery);
    /**
* @brief Permite remover um restaurante da base, se este existir
* @param name - nome do restaurante que pretendemos remover
* @return Retorna true caso seja possivel remover o restaurante
*/
    bool removeRestaurant(string name);
    /**
* @brief Permite encontrar um restaurante no vetor de restaurantes da base
* @param name - nome do restaurante que pretendemos procurar
* @return Restaurante que pretendemos
*/
    Restaurant searchRestaurant(string name);
    /**
* @brief Permite descobrir o indice de um restaurante no vetor de restaurantes da base
* @param restaurant - restaurante cujo index pretendemos encontrar
* @return Index do restaurante no vetor de restaurantes da base
*/
    int getIndexrestaurant(Restaurant restaurant);
/**
 * @brief Permite modificar o restaurante de índice index no vetor de restaurantes da base
 * @param restaurant - restaurante com as modificações que pretendemos colocar no indice dado
 * @param index  - Index do restaurante que pretendemos modificar no vetor de restaurantes da base
 */
    void changeRestaurant(Restaurant restaurant, int index);
/**
 * @brief Permite remover um cliente do vetor de clientes
 * @param index  - Index do cliente que pretendemos remover do vetor de clientes da base
 */

    void removeClient(int index);
    /**
    * @brief Permite remover um funcionário do vetor de clientes
    * @param index  - Index do funcionário que pretendemos remover do vetor de funcionários da base
    */

    void removeEmployee(int index);

    /**
     * @brief Permite descobrir o indice de um funcionário no vetor de funcionários da base através do NIF
    * @param nif - nif do funcionário cujo index pretendemos encontrar
    * @return Index do funcionário no vetor de funcionários da base
     */
    int getIndexEmployee(string nif) const;
/**
     * @brief Permite distribuir uma encomenda pelo deliverer com menos encomendas
    * @param delivery - encomenda a distribuir
     */
    void addDeliveryToDeliverer(Delivery delivery);
/**
     * @brief Atualiza informações acerca das bases (revenues, valor de black no cliente)
     */
    void updateBases();
/**
     * @brief Permite adicionar um cliente à blacklist
    * @param client - cliente a adicionar à blacklist
     */
     void addClientToBlacklist(Client client);
};


#endif //UGH_EATS_BASE_H
