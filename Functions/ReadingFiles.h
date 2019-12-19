#ifndef PROJETO_READINGFILES_H
#define PROJETO_READINGFILES_H

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Base.h"


/**
 * Funções de leitura/extração dos ficheiros
 */


/**
 * @brief Função que extrai informação do ficheiro de clientes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void extract_Clients(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que extrai informação do ficheiro de restaurantes
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void extract_Restaurants(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que extrai informação do ficheiro de entregas
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void extract_Deliveries(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que extrai informação do ficheiro de funcionários
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 */
void extract_Employees(Base& baseP, Base& baseL, Base& baseF);
/**
 * @brief Função que extrai informação do ficheiro de bases
 * @param Porto - toda a informação da base do Porto
 * @param Lisboa - toda a informação da base de Lisboa
 * @param Faro - toda a informação da base de Faro
 * @param boss_nif - NIF do patrão
 * @param boss - nome do patrão
 */
void extract_Bases(Base& baseP, Base& baseL, Base& baseF, string &boss, int &boss_nif);




#endif //PROJETO_READINGFILES_H
