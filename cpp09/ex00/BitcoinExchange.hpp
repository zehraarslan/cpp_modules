#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, double> dataMap;
public:
    BitcoinExchange();
    BitcoinExchange (const BitcoinExchange &btc);
    BitcoinExchange &operator=(const BitcoinExchange &btc);
    ~BitcoinExchange();

    int getValues(std::string fileName);
    int dateCheck(std::string date);
    int valueCheck(float value);
    int control(std::string input);
    int exchange(std::string date, double value);
    std::string trim(std::string input);
};


#endif