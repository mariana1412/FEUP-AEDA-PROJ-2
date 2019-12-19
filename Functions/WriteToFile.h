#ifndef PROJETO_WRITETOFILE_H
#define PROJETO_WRITETOFILE_H

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "../Classes/Company.h"
/**
 * Funções de escrita/atualização dos ficheiros
 */


/**
 * @brief Função que escreve a informação do ficheiro de clientes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */

void write_Clients(const Base& baseP,const Base& baseL,const Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de restaurantes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Restaurants(const Base& baseP,const Base& baseL,const Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de entregas
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Deliveries(const Base& baseP,const Base& baseL,const Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de funcionários
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void write_Employees(const Base& baseP,const Base& baseL,const Base& baseF);
/**
 * @brief Função que escreve a informação do ficheiro de bases
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @param nif - NIF do patrão
 * @param boss - nome do patrão
 */
void write_Bases(string boss, int nif, Base& baseP,const Base& baseL,const Base& baseF);


#endif //PROJETO_WRITETOFILE_H
