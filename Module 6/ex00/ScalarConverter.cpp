#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
	return (*this);
}

int ft_strcmp(const char *str1, const char *str2)
{
    int i;
	
	i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i])
        i++;
    return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

bool isValidNumber(const char* str)
{
    if (ft_strcmp(str, "inf") == 0 || ft_strcmp(str, "inff") == 0 || ft_strcmp(str, "nan") == 0) {
        return true;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i+1] == '\0' && (str[i] == 'f' || str[i] == 'F')) {
            ++i;
            continue;
        }

        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') {
            return false;
        }

        ++i;
    }

    return true;
}

bool isValidNumberF(const char* str)
{
	int i = 0;
    char *end;
    double num = std::strtod(str, &end);

    if (num == INFINITY || num == -INFINITY || num != num) {
        return false;
    }
    while (str[i] != '\0') {
        if (str[i+1] == '\0' && (str[i] == 'f' || str[i] == 'F')) {
            ++i;
            continue;
        }

        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.') {
            return false;
        }

        ++i;
    }

    return true;
}

char ScalarConverter::convertToChar(const std::string &str)
{
    char* end;
    double num = std::strtol(str.c_str(), &end, 10);

    if (end == str.c_str() || !(isValidNumberF(end)))
        throw std::invalid_argument("Invalid float: " + str);
	return static_cast<char>(num);
}

int ScalarConverter::convertToInt(const std::string &str)
{
    char* end;
    double num = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || (*end != '\0' && *end != 'f' && *end != 'F') || (*(end + 1) != '\0'))
        throw std::invalid_argument("Invalid int: " + str);
    if (num < INT_MIN || num > INT_MAX || num != num)
        throw std::invalid_argument("Invalid int: " + str);
    return static_cast<int>(num);
}
float ScalarConverter::convertToFloat(const std::string &str)
{
    char* end;
    double num = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || !isValidNumber(end))
        throw std::invalid_argument("Invalid float: " + str);
    return static_cast<float>(num);
}

double ScalarConverter::convertToDouble(const std::string &str)
{
	char* end;
    double num = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || !isValidNumber(end))
        throw std::invalid_argument("Invalid double: " + str);
	return (num);
}
void printingMachine(char* c, int* i, float* f, double* d)
{
    if (c && *c > 31 && *c != 127)
        std::cout << "char: '" << *c << "\'" << std::endl;
    else if (c)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    if (i)
        std::cout << "int: " << *i << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    if (f)
        std::cout << std::fixed << std::setprecision(1) << "float: " << *f << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    if (d)
        std::cout << std::fixed << std::setprecision(1) << "double: " << *d << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    char    c;
    int     i;
    float   f;
    double  d;
    char*   cp = NULL;
    int*    ip = NULL;
    float*  fp = NULL;
    double* dp = NULL;

    if (str.length() == 1 && !isdigit(str[0]))
    {
        c = str[0];
        cp = &c;
        try
        {
            i = static_cast<int>(c);
            ip = &i;
        }
        catch(...)
        {
            ip = NULL;
        }
        try
        {
            f = static_cast<float>(c);
            fp = &f;
        }
        catch(...)
        {
            fp = NULL;
        }
        try
        {
            d = static_cast<double>(c);
            dp = &d;
        }
        catch(...)
        {
            dp = NULL;
        }
    }
    else
    {
        try 
        {
            c = ScalarConverter::convertToChar(str);
            cp = &c;
        } 
        catch(...) 
        {
            cp = NULL;
        }

        try 
        {
            i = ScalarConverter::convertToInt(str);
            ip = &i;
        } 
        catch(...) 
        {
            ip = NULL;
        }

        try 
        {
            f = ScalarConverter::convertToFloat(str);
            fp = &f;
        } 
        catch(...) 
        {
            fp = NULL;
        }

        try 
        {
            d = ScalarConverter::convertToDouble(str);
            dp = &d;
        }
        catch(...) 
        {
            dp = NULL;
        }
    }
    printingMachine(cp, ip, fp, dp);
}