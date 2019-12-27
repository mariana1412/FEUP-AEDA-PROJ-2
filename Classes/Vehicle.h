#ifndef UGH_EATS_VEHICLE_H
#define UGH_EATS_VEHICLE_H

#pragma once
#include "Time.h"
#include <iostream>

using namespace std;
/**
 * Veículo
 */


class Vehicle{
private:
    string brand;/**< marca do veículo*/
    string type;/**< tipo de veículo*/
    Time date;/**<data de aquisição do veículo*/
    string lic_plate; /**<matrícula do veículo*/
    int total_del; /**<número total de entregas efetuadas*/
    int total_km; /**<número total de kms percorridos*/
    int n_del; /**<numero de entregas desde a ultima manutençao*/
    int n_min; /**<numero de minutos até terminar a manutençao */
public:
    /**
 * @brief Construtor por default da classe Veículo
 */
    Vehicle();
    /**
     * @brief Construtor  da classe Veículo
     * @param brand - marca do veículo
     * @param type - tipo do veículo
     * @param date - data de aquisição do veículo
     * @param n_del - numero de entregas desde a ultima manutençao
     * @param n_min - numero de minutos até terminar a manutençao
 */
    Vehicle(string brand, string type, Time date, string lic_plate, int total_del, int total_km, int n_del, int n_min);
    /**
    * @brief Permite obter a marca do veículo
    * @return Retorna a marca do veículo
*/
    string getBrand() const;
    /**
* @brief Permite obter o tipo do veículo
 * @return Retorna o tipo do veículo
*/
    string getType() const;
    /**
* @brief Permite obter a data de aquisição do veículo
 * @return Retorna a data de aquisição do veículo
*/
    Time getDate() const;
    /**
* @brief Permite obter a matrícula do veículo
* @return Retorna a matrícula do veículo
*/
    string getLicPlate() const;

    /**
* @brief Permite obter o número total de entregas do veículo
* @return Retorna o número total de entregas do veículo
*/
    int getTotalDel() const;

    /**
* @brief Permite obter o número de kms percorridos pelo veículo
* @return Retorna a número de kms percorridos pelo veículo
*/
    int getTotalKm() const;

    /**
* @brief Permite obter o numero de entregas desde a ultima manutençao
 * @return Retorna o numero de entregas desde a ultima manutençao
*/
    int getNDel() const;

    /**
    * @brief Permite obter o numero de minutos até terminar a manutençao
    * @return Retorna o numero de minutos até terminar a manutençao
    */
    int getNMin() const;
    /**
* @brief Permite definir a marca do veículo
     * @param brand - marca do veículo

*/
    void setBrand(string brand);
    /**
* @brief Permite definir o tipo do veículo
 * @param type - tipo do veículo
*/
    void setType(string type);
    /**
* @brief Permite definir a data de aquisição do veículo
 * @param date - data de aquisição do veículo
*/
    void setDate(Time date);

    /**
* @brief Permite definir a matrícula do veículo
 * @param plate - matrícula do veículo
*/
    void setLicPlate(string plate);

    /**
* @brief Permite definir o número total de entregas do veículo
 * @param del - número total de entregas do veículo
*/
    void setTotalDel(int del);

    /**
* @brief Permite definir o número de kms percorridos pelo veículo
 * @param km - número de kms percorridos pelo veículo
*/
    void setTotalKm(int km);

    /**
* @brief Permite definir o numero de entregas desde a ultima manutençao
* @param ndel - numero de entregas desde a ultima manutençao
*/
    void setNDel(int ndel);

    /**
    * @brief Permite definir o numero de minutos até terminar a manutençao
    * @param min - numero de minutos até terminar a manutençao
    */
    void setNMin(int min);
/**
 * @brief Adiciona 1 ao numero de entrgas do veiculo desde a ultima manutençao
 */

    void addDelivery();

/**
 * @brief Permite fazer reset (tornar 0) numero de entregas desde a ultima manutençao
 */
   void resetNDel();

/**
* @brief Permite mostrar no ecrã o veiculo de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param v - veiculo que pretendemos mostrar no ecrã
 */
    friend ostream& operator<<(ostream& os, const Vehicle& v);
/**
* @brief Permite comparar veículos (saber qual é o menor/maior)
* @param v1 - Veículo que é usado na comparação
* @return Retorna um booleano para o resultado da comparação
 */
    bool operator<(const Vehicle &v1) const;
/**
* @brief Permite comparar veículos (saber se são iguais)
* @param v1 - Veículo que é usado na comparação
* @return Retorna um booleano para o resultado da comparação
 */
    bool operator==(const Vehicle &v1) const;

    /**
     * @brief Permite mostrar no ecrã de forma "formatada" as características do veículo
     */
    void PrintVehicle() const;
};


#endif //UGH_EATS_VEHICLE_H
