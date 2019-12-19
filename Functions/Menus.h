#ifndef PROJETO_MENUS_H
#define PROJETO_MENUS_H

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Verification_Inputs.h"
using namespace std;


/**
 * Funções dos Menus
 */

/**
 * @brief Menu de gestão da conta do Cliente
 * @return Retorna valor inteiro para retorno do Menu
 */
int AccountManagement();
/**
 * @brief Menu principal visualizado pelo Patrão
 * @return Retorna valor inteiro para retorno do Menu
 */
int Boss_MainMenu();
/**
 * @brief Menu principal visualizado pela gerente
 * @return Retorna valor inteiro para retorno do Menu
 */
int Manager_MainMenu();
/**
 * @brief Menu principal visualizado pelo administrador
 * @return Retorna valor inteiro para retorno do Menu
 */
int Admin_MainMenu();
/**
 * @brief Menu principal visualizado pelo Cliente
 * @return Retorna valor inteiro para retorno do Menu
 */
int Client_MainMenu();

/**
 * @brief Menu de gerir clientes
 * @return Retorna valor inteiro para retorno do Menu
 * **/
int ClientsManagement();
/**
 * @brief Menu de gerir funcionários
 * @return Retorna valor inteiro para retorno do Menu
 * **/
int EmployeesManagement();
/**
 * @brief Menu de gerir restaurantes
 * @return Retorna valor inteiro para retorno do Menu
 * **/
int RestaurantsManagement();
/**
 * @brief Menu de realizar uma encomenda
 * @return Retorna valor inteiro para retorno do Menu
 * **/
int Order();
/**
 * @brief Menu de cálculo de lucro
 * @return Retorna valor inteiro para retorno do Menu
 * **/
int ProfitsCalculation();
/**
 * @brief Menu de Visualização de informação
 * @return Retorna valor inteiro para retorno do Menu
 */

int VisualizeInformation();

#endif //PROJETO_MENUS_H
