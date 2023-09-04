#include "ScavTrap.hpp"

int main()
{
   ScavTrap scavTrap("Zehra");

   scavTrap.attack("Zombie");
	scavTrap.guardGate();
	scavTrap.takeDamage(3);
	scavTrap.beRepaired(11);
	scavTrap.takeDamage(120);
	scavTrap.beRepaired(11);
}