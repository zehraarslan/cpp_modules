#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("Zehra");

    clap.attack("Zombie");
    clap.attack("Zombie");
    clap.attack("Zombie");
    clap.takeDamage(5);
    clap.beRepaired(5);
    clap.beRepaired(5);

    return 0;
}