#ifndef UGH_EATS_PRODUCT_H
#define UGH_EATS_PRODUCT_H

#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/**
 * Produto
 */


class Product{
private:
    string name;/**< nome do produto*/
    string type_of_food;/**< tipo de culinária do produto*/
    float price;/**< preço do produto*/
public:
    /**
* @brief Construtor por default da classe Produto
*/
    Product(){};
    /**
* @brief Construtor  da classe Produto
 * @param name - nome do produto
 * @param type_of_food - tipo de culinária do produto
 * @param price - preço do produto
*/
    Product(string name, string type_of_food, float price);
    /**
* @brief Permite obter o nome do produto
     * @return Retorna o nome do produto
*/
    string getName() const;
    /**
* @brief Permite obter o tipo de culinária do produto
 * @return Retorna o tipo de culinária do produto
*/
    string getType_of_food() const;
    /**
* @brief Permite obter o preço do produto
 * @return Retorna o preço do produto
*/
    float getPrice() const;
    /**
* @brief Permite definir o nome do produto
     * @param name - nome do produto
*/
    void setName(string name);
    /**
* @brief Permite definir o tipo de culinária do produto
 * @param type_of_food - tipo de culinária do produto
*/
    void setType_of_food(string type_of_food);
    /**
* @brief Permite definir o preço do produto
 * @param price - preço do produto
*/
    void setPrice(float price);
    /**
* @brief Operador = para comparar produtos
	 * @param prod - um outro produto para comparar ao produto em questão
	 * @return Retorna true caso o produto em questão seja igual ao produto a comparar, false caso contrário.
*/
    bool operator==(const Product& prod) const;

/**
 * @brief Permite mostrar no ecrã o produto de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param prod - produto que pretendemos mostrar no ecrã
 */

    friend ostream& operator<<(ostream& os, const Product& prod);
};


#endif //UGH_EATS_PRODUCT_H
