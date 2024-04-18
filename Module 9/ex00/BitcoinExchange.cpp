#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error whilst opening file.";
        return ;
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "File is empty.";
        file.close();
        exit(0);
    }
    
    std::string line;
    std::getline(file, line);
    for (int i = 1; std::getline(file, line); i++)
    {
        if (line.size() < 12)
            std::cerr << "Error at line " << i << ": \"" << line << "\"" << std::endl;
        if (line[4] != '-' || line[7] != '-')
            std::cerr << "Invalid date at line " << i << ": \"" << line << "\"" << std::endl;
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);

        std::string yearStr = line.substr(0, 4);
        std::string monthStr = line.substr(5, 2);
        std::string dayStr = line.substr(8, 2);

        if (!std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) ||
            !std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) ||
            !std::all_of(dayStr.begin(), dayStr.end(), ::isdigit))
        {
            std::cerr << "Invalid date at line " << i << ": \"" << line << "\"" << std::endl;
        }


        int year = std::atoi(date.substr(0, 4).c_str());
        int month = std::atoi(date.substr(5, 2).c_str());
        int day = std::atoi(date.substr(8, 2).c_str());

        double val = std::atof(value.c_str());

        std::tm time = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, NULL};;
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
        if (this->file.is_open())
            this->file.close();
        this->file.open(filename);
        this->bitcoinValues = other.bitcoinValues;
    }
    return *this;
}

void BitcoinExchange::compareVal(std::string datestr, double date, double val)
{
    std::map<double, double>::iterator it = this->bitcoinValues.lower_bound(date);
    if (it != this->bitcoinValues.begin())
    {
        --it; 
        std::cout << datestr << " => " << val << " => " << it->second * val << std::endl;
    }
    else
    {
        std::cout << "No previous date found in the map." << std::endl;
    }
}