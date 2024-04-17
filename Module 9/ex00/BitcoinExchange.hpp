#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <regex>
#include <string>
#include <ctime>

class BitcoinExchange
{
    private:
        std::string filename;
        // file stream
        std::ifstream file;
        // map
        std::map<double, double> bitcoinValues;
    public:
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        void compareVal(std::string datestr, double val1, double val2);
};

#endif