#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Span sp3 = Span(5);
        sp3.addNumber(2);
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try
    {
        Span sp2(5);
        std::vector<int> numbers;
        numbers.push_back(12);
        numbers.push_back(12);
        numbers.push_back(13);
        numbers.push_back(14);
        numbers.push_back(15);
        numbers.push_back(16);
        numbers.push_back(17);
        numbers.push_back(18);
        sp2.addNumber(numbers.begin() + 3, numbers.end()- 1);
        sp2.printNumbers();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   

    
    return 0;
}