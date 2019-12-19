#ifndef PROJETO_CLIENTS_FUNCTIONS_H
#define PROJETO_CLIENTS_FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Base.h"
#include "Verification_Inputs.h"
#include "utils.h"


using namespace std;

/**
 * Funções dos Clientes
 */

extern const  vector<string> nearby_Porto;
extern const vector<string> nearby_Lisboa;
extern const vector<string> nearby_Faro;
/**
 * @brief Função que cria um novo cliente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int create_client(Base &Porto, Base &Lisboa, Base &Faro,bool is_client);
/**
 * @brief Função que modifica um cliente existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int modify_client(Base &Porto, Base &Lisboa, Base &Faro);
/**
 * @brief Função que remove um cliente existente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int remove_client(Base &Porto, Base &Lisboa, Base &Faro);
int modifyData(Base &Porto, Base &Lisboa, Base &Faro);
/*
 * @brief Função que remove um conta de um cliente
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @return valor inteiro para retorno do Menu
 */
int removeAccount(Base &Porto,Base &Lisboa,Base &Faro);
/**
 * @brief Função que lança uma exceção caso o cliente esteja na blacklist da empresa
 * @param base - toda a informação da base a que pertence o cliente com o nif no argumento
 * @param nif - NIF do cliente
 */
void black_list(const Base &base, int nif);
/**
 * @brief Função que lança uma exceção caso o cliente não pertença à área da base
 * @param b - base a que pertence/quer pertencer o cliente
 * @param county - concelho em que vive o cliente
 * @param v - vetor de clientes da base enviada como argumento
 */
void out_of_area(const vector<Client> &v,string county,string b);
/**
 * @brief Função que lança uma exceção caso o cliente que se tenta criar já existe
 * @param b - base a que quer pertencer o cliente
 * @param nif - NIF do cliente em questão
 */
void client_already_exists(string nif, const Base &p, const Base &l, const Base &f);

/**
 * @brief Função que procura um Cliente, através do seu nif (x), num vetor de Clientes
 * @param v - vetor de clientes em que queremos procurar
 * @param x - NIF do cliente em questão
 * @return Retorna o índice do vetor de Clientes em que se encontra o respetivo Cliente, -1 se não existir
 */

int int_sequential_search_c(const vector<Client> &v, int x);

/**
 * @brief Função que procura um Cliente, através do seu nome (x), num vetor de Clientes
 * @param v - vetor de clientes em que queremos procurar
 * @param x - nome do cliente em questão
 * @return Retorna o índice do vetor de Clientes em que se encontra o respetivo Cliente, -1 se não existir
 */
int string_sequential_search_c(const vector<Client> &v, string x);

#endif //PROJETO_CLIENTS_FUNCTIONS_H
