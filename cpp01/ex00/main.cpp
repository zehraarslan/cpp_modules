#include "Zombie.hpp"

int main()
{
   Zombie fooZombie;
   fooZombie.setName("Foo");
   fooZombie.announce();

   Zombie *sticZombie = newZombie("Stic");
   randomZombie("Bob");
   delete sticZombie;
}