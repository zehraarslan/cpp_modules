#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"


class Zombie
{
    private:
       std::string name;
    public:
        Zombie();
        ~Zombie();
        std::string getName();
        void    setName(std::string name);
        void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomZombie(std::string name);

#endif