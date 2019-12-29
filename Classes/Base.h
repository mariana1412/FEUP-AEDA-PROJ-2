#ifndef UGH_EATS_BASE_H
#define UGH_EATS_BASE_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>
#include "Location.h"
#include "Person.h"
#include "bst.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------------------------//
/**
 * struct auxiliar para dispersão de funcionários (atuais ou antigos) numa tabela de dispersão
 */
struct EmployeeHash
{
    /**
	 * @brief Função de dispersão para funcionários (atuais ou antigos)
	 * @param employee - funcionário para dispersar
	 * @return valor do indice do funcionário dado como argumento
	 */
    int operator() (const Employee * employee) const
    {
        static const size_t shift = (size_t)log2(1 + sizeof(Employee));
        return (int)(employee->getNif()) >> shift;

    }

    /**
     * @brief Operador de igualdade de funcionários sendo usado para encontrar colisões na tabela
     * @param employee1 - funcionário a ser comparado
     * @param employee2 - funcionário a ser comparado
     * @return retorna true se os funcionários tiverem o mesmo nif, isto é, serem a mesma pessoa; retorna falso caso contrário
     */

    bool operator() (const Employee * employee1, const Employee * employee2) const
    {
        return (employee1->getNif() == employee2->getNif());
    }
};

//--------------------------------------------------------------------------------------------------------------------------//


/**
 * Base da empresa Ugh Eats
 */

typedef unordered_set<Employee*, EmployeeHash, EmployeeHash> HashTableEmployees;
typedef priority_queue<Tec> TecPriorityQueue;

class Base{
private:
    Location location; /**< Localização exata da base*/
    string manager;/**<Gerente da base*/
    int manager_nif; /**<NIF do gerente da base*/
    vector<Client> clients;/**Clientes da base*/
    vector<Client> blacklist;/**Lista negra da organização*/
    vector<Restaurant> restaurants;/**Conjunto de fornecedores da base*/
    vector<Delivery> deliveries;/**Encomendas feitas a esta base*/
    BST<Vehicle> vehicles; /**Veículos pertencentes à base*/
    TecPriorityQueue tecnicos; /**Tecnicos especializados em manutenção de veiculos*/
    HashTableEmployees employeesHash; /**Registo de todos os funcionários (antigos ou atuais)*/
public:
    /**
	 * @brief Construtor por default da classe Base
	 */
    Base();
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
    * @brief Permite obter as encomendas da base
    * @return Retorna um vetor com as encomendas da base
    */
    vector<Delivery> getDeliveries() const;

    /**
    * @brief Permite obter os veiculos da base
    * @return Retorna uma BST com os veículos da base
    */
    BST<Vehicle> getVehicles() const;

    /**
     * @brief Permite obter os funcionários armazenados na tabela de dispersão
     * @return Retorna um vetor com os funcionários da tabela de dispersão
     */
    vector<Employee *> getEmployeesHash() const;
    /**
     *
     * @brief Permite obter os técnicos disponiveis numa fila de prioridade
     * @return Retorna um vetor de tecnicos com os tecnicos sendo o menor index o tecnico disponivel mais cedo e que tenha concluido o maior numero de manutençoes
     *
     */
    vector<Tec> getTecs () const;
    /**
   * @brief Permite descobrir o indice de um restaurante no vetor de restaurantes da base
   * @param restaurant - restaurante cujo index pretendemos encontrar
   * @return Index do restaurante no vetor de restaurantes da base
   */
    int getIndexrestaurant(Restaurant restaurant);

    /**
    * @brief Permite descobrir o indice de um funcionário no vetor de funcionários da base através do NIF
    * @param nif - nif do funcionário cujo index pretendemos encontrar
    * @return Index do funcionário no vetor de funcionários da base
    */
    int getIndexEmployee(string nif) const;
    /**
     * @brief Permite definir os técnicos especializados em manutenção de veiculos disponiveis para prestar serviços à empresa
     * @param tecs - vetor de tecnicos especializados em manutenção de veiculos disponiveis para prestar serviços à empresa
     */

    void setTecs(vector<Tec> tecs);

    /**
     * @brief Permite guardar os funcionários contidos no vetor dado como argumento na tabela de dispersão
     * @param aux - vetor com todos os funcionários (atuais ou antigos) da base
     */
    void setEmployeesHash(vector<Employee *>& aux);

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
     * @brief Permite definir os veiculos da base
     * @param vehicles - vetor de veiculos da base
     */
     void setVehicles(vector<Vehicle> vehicles);
    /**
    * @brief Permite adicionar um cliente a base
    * @param client - cliente que pretendemos adicionar à base
    */
    void addClient(Client client);
        /**
    * @brief Permite adicionar um cliente à blacklist
    * @param client - cliente a adicionar à blacklist
    */
    void addClientToBlacklist(Client client);
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
    * @brief Permite adicionar uma veículo à base
    * @param vehicle - veículo que pretendemos adicionar à base
    */
    void addVehicle(Vehicle vehicle);

    /**
    * @brief Permite distribuir uma encomenda pelo deliverer com menos encomendas
    * @param delivery - encomenda a distribuir
     * @param order_time - momento em que foi feita a encomenda na forma de objeto da classe Time
    */
    void addDeliveryToDeliverer(Delivery delivery, Time order_time);
        /**
    * @brief Permite adicionar um técnico à base
    * @param  tecnico - tecnico que pretendemos adicionar à base
    */
    void addTec(Tec tecnico);
    /**
    * @brief Permite remover um restaurante da base, se este existir
    * @param name - nome do restaurante que pretendemos remover
    * @return Retorna true caso seja possivel remover o restaurante
    */
    bool removeRestaurant(string name);

    /**
     * @brief Permite remover um cliente do vetor de clientes
     * @param index  - Index do cliente que pretendemos remover do vetor de clientes da base
     */

    void removeClient(int index);
    /**
    * @brief Permite remover um funcionário da tabela de dispersão dos funcionários
    * @param index  - Index do funcionário que pretendemos remover do vetor de funcionários da base
    */

    void removeEmployee(int index);
    /**
     * @brief Permite remover um tecnico da fila de prioridade
     * @param tecnico - tecnico que pretendemos remover da fila de prioridade
     */
    void removeTec(Tec tecnico );
    /**
    * @brief Permite encontrar um restaurante no vetor de restaurantes da base
    * @param name - nome do restaurante que pretendemos procurar
    * @return Restaurante que pretendemos
    */
    Restaurant searchRestaurant(string name);

    /**
     * @brief Permite modificar o restaurante de índice index no vetor de restaurantes da base
     * @param restaurant - restaurante com as modificações que pretendemos colocar no indice dado
     * @param index  - Index do restaurante que pretendemos modificar no vetor de restaurantes da base
     */
    void changeRestaurant(Restaurant restaurant, int index);
    /**
    * @brief Permite contratar um funcionário antigo da tabela de dispersão dos funcionários
    * @param index  - Index do funcionário que pretendemos contratar da tabela de dispersão dos funcionários da base
    */

    void hireEmployee(int index);
    /**
    * @brief Atualiza informações acerca das bases (revenues, valor de black no cliente)
    */
    void updateBases();
    /**
     * @brief Imprime no ecrã todos os funcionários possibilitando vários casos diferentes
     * @param former - se for true, imprime os antigos funcionários
     * @param newE - se for true, imprime os funcionários atuais
     * @param admin - se for true, imprime os administradores
     * @param deliverer - se for true, imprime os entregadores
     * @return Retorna um vetor com os indices dos funcionários que foram mostrados no ecrã
     */
    vector<int> printEmployees(bool former, bool newE, bool admin, bool deliverer);
    /**
     * @brief Imprime no ecrã todos os tecnicos possibilitando dois modos de ordenaçao dos mesmos
     * @param aux - vetor de tecnicos que contem os tecnicos da base correspondente
     */
    void printTecs(vector<Tec> aux);

    /**
     * @brief Escolha um funcionário dos que estão no ecrã de acordo com os argumentos dados
     * @param former - se for true, imprime os antigos funcionários
     * @param newE - se for true, imprime os funcionários atuais
     * @param admin - se for true, imprime os administradores
     * @param deliverer - se for true, imprime os entregadores
     * @param action - indica a ação que se pretende efetuar ao escolher o funcionário
     * @return Retorna o índice do funcionário escolhido na tabela de dispersão
     */
    int chooseEmployee(bool former, bool newE, bool admin, bool deliverer, string action);
    /**
     * @brief Limpa a fila de prioridade dos tecnicos
     */
    void clearTecs();
/**
 *@brief Se um veiculo atingir 5 entregas após a ultima manutenção, é enviado para a manutenençao sendo feitas as atualizaçoes necessarias
 * @param ve - veiculo que atingiu as 5 entregas desde a ultima manutenção
 */
    void sendToMaintenance(Vehicle ve);

/**
 * @brief Funçao que decrementa o n de horas e minutos ate estar disponivel o tecnico e verifica se ja terminou a manutenção
 * @param m - numero de minutos que passaram
 * @param h - numero de horas que passaram
 */
    void updateTecs(int m);
    /**
     * @brief Funçao que decrementa o tempo ate terminar a manutençao do veiculo e verifica se ja terminou a manutenção
     * @param m - numero de minutos que passaram
     */
    void updateVehicles(int m);
    /**
     * @brief Funçao que atualiza a hash table dos employees para os valores corretos
     */
    void hashUpdate();
    /**
     * @brief Funçao que atualiza o número de kms percorridos de um veiculo, adicionando a o número de kms da viagem
     * @param distance - número de kms da viagem de entrega
     * @param del - deliverer a quem o veículo pertence
     */
     void addDistance(int distance, Deliverer* del);
};

#endif //UGH_EATS_BASE_H
