#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const std::string idea);
    Brain(const Brain &brain);
    Brain & operator=(const Brain &brain);
    ~Brain();

    std::string getIdeas(int i);
    void setIdeas(std::string idea);
};

#endif