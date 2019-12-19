#ifndef UGH_EATS_RESTAURANTS_H
#define UGH_EATS_RESTAURANTS_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "../Functions/utils.h"

using namespace std;
/**
 * Restaurante
 */
extern const  vector<string> nearby_Porto;
extern const vector<string> nearby_Lisboa;
extern const vector<string> nearby_Faro;

class Restaurant{
private:
    string name;/**< nome do restaurante*/
    string address;/**< morada do restaurante*/
    string county;/**< concelho do restaurante*/
    vector<string> types_of_food;/**< tipos de comida do restaurante*/
    vector<Product> products;/**< produtos do restaurante*/
    float revenue;/**< valor retirado pela empresa neste restaurante*/

public:
    /**
 * @brief Construtor por default da classe Restaurant
 */
    Restaurant(){};
    /**
 * @brief Construtor da classe Base
     * @param name - nome do restaurante
     * @param address - morada do restaurante
     * @param county - concelho do restaurante
     * @param types_of_food - tipos de comida do restaurante
     * @param products - produtos do restaurante
     * @param revenue - valor retirado pela empresa neste restaurante
 */
    Restaurant(string name, string address, string county, vector<string> types_of_food, vector<Product> products, float revenue);
    /**
 * @brief Permite obter o nome do restaurante
     * @return Retorna o nome do restaurante
 */
    string getName() const;
    /**
* @brief Permite obter a morada do restaurante
 * @return Retorna a morada do restaurante
*/
    string getAddress() const;
    /**
* @brief Permite obter o concelho do restaurante
 * @return Retorna o concelho do restaurante
*/
    string getCounty() const;
    /**
* @brief Permite obter os tipos de comida do restaurante
 * @return Retorna os tipos de comida do restaurante
*/
    vector<string> getTypes_of_food() const;
    /**
* @brief Permite obter os produtos do restaurante
 * @return Retorna os produtos do restaurante
*/
    vector<Product> getProducts() const;
    /**
* @brief Permite obter o valor retirado pela empresa neste restaurante
 * @return Retorna o Valor retirado pela empresa neste restaurante
*/
    float getRevenue() const;
    /**
* @brief Permite definir o nome do restaurante
 * @param name - nome do restaurante
*/
    void setName(string name);
    /**
* @brief Permite definir o nome do restaurante verificando se já existe
* @param name - nome do restaurante
     * @param v - vetor de restaurantes da base
*/
    void setName(string name, const vector<Restaurant> &v);
    /**
* @brief Permite definir o concelhp do restaurante
* @param county - concelho do restaurante
*/
    void setCounty(string county);
    /**
* @brief Permite definir o nome do restaurante verificando se pretence à area da base
* @param county - concelho do restaurante
     * @param base -base do restaurante
*/
    void setCounty(string county, string base);
    /**
* @brief Permite definir o nome do restaurante
* @param name - nome do restaurante
*/
    void setAddress(string address);
    /**
* @brief Permite definir os tipo de comida do restaurante
* @param types_of_food - tipos de comida do restaurante
*/
    void setTypes_of_food(vector<string> types_of_food);
    /**
* @brief Permite definir os produtos do restaurante
* @param products - produtos do restaurante
*/
    void setProducts(vector<Product> products);
    /**
* @brief Permite definir o valor retirado pela empresa neste restaurante
* @param revenue - valor retirado pela empresa neste restaurante
*/
    void setRevenue(float revenue);
    /**
* @brief Permite adicionar um produto a um restaurante, verificando se este já existe
* @param product - produto a ser adicionado
*/
    void addProduct(Product product);
    /**
* @brief Permite adicionar um tipo de comida ao restaurante
* @param type_of_food - tipo de comida a ser adicionado
*/
    void addType_of_food(string type_of_food);
    /**
* @brief Operador = para comparar restaurantes
 * @param rest - um outro restaurante para comparar ao restaurante em questão
 * @return Retorna true caso o produto em questão seja igual ao produto a comparar, false caso contrário.
*/
    bool operator==(const Restaurant& rest) const;
    /**
* @brief Procura um produto nos produtos do restaurante
* @param name - nome do produto em questão
* @return Retorna o produto caso ele exista
*/
    Product searchProduct(string name);
    /**
* @brief Procura o index de um produto no vetor de produtos do restaurante
* @param produto - produto a ser procurado
* @return Retorna o index do produto no vetor de produtos do restaurante, caso ele exista
*/
    int getIndexProduct(Product product);
    /**
* @brief Remove um produto do restaurante
* @param index - indíce do produto a ser retirado no vetor de produtos do restaurante
*/
    void removeProduct(int index);
    /**
* @brief Atualiza os tipos de comida do restaurante
*/
    void updateTypes_of_food();

/**
 * @brief Permite modificar o produto de indice index no vetor de produtos do restaurante
 * @param produto - produto com as modificações que pretendemos colocar no indice dado
 * @param index  - Index do produto que pretendemos modificar no vetor de produtos do restaurante
 */
    void changeProduct(Product product, int index);

    /**
* @brief Permite mostrar no ecrã os tipos de comida de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param types_of_food - vetor de string que pretendemos mostrar no ecrã
 */
    friend ostream& operator<<(ostream& os, const vector<string>& types_of_food);

    /**
* @brief Permite mostrar no ecrã os produtos de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param products - vetor de produtos que pretendemos mostrar no ecrã
*/
    friend ostream& operator<<(ostream& os, const vector<Product>& products);

/**
* @brief Permite mostrar no ecrã o restaurante de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param rest - restaurante que pretendemos mostrar no ecrã
 */
    friend ostream& operator<<(ostream& os, const Restaurant& rest);
};


#endif //UGH_EATS_RESTAURANTS_H
