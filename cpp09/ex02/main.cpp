#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout <<  "Error: missing argument." << std::endl;
        return 1;
    }

    PmergeMe sort;
    sort.fordJohnson(argc, argv);

    return 0;
}