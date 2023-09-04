#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


void identify(Base *p)
{
    if (A *a = dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (B *b = dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (C *c = dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Type Id: A" << std::endl;
    }
    catch (const std::exception& e)
    {

    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "Type Id: B" << std::endl;
    }
    catch (const std::exception& e)
    {

    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "Type Id: C" << std::endl;
    }
    catch (const std::exception& e)
    {

    }
}

Base* generate(void)
{
    std::srand(std::time(NULL));
    int randomNumber = std::rand() % 3;
    switch (randomNumber)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}



int main(void)
{
    Base *base = generate();
    identify(base);
    identify(*base);

    delete(base);
    return 0;
}