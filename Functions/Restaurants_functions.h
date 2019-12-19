#ifndef PROJETO_RESTAURANTS_FUNCTIONS_H
#define PROJETO_RESTAURANTS_FUNCTIONS_H

#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "../Classes/Base.h"
#include "../Functions/Verification_Inputs.h"
/**
 * Funções dos restaurantes
 */

/**
 * @brief Função que cria um restaurante
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */

int create_restaurant(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que modifica um restaurante
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int modify_restaurant(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que remove um restaurante
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int remove_restaurant(Base &Porto, Base &Lisboa, Base &Faro);


#endif //PROJETO_RESTAURANTS_FUNCTIONS_H
