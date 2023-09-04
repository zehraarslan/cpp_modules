#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: missing or excess arguments." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.getValues(argv[1]);
    return 0;

}