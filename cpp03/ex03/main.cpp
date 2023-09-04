#include "DiamondTrap.hpp"

int main()
{
   DiamondTrap trap("Zehra");
   trap.whoAmI();
   trap.attack("Zombie");
   trap.highFivesGuys();
   trap.takeDamage(3);
   trap.beRepaired(11);
   trap.guardGate();
   trap.attack("Zombie");
   trap.attack("Zombie");
   trap.attack("Zombie");
   trap.attack("Zombie");
}