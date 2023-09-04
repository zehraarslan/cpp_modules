#include "Replace.hpp"

Replace::Replace(std::string fileName, std::string str, std::string newStr)
{
    this->fileName = fileName;
    this->str = str;
    this->newStr = newStr;
}

Replace::~Replace() {}

void Replace::replaceFile()
{
    std::string line;
    size_t  pos;
    std::string output_file_name;

    std::ifstream inFile(this->fileName);
    if (!inFile)
    {
        std::cout << "Error occurred while reading." << std::endl;
        return ;
    }

    output_file_name = this->fileName + ".replace";
    std::ofstream outputFile(output_file_name);
    if (!outputFile)
    {
        std::cout << "A file creation error has occurred." << std::endl;
        return ;
    }

    while (getline(inFile, line))
    {
        pos = 0;
        while(line.find(str, pos) != std::string::npos)
        {
            pos = line.find(str, pos);
            line.erase(pos, this->str.length());
            line.insert(pos, this->newStr);
            pos += newStr.length();
        }
        outputFile << line << std::endl;
    }
    inFile.close();
    outputFile.close();
}