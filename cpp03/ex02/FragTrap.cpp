#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->name = "Default";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string name)
{
    std::cout << "FragTrap named " << name << " constructor called!" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    this->hit_points = fragTrap.getHitPoints();
    this->energy_points = fragTrap.getEnergyPoints();
    this->attack_damage = fragTrap.getAttackDamage();
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap named " << this->name << " destructor called!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " high five guys!" << std::endl;
}