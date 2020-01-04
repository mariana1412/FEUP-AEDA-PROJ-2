
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

/**
 * @brief Função que procura um técnico, através do seu nif ou do seu nome consoante a variável byName, na fila de prioridade dos técnicos
 * @param byName - Se for true, a procura do técnico é através de nome; se for false, a procura é através do nif
 * @param name - Nome do técnico em questão
 * @param nif - NIF do técnico em questão
 * @param v -vetor de tecnicos em que queremos procurar
 * @return Retorna o indice do técnico em questao ou -1 se não existir
 */

int search_tec(bool byName, string name, int nif, vector<Tec> v);



#endif //PROJETO_TECS_FUNCTIONS_H