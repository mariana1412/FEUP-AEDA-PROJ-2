#ifndef PROJETO_COMPANY_H
#define PROJETO_COMPANY_H
#include<string>
#include "Base.h"
using namespace std;
/**
 * Base da empresa Company
 */

class Company{
private:
    string boss;/**<Nome do patrão*/
    int boss_nif;/**<NIF do patrão*/
    Base Porto;/**< Base do Porto*/
    Base Lisboa;/**<Base de Lisboa*/
    Base Faro;/**<Base de Faro*/
public:
    /**
 * @brief Construtor por default da classe Company
 */
    Company(){};
    /**
 * @brief Construtor da classe Company
     * @param Boss - nome do patrão
     * @param boss_nif - NIF do patrão
     * @param Porto - base do Porto
     * @param Lisboa - base de Lisboa
     * @param Faro - base de Faro
 */
    Company(string Boss, int boss_nif, Base Porto, Base Lisboa, Base Faro);
    /*
     * @brief Permite definir o nome do patrão
     * @param boss - nome do patrão
     */
    void setBoss(string boss);
    /*
     * @brief Permite obter o nome do patrão
     * @return Retorna o nome do patrão
     */
    string getBoss()const;
    /*
     * @brief Permite definir o NIF do patrão
     * @param nif - NIF do patrão
     */
    void setBossNif(int nif);
    /*
     * @brief Permite obter o NIF do patrão
     * @return Retorna o NIF do patrão
     */
    int getBossNif() const;
};


#endif //PROJETO_COMPANY_H
