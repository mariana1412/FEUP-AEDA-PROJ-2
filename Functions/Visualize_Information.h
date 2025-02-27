#ifndef PROJETO_VISUALIZE_INFORMATION_H
#define PROJETO_VISUALIZE_INFORMATION_H

#include "../Classes/Base.h"
#include "Verification_Inputs.h"
#include<algorithm>

/**
 * Funções de Visualização de informação
 */
 /**
  * @brief Permite visualizar todos os clientes de uma base escolhida na função
  * @param Porto - base do Porto
  * @param Lisboa - base de Lisboa
  * @param Faro - base de Faro
  * @return Retorna valor inteiro para retorno de Menu
  */
int visualize_clients(const Base &Porto, const Base &Lisboa, const Base &Faro);
/**
 * @brief Permite visualizar todos os clientes na blacklist de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int visualize_blacklist(const Base &Porto, const Base &Lisboa, const Base &Faro);
/**
 * @brief Permite visualizar todos os funcionários de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int visualize_employees(Base Porto, Base Lisboa, Base Faro);
/**
 * @brief Permite visualizar todos os restaurantes de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int visualize_restaurants(const Base &Porto, const Base &Lisboa, const Base &Faro);
/**
 * @brief Permite visualizar todos as encomendas de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int visualize_deliveries(const Base &Porto, const Base &Lisboa, const Base &Faro);
/**
 * @brief Permite visualizar todos os tecnicos de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */

int visualize_tecs(Base Porto,Base Lisboa,Base Faro);

/**
 * @brief Permite visualizar os veiculos de uma determinada base de uma determinada ordem dada pelo argumento "option"
 * @param base - base dos veículos a mostrar
 * @param option - opção que indica qual iterador a usar
 */

void print_vehicles(const Base &base, int option);

/**
 * @brief Permite visualizar todos os veiculos de uma base escolhida na função
 * @param Porto - base do Porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int visualize_vehicles(const Base &Porto, const Base &Lisboa, const Base &Faro);


bool SortById ( Tec tec1, Tec tec2);

#endif //PROJETO_VISUALIZE_INFORMATION_H
