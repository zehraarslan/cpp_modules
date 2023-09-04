#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <cstring>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string name);
    ~HumanB();
    std::string getName() const;
    void setName(std::string name);
    void setWeapon(Weapon &wepaon);
    void attack();
};

#endif