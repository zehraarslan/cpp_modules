#include "Zombie.hpp"

void randomZombie(std::string name)
{
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}