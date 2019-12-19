#ifndef PROJETO_UTILS_H
#define PROJETO_UTILS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Exceptions.h"
#include "../Classes/Time.h"


using namespace std;
/**
 * Funções de utéis para o programa
 */

/**
 * @brief Função que verifica se uma string é um número
 * @parsam n - string
 * @return Retorna verdadeira se n for um número, falso caso contrário
 */
bool isNumber(string n);
/**
 * @brief Função que verifica se um carater é um algarismo
 * @parsam n - carater
 * @return Retorna verdadeira se n for um algarismo, falso caso contrário
 */
bool isAlgarism(char n);
/**
 * @brief Função que verifica se um carater é uma letra
 * @parsam a - carater
 * @return Retorna verdadeira se a for uma letra, falso caso contrário
 */
bool isLetter(char a);
/**
 * @brief Função que retira o ' ' do inicio e do fim de uma string
 * @parsam str - string
 */
void trim(string &str);
/**
 * @brief Função que formata a string para que todas as letras sejam minusculas menos a primeira letra de cada palavra
 * @parsam str - string
 */
void formatting_string(string &str);
/**
 * @brief Função que remove todos os espaços de uma string
 * @parsam aux - string
 */
void remove_all_whitespaces(string &aux);
/**
 * @brief Função que remove todos os espaços extra de uma string
 * @parsam aux - string
 */
string remove_extra_whitespaces(string aux);
/**
 * @brief Função que confirma uma operação
 * @parsam action - ação que está a ser realizada
 * @param str - tipo de objeto a ser alterado
 */
bool confirm_modifications(string action, string str);
/**
 * @brief Converte uma string em horas adicionando esta informaçao a um objeto do tipo Time
 * @param d - objeto do tipo Time
 * @param s - string que pretendemos converter
 */
void stringToHours(Time &d,string str);
/**
 * @brief Verifica se a hora inserida é válida
 * @param aux - hora no tipo string a ser verificada
 */
void verification_hour(string &aux);




#endif //PROJETO_UTILS_H
