#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
    private:
        std::string filename;
        std::ifstream file;
        std::map<double, double> bitcoinValues;
    public:
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        bool allDigits(const std::string& str);

        void compareVal(std::string datestr, double date, double val);
};

#endif