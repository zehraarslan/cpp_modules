#include "Convert.hpp"

Convert::Convert()
{
    //std::cout << "[Convert] Default constructor called\n";
}

Convert::Convert(const Convert &convert)
{
    //std::cout << "[Convert] Copy constructor called\n";
}

Convert &Convert::operator=(const Convert &convert)
{
    //std::cout << "[Convert] Copy constructor called\n";
    return *this;
}

Convert::~Convert()
{
    //std::cout << "[Convert] Destructor called\n";
}

int Convert::isNan(std::string argv)
{
    if (argv == "-inff" || argv == "+inff" || argv == "nanf")
        return (1);
    if (argv == "-inf" || argv == "+inf" || argv == "nan")
        return (1);
    return (0);
}

void Convert::typeDetection(std::string argv)
{
    this->toChar(argv);
    this->toInt(argv);
    this->toFloat(argv);
    this->toDouble(argv);
}

void Convert::toChar(std::string argv)
{
    int number = 0;

    if (isNan(argv))
    {
        std::cout << "char: impossible" << std::endl;
        return ;
    }
    try
    {
        number = stoi(argv);
    }
    catch (const std::exception& e)
    {
        if (isalpha(argv[0]) && !argv[1])
        {
            std::cout << "char: " << argv[0] << std::endl;
            return ;
        }
        std::cout << "char: Non displayable" << std::endl;
        return ;
    }
    if (number >= 32 && number <= 126)
    {
        std::cout << "char: " << static_cast<char>(number) << std::endl;
        return ;
    }
    else
        std::cout << "char: Non displayable" << std::endl;
}

void Convert::toInt(std::string argv)
{
    int number = 0;
    if (isNan(argv))
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    try
    {
        number = stoi(argv);
    }
    catch (const std::exception& e)
    {
        if (isalpha(argv[0]) && !argv[1])
        {
            std::cout << "int: " << static_cast<int>(argv[0]) << std::endl;
            return ;
        }
        std::cout << "int: Non displayable" << std::endl;
        return ;
    }
    std::cout << "int: " << number << std::endl;
}

void Convert::toFloat(std::string argv)
{
    float number = 0;

    if (isNan(argv))
    {
        std::cout << "float: nanf" << std::endl;
        return ;
    }
    try
    {    
        number = std::stof(argv);
    }
    catch (const std::exception& e)
    {
        if (isalpha(argv[0]) && !argv[1])
        {
            std::cout << "float: " << static_cast<float>(argv[0]) << ".0f" << std::endl;
            return ;
        }
        std::cout << "float: Non displayable" << std::endl;
        return ;
    }
    std::cout << "float: " << number;
    if (number - std::stoi(argv) == 0)
    {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

void Convert::toDouble(std::string argv)
{
    double number = 0;

    if (isNan(argv))
    {
        std::cout << "double: nan" << std::endl;
        return ;
    }
    try
    {
        number = std::stod(argv);
    }
    catch (const std::exception& e)
    {
        if (isalpha(argv[0]) && !argv[1])
        {
            std::cout << "double: " << static_cast<double>(argv[0]) << ".0" << std::endl;
            return ;
        }
        std::cout << "double: Non displayable" << std::endl;
        return ;
    }
    std::cout << "double: " << number;
    if (number - std::stoi(argv) == 0)
    {
        std::cout << ".0";
    }
}