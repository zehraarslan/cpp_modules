#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);

    std::vector<int>::iterator iter;
    try
    {
        iter = easyfind(vec, 34);
        std::cout << *iter << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        iter = easyfind(vec, 30);
        std::cout << *iter << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}