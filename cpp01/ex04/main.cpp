
#include "Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage : <filename> <string_to_replace> <stirng_to_replace_by>" << std::endl;
        return (EXIT_FAILURE);
    }

    Replace replace(argv[1], argv[2], argv[3]);
    replace.replaceFile();
}