#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>

class Convert
{
private:
    
public:
    Convert();
    Convert(const Convert &convert);
    Convert &operator=(const Convert &convert);
    ~Convert();

    void typeDetection(std::string argv);
    void toChar(std::string argv);
    void toInt(std::string argv);
    void toFloat(std::string argv);
    void toDouble(std::string argv);
    int isNan(std::string argv);
};

#endif