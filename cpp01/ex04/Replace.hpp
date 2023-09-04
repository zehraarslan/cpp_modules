#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
private:
    std::string fileName;
    std::string str;
    std::string newStr;
    std::string data;
public:
    Replace(std::string fileName, std::string str, std::string newStr);
    ~Replace();
    void replaceFile();
};


#endif