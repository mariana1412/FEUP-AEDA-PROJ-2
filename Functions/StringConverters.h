#ifndef PROJETO_STRINGCONVERTERS_H
#define PROJETO_STRINGCONVERTERS_H

#pragma once

#include <string>
#include <vector>
#include "../Classes/Base.h"
/**
 * Funções de conversões de strings para outros tipos
 */
/**
 * @brief Função que converte uma string num vetor de strings
* @param str - string a ser convertida
 * @return Retorna um vetor de strings extraídas da strings como argumento
 */
vector<string> stringToStringVector(string str);
/**
 * @brief Função que converte uma string num vetor de produtos
* @param str - string a ser convertida
 * @return Retorna um vetor de produtos extraídos da strings como argumento
 */
vector<Product> stringToProductVector(string str);
/**
 * @brief Função que converte uma string numa data da class Time
* @param str - string a ser convertida
 * @return Retorna um objeto da classe Time obtido da strings como argumento
 */
Time stringToDate(string str);
/**
 * @brief Função que converte uma string num veículo da class Vehicle
* @param str - string a ser convertida
 * @return Retorna um objeto da classe Vehicle obtido da strings como argumento
 */
Vehicle stringToVehicle(string str);
/**
 * @brief Função que converte uma string num tempo da class Time
* @param str - string a ser convertida
 * @return Retorna um objeto da classe Time obtido da strings como argumento
 */
Time stringToTime(string str);
/**
 * @brief Função que converte uma string numa hora da class Time
* @param str - string a ser convertida
 * @return Retorna um objeto da classe Time obtido da strings como argumento
 */
Time stringToHour(string str);
/**
 * @brief Função que converte uma string numa localização da class Location
* @param str - string a ser convertida
 * @return Retorna um objeto da classe Location obtido da strings como argumento
 */
Location stringToLocation(string str);
/**
 * @brief Função que procura clientes no vetor de clientes através de uma string (nifs dos clientes)
* @param str - nifs dos clientes
 * @param b - base
 * @return Retorna o vetor de clientes da base b se str for o NIF de um cliente
 */
vector<Client> stringToClientVectorSearch(string str, const Base& b);
/**
 * @brief Função que procura deliveries no vetor de deliveries através de uma string (ids das deliveries)
* @param str - ids das deliveries
 * @param b - base
 * @return Retorna o vetor das deliveries da base b se str for os ids deliveries
 */
vector<Delivery> stringToDeliveryVectorSearch(string str, const Base& b);
/**
 * @brief Função que procura products no vetor de products através de uma string (nome do produtos)
* @param str - nome dos produtos
 * @param b - base
 * @return Retorna o vetor de produtos da base b se str for o nome dos produtos
 */
vector<Product> stringToProductVectorSearch(string str, const Restaurant& r);
/**
 * @brief Função que indica se existe um admin com o nif dado
* @param str - nif do cliente
 * @param b - base
 * @return Retorna verdadeiro ou falso consoante o admin com o nif indicado existe
 */
bool stringToAdminSearch(string str, const Base& b);

#endif //PROJETO_STRINGCONVERTERS_H
