
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
 * @brief Função que procura um Funcionário, através do seu nif (x), num vetor de funcionários
 * @param v - vetor de funcionários em que queremos procurar
 * @param x - NIF do funcionário em questão
 * @return Retorna o índice do vetor de funcionários em que se encontra o respetivo funcionário, -1 se não existir
 */
//int int_sequential_search_e(const vector<Employee*> &v, int x);
/**
 * @brief Função que procura um funcionário, através do seu nome (x), num vetor de funcionários
 * @param v - vetor de funcionários em que queremos procurar
 * @param x - nome do funcionário em questão
 * @return Retorna o índice do vetor de funcionários em que se encontra o respetivo funcionário, -1 se não existir
 */
//int string_sequential_search_e(const vector<Employee*> &v, string x);



#endif //PROJETO_TECS_FUNCTIONS_H