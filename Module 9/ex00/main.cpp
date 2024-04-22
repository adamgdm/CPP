#include "BitcoinExchange.hpp"

int checkValueStr(const std::string& valueStr)
{
    int i = 0;
    bool digitPart = true;

    while (i < (int)valueStr.size()) 
    {
        char c = valueStr[i];
        if (digitPart) 
        {
            if (!isdigit(c) && c != '.' && !(i == 0 && (c == '+' || c == '-'))) 
            {
                if (isspace(c))
                    digitPart = false; 
                else
                    return 0;
            }
        } 
        else 
        {
            if (!isspace(c))
                return 0;
        }
        i++;
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

    BitcoinExchange exchange("cpp_09/data.csv");
    
    std::string line;
    int i = 0;
    while (std::getline(file, line))
    {
        if (i == 0)
        {
            std::string header = line;
            header.erase(line.find_last_not_of(" \n\r\t") + 1);
            if (header == "date | value")
                std::getline(file, line);
            i++;
        }
        if (line.size() < 14 
            || std::count(line.begin(), line.end(), '|') != 1 
            || std::count(line.begin(), line.end(), '.') > 1
            || line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[12] != ' ')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string yearStr = line.substr(0, 4);
        std::string monthStr = line.substr(5, 2);
        std::string dayStr = line.substr(8, 2);
        std::string valueStr = line.substr(13);

        if (!exchange.allDigits(yearStr) || !exchange.allDigits(monthStr) 
            || !exchange.allDigits(dayStr) || !checkValueStr(valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        int year = std::atoi(yearStr.c_str());
        int month = std::atoi(monthStr.c_str());
        int day = std::atoi(dayStr.c_str());
        double value = std::atof(valueStr.c_str());

        // Validate the date
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2009 || year > 2030)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if ((month == 2 && (year % 4 != 0) && day > 28) || (month == 2 && day > 29))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // check if value positive between 1 and 1000
        if (value < 0 || value > 1000)
        {
            if (value < 0)
                std::cerr << "Error: Not a positive value" << std::endl;
            else if (value > 1000)
                std::cerr << "Error: Too large a number" << std::endl;
            continue;
        }

        std::string date = line.substr(0, 10);
        std::tm time = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, 0};
        double unixTime = std::mktime(&time);

        exchange.compareVal(date, unixTime, value);
    }

    return 0;
}