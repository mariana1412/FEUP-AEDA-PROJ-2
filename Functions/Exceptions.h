#ifndef PROJETO_EXCEPTIONS_H
#define PROJETO_EXCEPTIONS_H

#pragma once
#include <string>


using namespace std;

/**
 * Classe Blacklist utilizada para tratamento de exceções no decorrer do programa.
 */

class BlackList {
private:
    string msg;/**<Mensagem acerca do erro que lançou a execeção*/
public:
    /**
     * @brief Construtor da classe BlackList
     * **/
    BlackList() { msg = "Client belongs to the Black List!"; }
    /**
     * @brief Permite obter a descrição do erro
     * @return Retorna a mensagem de erro
     */
    string getMsg() const { return msg; }
};

/**
 * Classe OutOfArea utilizada para tratamento de exceções no decorrer do programa.
 */
class OutOfArea {
private:
    string msg;/**<Mensagem acerca do erro que lançou a execeção*/
public:
    /**
 * @brief Construtor da classe OutOfArea
 * **/
    OutOfArea() { msg = "It is not possible to create this client, it does not belong to the base area! "; }
    /**
  * @brief Permite obter a descrição do erro
  * @return Retorna a mensagem de erro
  */
    string getMsg() const { return msg;  }
};
/**
 * Classe RestaurantOutOfArea utilizada para tratamento de exceções no decorrer do programa.
 */

class RestaurantOutOfArea {
private:
    string county;/**<concelho do restaurante que gerou a exceção*/
public:
    /**
* @brief Construtor da classe RestaurantOutOfArea
     * @param c - concelho do restaurante que lançou a exceção
* **/
    RestaurantOutOfArea(string c) {this->county = c;}
    /**
  * @brief Permite obter a descrição do erro
  * @return Retorna a mensagem de erro
  */
    string getCounty() const {return county;}
};

/**
 * Classe RestaurantNotFound utilizada para tratamento de exceções no decorrer do programa.
 */
class RestaurantNotFound {
private:
    string name;/**<nome do restaurante que gerou a exceção*/
public:
    /**
* @brief Construtor da classe RestaurantNotFound
  * @param n - nome do restaurante que lançou a exceção
* **/
    RestaurantNotFound(string n) {this->name = n; }
    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getName() const {return name;}
};
/**
 * Classe RestaurantAlreadyExists utilizada para tratamento de exceções no decorrer do programa.
 */
class RestaurantAlreadyExists {
private:
    string name;/**<nome do restaurante que gerou a exceção*/
public:
    /**
* @brief Construtor da classe RestaurantAlreadyExists
* @param n - nome do restaurante que lançou a exceção
* **/
    RestaurantAlreadyExists(string n) {this->name = n;}
    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getName() const {return name;}
};
/**
 * Classe ProductAlreadyExists utilizada para tratamento de exceções no decorrer do programa.
 */

class ProductAlreadyExists {
private:
    string name;/**<nome do produto que gerou a exceção*/
public:
    /**
* @brief Construtor da classe ProductAlreadyExists
* @param name - nome do produto que lançou a exceção
* **/
    ProductAlreadyExists(string name) {this->name = name;}
    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getName() const {return name;}
};
/**
 * Classe ProductNotFound utilizada para tratamento de exceções no decorrer do programa.
 */

class ProductNotFound {
private:
    string name;/**<nome do restaurante que gerou a exceção*/
public:
    /**
* @brief Construtor da classe ProductNotFound
* @param p - nome do produto que lançou a exceção
* **/
    ProductNotFound(string p) {this->name = p;}
    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getName() const {return name;}
};
/**
 * Classe ClientAlreadyExists utilizada para tratamento de exceções no decorrer do programa.
 */
class ClientAlreadyExists{
private:
    string nif;/**<nif do cliente que gerou a exceção*/
public:
    /**
* @brief Construtor da classe ClientAlreadyExists
* @param nif - nif do cliente que lançou a exceção
* **/
    ClientAlreadyExists(string nif){this->nif=nif;}
    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getNIF() const{return nif;}
};
/**
 * Classe EmployeeAlreadyExists utilizada para tratamento de exceções no decorrer do programa.
 */
class EmployeeAlreadyExists {
private:
    string nif;/**<nome do funcionário que gerou a exceção*/
public:
    /**
* @brief Construtor da classe EmployeeAlreadyExists
* @param nif - nif do funcionário que lançou a exceção
* **/
    EmployeeAlreadyExists(string nif) { this->nif = nif; }

    /**
* @brief Permite obter a descrição do erro
* @return Retorna a mensagem de erro
*/
    string getNIF() const { return nif; }
};
    /**
 * Classe EmployeeNotFound utilizada para tratamento de exceções no decorrer do programa.
 */
    class EmployeeNotFound{
    private:
        string nif;/**<nome do funcionário que gerou a exceção*/
    public:
        /**
    * @brief Construtor da classe EmployeeAlreadyExists
    * @param nif - nif do funcionário que lançou a exceção
    * **/
        EmployeeNotFound(string nif){this->nif=nif;}
        /**
    * @brief Permite obter a descrição do erro
    * @return Retorna a mensagem de erro
    */
        string getNIF() const{return nif;}
};

#endif //PROJETO_EXCEPTIONS_H
