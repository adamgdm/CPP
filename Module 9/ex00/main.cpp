#include "BitcoinExchange.hpp"

int checkValueStr(const std::string& valueStr) {
    for (std::string::size_type i = 0; i < valueStr.size(); ++i) {
    char c = valueStr[i];
    if (!isdigit(c) && c != '.') {
        return 0;
    }
}
    return 1;
}

int main(int ac, char **av)
{
    (void)ac;
    std::ifstream file(av[1]);
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "File is empty." << std::endl;
        file.close();
        return 0;
    }

    BitcoinExchange exchange("cpp_09/data.csv");
    
    std::string line;
    //skip the first line
    std::getline(file, line);
    for (int i = 1; std::getline(file, line); i++)
    {

        if (line.size() < 14 
            || std::count(line.begin(), line.end(), '|') != 1 
            || std::count(line.begin(), line.end(), '.') > 1)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string yearStr = line.substr(0, 4);
        std::string monthStr = line.substr(5, 2);
        std::string dayStr = line.substr(8, 2);
        std::string valueStr = line.substr(13);
        int year = std::atoi(yearStr.c_str());
        int month = std::atoi(monthStr.c_str());
        int day = std::atoi(dayStr.c_str());
        double value = std::atof(valueStr.c_str());
        std::string date = line.substr(0, 10);
        std::tm time = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, NULL};

        // Manually parse the date
        if (line[4] != '-' || line[7] != '-')
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Check if year, month, and day are all digits
        if (!std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) ||
            !std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) ||
            !std::all_of(dayStr.begin(), dayStr.end(), ::isdigit))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }


        if (month < 1 || month > 12 || day < 1 || day > 31)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        } 
        if (year < 2009 || year > 2030)
        {
            std::cerr << "Error: Years ranges from 2009 to 2030, line " << i + 1 << ": \"" << line << "\"" << std::endl;
            continue;
        }
        if ((month == 2 && day > 29 && year % 4 == 0) || (month == 2 && day > 28 && year % 4 != 0))
        {
            std::cerr << "Error: Invalid date at line " << i + 1 << ": \"" << line << "\"" << std::endl;
            continue;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            std::cerr << "Error: Invalid date at line " << i + 1 << ": \"" << line << "\"" << std::endl;
            continue;
        }
        else if (day > 31)
        {
            std::cerr << "Error: Invalid date at line " << i + 1 << ": \"" << line << "\"" << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive integer" << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number" << std::endl;
            continue;
        }

        double unixTime = std::mktime(&time);

        exchange.compareVal(date, unixTime, value);
    }

    return 0;
}