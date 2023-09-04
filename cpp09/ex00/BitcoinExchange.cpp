#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){ }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc)
{
    *this = btc;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
    this->dataMap = btc.dataMap;
    return *this;
}

BitcoinExchange::~BitcoinExchange() { }

int BitcoinExchange::getValues(std::string fileName)
{
    std::string dataInput;
    std::string dataName = "data.csv";
    std::ifstream data(dataName.c_str());
    if(!data)
    {
        std::cout << "Error: file not opened." << std::endl;
        return 1;
    }
    while (std::getline(data, dataInput))
    {
        if (dataInput == "date,exchange_rate")
            continue;
        std::stringstream line(dataInput);
        std::string dataDate;
        double dataValue;

        std::getline(line, dataDate, ',');
        line >> dataValue;
        dataMap.insert(std::make_pair(dataDate, dataValue));
    }
    data.close();


    std::string fileInput;
    std::ifstream file(fileName.c_str());

    if (!file)
    {
        std::cout << "Error: file not opened." << std::endl;
        return 1;
    }
    while (std::getline(file, fileInput))
    {
        if (fileInput.length() < 2)
        {
            continue;
        }
        
        std::stringstream fileLine(fileInput);
        std::string fileDate;
        std::string fileValue_string;
        float fileValue;

        if ((std::getline(fileLine, fileDate, '|')) && (fileLine >> fileValue_string))
        {
            fileDate = trim(fileDate);
            fileValue_string = trim(fileValue_string);

            if (fileDate == "date" && fileValue_string == "value")
                continue;


            if (control(fileValue_string))
                continue;
            fileValue = std::atof(fileValue_string.c_str());

            if (dateCheck(fileDate))
            {
                std::cout << "Error: invalid date =>"  << fileDate << std::endl;
                continue;
            }
            if (valueCheck(fileValue))
                continue;
            
            exchange(fileDate, fileValue);
        }
        else
        {
            std::cout << "Error: bad input => " << fileInput << std::endl;
        }
    }
    file.close();

    return 0;
}

int BitcoinExchange::dateCheck(std::string fileDate)
{
    if (fileDate.length() != 10)
        return 1;

    if (fileDate[4] != '-' || fileDate[7] != '-')
        return 1;

    for (int i = 0; i < fileDate.size() - 1; i++)
    {
        if (i != 4 && i != 7)
        {
            if(!isdigit(fileDate[i]))
                return 1;
        }
    }
    

    int year = atoi(fileDate.substr(0, 4).c_str());
    int month = atoi(fileDate.substr(5, 2).c_str());
    int day = atoi(fileDate.substr(8, 2).c_str());
    int monthControl1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int monthControl2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (!(year >= 2001 && year <= 2023))
        return 1;

    if (!(month >= 1 && month <= 12))
        return 1;

    if (year % 4 != 0)
    {
        if (!(day >= 1 && day <= monthControl1[month - 1]))
            return 1;
    }
    else
    {
        if (!(day >= 1 && day <= monthControl2[month - 1]))
            return 1;
    }
    return 0;
}

int BitcoinExchange::valueCheck(float value)
{
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }

    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    return 0;
}

int BitcoinExchange::exchange(std::string date, double value)
{
    
    if (dataMap.find(date) != dataMap.end())
    {
        std::cout << date << " => " << value << " = " << dataMap[date]*value << std::endl;
    }
    else
    {
        std::map<std::string, double>::iterator end = dataMap.end();
        decltype(end) iter = dataMap.lower_bound(date);
        if (dataMap.begin()->first != iter->first)
            iter--;
        std::cout << date << " => " << value << " = " << iter->second*value << std::endl;
    }

    return 0;
}

std::string BitcoinExchange::trim(std::string input)
{
    int begin = 0;
    int end = input.length() - 1;


    while (begin < input.length())
    {
        if (isspace(input[begin]))
        {
            input[begin] = ' ';
        }
        else
            break;
        begin++;
    }
    
    while (end >= 0)
    {
        if (isspace(input[end]))
        {
            input[end] = ' ';
        }
        else
            break;
        end--;
    }

    size_t first = input.find_first_not_of(' ');
    if (std::string::npos == first) {
        return "";
    }
    size_t last = input.find_last_not_of(' ');
    return input.substr(first, (last - first + 1));
}

int BitcoinExchange::control(std::string fileValue_string)
{

    int point = 0;
    for (int i = 0; i < fileValue_string.length(); i++)
    {
        if (fileValue_string[i] == '.')
        {
            if (point == 0)
            {
                point = 1;
            }
            else
            {
                std::cout << "Error: invalid number => " << fileValue_string << std::endl;
                return 1;
            }
        }
        if (!isdigit(fileValue_string[i]) && fileValue_string[i] != '.')
        {
            if (i == 0 && fileValue_string[i] == '-')
            {
                continue;
            }
            else
            {
                std::cout << "Error: invalid number => " << fileValue_string << std::endl;
                return 1;
            }
        }
    }

    return 0;
}