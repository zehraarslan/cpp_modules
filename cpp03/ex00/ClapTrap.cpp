#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "CrapTrap default constructor called" << std::endl;
    this->name = "Default";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
    std::cout << "ClapTrap named " << name << " constructor called!" << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;   
    *this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->name = clapTrap.getName();
    this->hit_points = clapTrap.getHitPoints();
    this->energy_points = clapTrap.getEnergyPoints();
    this->attack_damage = clapTrap.getAttackDamage();
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap named " << this->name << " destructor called!" << std::endl;
}

std::string ClapTrap::getName() const { return this->name; }
int ClapTrap::getHitPoints() const { return this->hit_points; }
int ClapTrap::getEnergyPoints() const { return this->energy_points; }
int ClapTrap::getAttackDamage() const { return this->attack_damage; }

void ClapTrap::attack(const std::string &target)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "\
        << this->attack_damage << " points of damage!";
        attack_damage++;
        energy_points--;
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
        if (this->energy_points <= 0)
             std::cout<<this->name <<" dead!"<<std::endl;
    }
    else if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout<<this->name <<" doesn't have enough energy";
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
    }
    else
    {
        std::cout<<this->name <<" dead!"<<std::endl;
    }

}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name << " taked " << amount << " points of damage!";
        if (this->hit_points > amount)
            hit_points -= amount;
        else
            this->hit_points = 0;
        this->energy_points--;
        if (this->attack_damage >= 1)
            attack_damage--;
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
        if (this->hit_points <= 0 || this->energy_points <= 0)
             std::cout<<this->name <<" dead!"<<std::endl;
    }
    else if (hit_points < amount)
    {
        std::cout<<this->name << " doesn't have enough hit point";
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
    }
    else if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout<<this->name <<" doesn't have enough energy";
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
    }
    else
    {
        std::cout<<this->name <<" dead!"<<std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points > 0 && this->energy_points > 0)
    {
        std::cout << "ClapTrap " << this->name <<" self-repaired " << amount << " hit points ";
        hit_points += amount;
        energy_points--;
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
    }
    else if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout<<this->name <<" doesn't have enough energy";
        std::cout <<  "      ->.  Hit points : " << this->hit_points << "  Energy points : " << this->energy_points << "    Attack damage : " << this->attack_damage << std::endl;
    }
    else
    {
        std::cout<<this->name <<" dead!"<<std::endl;
    }
}