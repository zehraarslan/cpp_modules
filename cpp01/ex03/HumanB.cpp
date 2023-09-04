#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB() {}

std::string HumanB::getName() const
{
    return this->name;
}

void HumanB::setName(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << " attacks with a " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " is attacking unarmed!" << std::endl;
}