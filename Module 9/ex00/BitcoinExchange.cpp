#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
    this->file.open(filename.c_str());
    if (!file)
    {
        std::cerr << "Error whilst opening file containing data." << std::endl;
        exit(0);
    }
    
    std::string line;
    std::getline(file, line);
    for (int i = 1; std::getline(file, line); i++)
    {
        if (line.size() < 12)
            std::cerr << "Error at line " << i << ": \"" << line << "\" IN DATA FILE" << std::endl;
        if (line[4] != '-' || line[7] != '-')
            std::cerr << "Error: Invalid date at line " << i << ": \"" << line << "\" IN DATA FILE" << std::endl;
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);

        std::string yearStr = line.substr(0, 4);
        std::string monthStr = line.substr(5, 2);
        std::string dayStr = line.substr(8, 2);

        if (!allDigits(yearStr) || !allDigits(monthStr) || !allDigits(dayStr))
            std::cerr << "Error: Invalid date at line " << i << ": \"" << line << "\" IN DATA FILE" << std::endl;

        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());

        double val = std::atof(value.c_str());

        std::tm time = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, 0};
        double unixTime = std::mktime(&time);

        this->bitcoinValues.insert(std::pair<double, double>(unixTime, val));
    }    
    file.close();
}

BitcoinExchange::~BitcoinExchange()
{
    this->file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->filename = other.filename;
        if (this->file.is_open())
            this->file.close();
        this->file.open(other.filename);
        this->bitcoinValues = other.bitcoinValues;
    }
    return (*this);
}

bool BitcoinExchange::allDigits(const std::string& str) 
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) 
    {    
        if(!std::isdigit(*it))
            return false;
    }
    return true;
}

void BitcoinExchange::compareVal(std::string datestr, double date, double val)
{
    std::map<double, double>::iterator it = this->bitcoinValues.lower_bound(date);
    if (it == this->bitcoinValues.end() || it->first != date) 
    {
        if (it != this->bitcoinValues.begin())
            --it;  
        else 
        {
            std::cout << "Error: No previous date found in the map." << std::endl;
            return;
        }
    }
    std::cout << datestr << " => " << val << " => " << it->second * (float)val << std::endl;
}