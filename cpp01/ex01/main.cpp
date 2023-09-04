#include "Zombie.hpp"

int main()
{
    Zombie *zombies = zombieHorde(7, "Bob");
    delete[] zombies;
}