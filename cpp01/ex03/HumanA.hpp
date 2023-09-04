#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <cstring>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    std::string getName() const;
    void setName(std::string name);
    void setWeapon(Weapon &wepaon);
    void attack();
};

#endif