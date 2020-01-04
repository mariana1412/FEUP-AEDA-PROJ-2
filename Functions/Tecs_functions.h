
#ifndef PROJETO_TECS_FUNCTIONS_H
#define PROJETO_TECS_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
//#include "Exceptions.h"
#include "../Classes/Base.h"
#include "Verification_Inputs.h"
#include "StringConverters.h"
class Base;
class Client;

using namespace std;
/**
 * Funções dos Técnicos
 */

/**
 * @brief Função que contrata um novo técnico
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */

int hire_tec(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que modifica um técnico existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int modify_tec(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que remove um técnico existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int remove_tec(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que lança uma exceção caso o técnico que se tenta criar já existe
 * @param b - base a que quer pertencer o técnico
 * @param nif - NIF do técnico em questão
 */
void tec_already_exists(string nif, const Base &p, const Base &l, const Base &f);

/**
 * @brief Função que procura um Técnico, através do seu nif (x), na fila de prioridade dos técnicos
 * @param v - fila de prioridade de tecnicos em que queremos procurar
 * @param x - NIF do tecnico em questão
 * @return Retorna o técnico em questao, ou um técnico com nif a 0 se não existir
 */
Tec Tec_sequential_search_t( TecPriorityQueue tec , int x);





#endif //PROJETO_TECS_FUNCTIONS_H