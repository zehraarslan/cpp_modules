#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "CrapTrap default constructor called" << std::endl;
    this->name = "Default";
    ClapTrap("Default_clap_name");
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

DiamondTrap::DiamondTrap(const std::string name)
{
    std::cout << "DiamondTrap named " << name << " constructor called!" << std::endl;
    this->name = name;
    //ClapTrap(name + "_clap_name");
    ClapTrap::name = this->name + "_clap_name";
    FragTrap::hit_points = 100;
    ScavTrap::energy_points = 50;
    FragTrap::attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    this->name = diamondTrap.name;
    ClapTrap(diamondTrap.name + "_clap_name");
    FragTrap::hit_points = diamondTrap.getHitPoints();
    ScavTrap::energy_points = diamondTrap.getEnergyPoints();
    FragTrap::attack_damage = diamondTrap.getAttackDamage();
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap named " << this->name << " destructor called!" << std::endl;
}


void DiamondTrap::whoAmI()
{
    std::cout << "Diamond name : " << this->name << "   ClapTrap name : " << ClapTrap::name << std::endl;
}