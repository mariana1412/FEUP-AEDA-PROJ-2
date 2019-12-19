#ifndef PROJETO_ORDER_FUNCTIONS_H
#define PROJETO_ORDER_FUNCTIONS_H

#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Clients_functions.h"
#include "Verification_Inputs.h"
#include "utils.h"



using namespace std;
/**
 * Funções de encomenda
 */

/**
 * @brief Função que realiza uma encomenda
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */

int create_order(Base &Porto, Base &Lisboa, Base &Faro);

/**
 * @brief Função que procura pelo restaurante dando como argumento uma string com o nome do mesmo
 * @param base - informação da base
 * @param name - nome do restaurante a procurar
 * @param restaurant - restaurante escolhido
 * @return vetor dos indices dos produtos escolhidos do restaurant
 */
vector<int> searchByRestaurant(Base base, string name, Restaurant &restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento uma string com o concelho do mesmo
 * @param b - informação da base
 * @param base - nome da base
 * @param county - concelho do restaurante a procurar
 * @param restaurant - restaurante escolhido
 * @return vetor dos indices dos produtos escolhidos do restaurant
 */
vector<int> searchByArea(Base b, string base, string county, Restaurant& restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento um float com o valor maximo do preço do produto
 * @param base - informação da base
 * @param pmax - preço máximo do produto
 * @param restaurant - restaurante escolhido
 * @return vetor dos indices dos produtos escolhidos do restaurant
 */
vector<int> searchByPrice(Base base, float pmax, Restaurant& restaurant);

/**
 * @brief Função que procura pelo restaurante dando como argumento uma string com o tipo de comida pretendido
 * @param base - informação da base
 * @param type_of_food - tipo de comida do produto
 * @param restaurant - restaurante escolhido
 * @return vetor dos indices dos produtos escolhidos do restaurant
 */
vector<int> searchByTypeOfFood(Base base, string type_of_food, Restaurant& restaurant);

/**
 * @brief Função que compara dois pairs usando como parametro de comparação o preço do produto
 * @param p1 - primeiro pair a comparar
 * @param p2 - segundo pair a comparar
 * @return true se o preço do produto dado por p1 é menor que o preço do produto dado por p2
 */
bool comparePrice(const pair<Restaurant, int> &p1, const pair<Restaurant, int> &p2);


#endif //PROJETO_ORDER_FUNCTIONS_H
