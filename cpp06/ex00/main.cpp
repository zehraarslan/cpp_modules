#include <iostream>
#include <string>
#include <ctype.h>
#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Kullanım: ./convert <number>" << std::endl;
        return 0;
    }
    Convert convert;
    convert.typeDetection(argv[1]);
}
