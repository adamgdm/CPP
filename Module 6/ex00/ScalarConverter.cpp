#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(*this) = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		(*this) = other;
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

    if (end == str.c_str() || !isValidNumberF(end)) {
        throw std::invalid_argument("Invalid float: " + str);
    }
	return static_cast<char>(num);
}

int ScalarConverter::convertToInt(const std::string &str)
{
	char* end;
    double num = std::strtod(str.c_str(), &end);

	std::
	

    if (end == str.c_str() || !isValidNumberF(end)) {
        throw std::invalid_argument("Invalid int: " + str);
    }
	return (num);
}

float ScalarConverter::convertToFloat(const std::string &str)
{
    char* end;
    double num = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || !isValidNumber(end)) {
        throw std::invalid_argument("Invalid float: " + str);
    }

    return static_cast<float>(num);
}

double ScalarConverter::convertToDouble(const std::string &str)
{
	char* end;
    double num = std::strtod(str.c_str(), &end);

    if (end == str.c_str() || !isValidNumber(end)) {
        throw std::invalid_argument("Invalid double: " + str);
    }
	return (num);
}

void ScalarConverter::convert(const std::string &str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	// CHARACTER CONVERSION
    try 
	{
        c = convertToChar(str);
        if (c > 31 && c != 127)
            std::cout << "char: '" << c << "\'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } 
	catch(...) 
	{
        std::cout << "char: impossible" << std::endl;
    }

	// INT CONVERSION
    try 
	{
        i = convertToInt(str);
        std::cout << "int: " << i << std::endl;
    } 
	catch(...) 
	{
        std::cout << "int: impossible" << std::endl;
    }

	// FLOAT CONVERSION
    try 
	{
        f = convertToFloat(str);
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    } 
	catch(...) 
	{
        std::cout << "float: impossible" << std::endl;
    }

	// DOUBLE CONVERSION
    try 
	{
        d = convertToDouble(str);
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    }
	catch(...) 
	{
	    std::cout << "double: impossible" << std::endl;
	}
}