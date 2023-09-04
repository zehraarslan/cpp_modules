#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal* j = new Dog();
    Animal* i = new Cat();
	Animal *animal[2];
	animal[0] = j;
	animal[1] = i;
	animal[0]->makeSound();
	animal[1]->makeSound();
	std::cout << animal[0]->getType() << "'s idea 1 is " << animal[0]->getBrain()->getIdeas(0) << std::endl;
	std::cout << animal[1]->getType() << "'s idea 1 is " << animal[1]->getBrain()->getIdeas(0) << std::endl;

	delete j;
	delete i;


	Animal* animals[4] = {new Cat, new Dog, new Dog, new Cat};
	int index = -1;
	while (++index < 4)
	{
		animals[index]->makeSound();
		std::cout << "Idea : " << animals[index]->getBrain()->getIdeas(2) << std::endl;
		delete animals[index];
	}

		std::cout << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "Idea : " << tmp.getBrain()->getIdeas(10) << std::endl;
	}
	std::cout << "Idea : " << basic.getBrain()->getIdeas(10) << std::endl;
	return (0);
}