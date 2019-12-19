#ifndef PROJETO_VISUALIZE_INFORMATION_H
#define PROJETO_VISUALIZE_INFORMATION_H

#include "../Classes/Base.h"
#include "Verification_Inputs.h"

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
int visualize_employees(const Base &Porto, const Base &Lisboa, const Base &Faro);
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



#endif //PROJETO_VISUALIZE_INFORMATION_H
