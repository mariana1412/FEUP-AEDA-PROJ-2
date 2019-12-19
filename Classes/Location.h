#ifndef UGH_EATS_LOCATION_H
#define UGH_EATS_LOCATION_H

#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;
/**
 * Localização exata
 */

class Location{
private:
    string address;/**< morada da localização*/
    string county;/**< concelho da localização*/
    string gps;/**<coordenadas gps da localização*/
public:
    /**
 * @brief Construtor por default da classe Location
 */
    Location();
    /**
 * @brief Construtor da classe Base
     * @param address - morada da localização
     * @param county - concelho da localização
     * @param gps - coordenada gps da localização no formato [latitude;longitude]
 */
    Location(string address, string county, string gps);
    /**
 * @brief Permite obter a morada da localização
     * @return Retorna a morada da localização
 */
    string getAddress() const;
    /**
* @brief Permite obter o concelho da localização
 * @return Retorna o concelho da localização
*/
    string getCounty() const;
    /**
* @brief Permite obter as coordenadas gps da localização
 * @return Retorna as coordenadas gps da localização
*/
    string getGps() const;
    /**
* @brief Permite definir a morada da localização
 * @param address - morada da localização
*/
    void setAddress(string address);
    /**
* @brief Permite definir o concelho da localização
 * @param county - concelho da localização
*/
    void setCounty(string county);
    /**
* @brief Permite definir as coordenadas gps da localização
 * @param gps - coordenadas gps da localização no formato [latitude;longitude]
*/
    void setGps(string gps);

    /**
* @brief Permite mostrar no ecrã a localização de forma formatada
* @param os - ostream para onde é enviada a mensagem formatada
* @param l - localização que pretendemos mostrar no ecrã
 */
    friend ostream& operator<<(ostream& os, const Location& l);
};


#endif //UGH_EATS_LOCATION_H
