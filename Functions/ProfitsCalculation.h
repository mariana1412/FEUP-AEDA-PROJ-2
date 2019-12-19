#ifndef PROJETO_PROFITSCALCULATION_H
#define PROJETO_PROFITSCALCULATION_H

#pragma once

#include <iostream>
#include<iomanip>
#include "../Classes/Base.h"
#include "../Functions/Verification_Inputs.h"

using namespace std;
/**
 * Funções de cálculo dos valores que a empresa retira dos seus serviço
 */



/**
 * @brief Funções de cálculo dos valores que a empresa retira dos seus serviço por base
 * @param p - base do Porto
 * @param l - base de Lisboa
 * @param f - base de Faro
 * @return valor inteiro para retorno do Menu
 */
int ProfitsByBase(Base p, Base l, Base f);
/**
 * @brief Funções de cálculo dos valores que a empresa retira dos seus serviço por fornecedor
 * @return valor inteiro para retorno do Menu
 */
int ProfitsByRestaurant(Base p, Base l , Base f);
/**
 * @brief Funções de cálculo dos valores que a empresa retira dos seus serviço por cliente
 * @return valor inteiro para retorno do Menu
 */
int ProfitsByClient(Base p, Base l, Base f);
/**
 * @brief Funções de cálculo dos valores que a empresa retira dos seus serviço no geral em cada periodo de tempo
 * @return valor inteiro para retorno do Menu
 */
int ProfitByTimeInterval(Base p, Base l , Base f);
/**
 * @brief Função que procura um Cliente, através do seu nome (x), num vetor de Clientes
 * @param v - vetor de clientes em que queremos procurar
 * @param x - nome do cliente em questão
 * @return Retorna o índice do vetor de Clientes em que se encontra o respetivo Cliente, -1 se não existir
 */
int string_sequential_search_aux(const vector<Client> &v, string x);

#endif //PROJETO_PROFITSCALCULATION_H
