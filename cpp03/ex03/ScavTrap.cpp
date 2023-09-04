#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string name)
{
    std::cout << "ScavTrap named " << name << " constructor called!" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    this->name = scavTrap.getName();
    this->hit_points = scavTrap.getHitPoints();
    this->energy_points = scavTrap.getEnergyPoints();
    this->attack_damage = scavTrap.getAttackDamage();
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap named " << this->name << " destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string target)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "\
        << this->attack_damage << " points of damage!";
        attack_damage++;
        energy_points--;
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "   Attack damage : " << this->attack_damage << std::endl;
        if (this->energy_points <= 0)
             std::cout<<this->name <<" dead!"<<std::endl;
    }
    else if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout<<this->name <<" doesn't have enough energy";
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "   Attack damage : " << this->attack_damage << std::endl;
    }
    else
    {
        std::cout<<this->name <<" dead!"<<std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << this->getName() << " is in guard door gate mode." << std::endl;
}

