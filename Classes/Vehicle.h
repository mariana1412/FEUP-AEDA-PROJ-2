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
 */
    Vehicle(string brand, string type, Time date);
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
* @brief Permite mostrar no ecrã o veiculo de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param v - veiculo que pretendemos mostrar no ecrã
 */
    friend ostream& operator<<(ostream& os, const Vehicle& v);

};


#endif //UGH_EATS_VEHICLE_H
