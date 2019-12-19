#ifndef PROJETO_VERIFICATIONS_INPUTS_H
#define PROJETO_VERIFICATIONS_INPUTS_H

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"
#include "../Classes/Time.h"
#include "StringConverters.h"

using namespace std;
/**
 * Funções de verificação de inputs
 */

/**
 * @brief Função que verifica se a opçao escolhida num menu é válida ou não
 * @parsam option - opção do menu
 * @param omin - valor minimo do menu
 * @param omax - valor maximo do menu
 */

void menu_int_options(int &option, int omin, int omax);

/**
 * @brief Função que verifica se a opçao escolhida num menu de produtos é válida ou não
 * @parsam option - opção do menu
 * @param omin - valor minimo do menu
 * @param omax - valor maximo do menu
 */
void product_menu(int &option, int omin, int nmax);

/**
 * @brief Função que verifica se uma string é um inteiro válido
 * @parsam aux - string
 */
void verification_int(string &aux);
/**
 * @brief Função que verifica se uma string é um NIF válido
 * @parsam aux - string
 */
void verification_nif(string &aux);
/**
 * @brief Função que verifica se uma string é tudo letras
 * @parsam aux - string
 */
void verification_all_letters(string &aux);
/**
 * @brief Função que verifica se uma string é uma data válida
 * @parsam aux - string
 * @return data válida
 */
Time verification_date(string &aux);
/**
 * @brief Função que verifica se uma string é uma base válida
 * @parsam aux - string
 */
void verification_base(string &aux);
/**
 * @brief Função que verifica se uma string é um float válido
 * @parsam aux - string
 */
void verification_float(string &aux);

/**
 * @brief Função que verifica se uma string é uma data válida, formato: dd/mm/yyyy, hh:mm
 * @parsam aux - string
 * @return data válida
 */
Time verification_time(string &aux);

#endif //PROJETO_VERIFICATIONS_INPUTS_H

