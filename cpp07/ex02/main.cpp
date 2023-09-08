#include "Array.hpp"

#define RANGE 15
int main(void)
{
    Array<int> numbers_null;
    Array<std::string> chr_null;
    
    Array<int> numbers(RANGE);
    std::srand(std::time(NULL));
    for (int i = 0; i < RANGE; i++)
    {
        
        try
        {
           numbers[i] = std::rand();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " <<e.what() << '\n';
        }
    }
    for (int i = 0; i < RANGE; i++)
    {
        std::cout << numbers[i] << std::endl;
    }
    

    Array<double> numbers_d(RANGE);
    for (int i = 0; i < RANGE; i++)
    {
        
        try
        {
           numbers_d[i] = std::rand();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Exception: " <<e.what() << '\n';
        }
    }
     for (int i = 0; i < RANGE; i++)
    {
        std::cout << numbers_d[i] << std::endl;
    }

    Array<char> chr(RANGE);
    for (int i = 0; i < RANGE; i++)
    {
        try
        {
            int randomNumber = std::rand() % 26;
            chr[i] = 'A' + randomNumber;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    for (int i = 0; i < RANGE; i++)
    {
        std::cout << chr[i] << std::endl;
    }

    try
    {
        std::cout << "numbers size: " << numbers.size() << std::endl;
        numbers[20] = 5;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " <<e.what() << '\n';
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[RANGE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        chr[RANGE] = 'A';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}