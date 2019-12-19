#ifndef PROJETO_EMPLOYEES_FUNCTIONS_H
#define PROJETO_EMPLOYEES_FUNCTIONS_H

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
 * Funções dos Funcionários
 */

/**
 * @brief Função que cria um novo funcionário
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */

int create_employee(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que modifica um funcionário existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int modify_employee(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que remove um funcionário existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int remove_employee(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que lança uma exceção caso o funcionário que se tenta criar já existe
 * @param b - base a que quer pertencer o funcionário
 * @param nif - NIF do funcionário em questão
 */
bool employee_already_exists(string nif, const Base &p, const Base &l, const Base &f);
/**
 * @brief Função que procura um Funcionário, através do seu nif (x), num vetor de funcionários
 * @param v - vetor de funcionários em que queremos procurar
 * @param x - NIF do funcionário em questão
 * @return Retorna o índice do vetor de funcionários em que se encontra o respetivo funcionário, -1 se não existir
 */
int int_sequential_search_e(const vector<Employee*> &v, int x);
/**
 * @brief Função que procura um funcionário, através do seu nome (x), num vetor de funcionários
 * @param v - vetor de funcionários em que queremos procurar
 * @param x - nome do funcionário em questão
 * @return Retorna o índice do vetor de funcionários em que se encontra o respetivo funcionário, -1 se não existir
 */
int string_sequential_search_e(const vector<Employee*> &v, string x);
/**
 * @brief Permite mudar o gerente de quaisquer base
 * @param Porto - base do porto
 * @param Lisboa - base de Lisboa
 * @param Faro - base de Faro
 * @return Retorna valor inteiro para retorno de Menu
 */
int changeManager(Base& Porto, Base& Lisboa, Base& Faro);

#endif //PROJETO_EMPLOYEES_FUNCTIONS_H
