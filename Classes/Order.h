#ifndef UGH_EATS_ORDER_H
#define UGH_EATS_ORDER_H

#pragma once
#include <iostream>
#include "Restaurant.h"
#include "Vehicle.h"

using namespace std;
/**
 * Encomenda
 */
class Order{
private:
    Restaurant restaurant;/**< restaurante a que é feita a encomenda*/
    Time time;/**< Tempo exato da encomenda*/
    vector<Product> products;/**< Produtos encomendados*/
    int nif; /**< NIF do cliente que faz a encomenda*/

protected:
    float price;/**<preço da encomenda*/

public:
    /**
* @brief Construtor por default da classe Order
*/
    Order(){};
    /**
* @brief Construtor da classe Order
     * @param restaurant - restaurante a que é feita a encomenda
     * @param time - tempo exato da encomenda
     * @param products - produtos encomendados
     * @param nif - NIF do cliente que encomendou
*/
    Order(Restaurant restaurant, Time time , vector<Product>products, int nif);
    /**
* @brief Permite obter o restaurante a que é feita a encomenda
     * @return Retorna o restaurante a que é feita a encomenda
*/
    Restaurant getRestaurant() const;
    /**
* @brief Permite obter o tempo exato da encomenda
 * @return Retorna o tempo exato da encomenda
*/
    Time getTime() const;
    /**
* @brief Permite obter os produtos encomendados
* @return Retorna os produtos encomendados
*/
    vector<Product> getProducts()const;
    /**
* @brief Permite obter o NIF do cliente que faz a encomenda
* @return Retorna o NIF do cliente que faz a encomenda
*/
    int getNif()const;
    /**
* @brief Permite definir o restaurante a que é feita a encomenda
     * @param restaurant - restaurante a que é feita a encomenda
*/
    void setRestaurant(Restaurant restaurant);
    /**
* @brief Permite definir o tempo exato da encomenda
* @param time - tempo exato da encomenda
*/
    void setTime(Time time);
    /**
* @brief Permite definir os produtos encomendados
* @param products - produtos encomendados
*/
    void setProducts(vector<Product> products);
    /**
* @brief Permite definir o NIF do cliente que faz a encomenda
* @param nif - NIF do cliente que faz a encomenda
*/
    void setNif(int nif);
};

/**
 * Entrega
 */

class Delivery : public Order {
private:
    static int id_global; /**id global para saber a próxima entrega<*/
    int id;/**id da entrega<*/
    bool success;/**< sucesso ou insucesso da entrega*/
    string reason_insuccess;/**< motivo de insucesso*/
    Time deliver_time;/**< tempo exato da entrega*/
    float tax;/**< taxa da entrega*/
    float final_price;/**<preço final da entrega : taxa + preço dos produtos*/
public:
    /**
* @brief Construtor por default da classe Delivery
*/
    Delivery(){};
    /**
* @brief Construtor da classe Delivery
     * @param restaurant - restaurante a que é feita a encomenda
     * @param time - tempo exato em que é feita a encomenda
     * @param products - produtos encomendados
     * @param nif - NIF do cliente que faz a encomenda
     * @param id - id da entrega
     * @param success - sucesso ou insucesso (verdadeiro ou falso)
     * @param reason_insuccess - motivo de insucesso
     * @param deliver_time - tempo exato de entrega
     * @param tax - taxa de entrega
*/
    Delivery(Restaurant restaurant, Time time , vector<Product> products,int nif, int id, bool success, string reason_insuccess, Time deliver_time, float tax);
    /**
   * @brief Construtor da classe Delivery
        * @param restaurant - restaurante a que é feita a encomenda
        * @param time - tempo exato em que é feita a encomenda
        * @param products - produtos encomendados
        * @param nif - NIF do cliente que faz a encomenda
        * @param tax - taxa de entrega
   */

    Delivery(Restaurant restaurant, Time time , vector<Product> products,int nif, float tax);
    /**
* @brief Permite obter o id da entrega
     * @return Retorna o id da entrega
*/
    int getId() const;
    /**
* @brief Permite obter o sucesso ou insucesso da entrega
 * @return Retorna verdadeiro se a entrega foi bem sucedida, falso caso contrário
*/
    bool getSuccess() const;
    /**
* @brief Permite obter o motivo de insucesso da entrega
* @return Retorna o motivo de insucesso da entrega
*/
    string getReason_insuccess() const;
    /**
* @brief Permite obter o tempo exato da entrega
* @return Retorna o tempo exato da entrega
*/
    Time getDeliver_time() const;
    /**
* @brief Permite obter o preço da entrega
* @return Retorna o preço da entrega
*/
    float getPrice() const;
    /**
* @brief Permite obter o preço final da entrega
* @return Retorna o preço final da entrega
*/
    float getFinalPrice() const;
    /**
* @brief Permite obter o valor da taxa de entrega
* @return Retorna o valor da taxa de entrega
*/
    float getTax() const;

    /**
* @brief Permite definir o sucesso ou insucesso da entrega
 * @param success - verdadeiro se a entrega foi bem sucedida, falso caso contrário
*/
    void setSuccess(bool success);
    /**
* @brief Permite definir o motivo de insucesso da entrega
* @param reason_insucess - motivo de insucesso da entrega
*/
    void setReason_insuccess(string reason_insucess);
    /**
* @brief Permite definir o tempo exato da entrega
* @param deliver_time - tempo exato da entrega
*/
    void setDeliver_time(Time deliver_time);
    /**
* @brief Permite definir o preço da entrega
* @param price - preço da entrega
*/
    void setPrice(float price);
/**
* @brief Permite imprimir uma encomenda
* @param os - outstream
 * @param d - delivery a imprimir
 * @return Retorna uma ostream com as informações da delivery
*/
    friend ostream & operator<<(ostream &os, const Delivery &d);
};


#endif //UGH_EATS_ORDER_H
