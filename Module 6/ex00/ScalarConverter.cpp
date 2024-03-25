#include "ScalarConverter.hpp"
#include "helpers.hpp"

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

char *ScalarConverter::convertToChar(const std::string &str)
{
    char* end;
    char *result;
    char* string = stringToCharPtr(str);
    double num = std::strtol(string, &end, 10);

    try
    {   
        if (end == string || !(isValidNumberF(end)))
            throw std::invalid_argument("Invalid float: " + str);
    }
    catch (...)
    {
        delete[] (string);
        return (NULL);
    }

    result = new char;
    *result = static_cast<char>(num);
    delete[] (string);
    return (result);
}

int *ScalarConverter::convertToInt(const std::string &str)
{
    char* end;
    int *result;
    char* string = stringToCharPtr(str);
    double num = std::strtod(string, &end);

    try 
    {
        if (end == string || (*end != '\0' && *end != 'f' && *end != 'F') || (*(end + 1) != '\0'))
            throw std::invalid_argument("Invalid int: " + str);
        if (num < INT_MIN || num > INT_MAX || num != num)
            throw std::invalid_argument("Invalid int: " + str);
    }
    catch (...)
    {
        delete[] (string);
        return (NULL);
    }

    result = new int;
    *result = static_cast<int>(num);
    delete[] (string);
    return (result);
}

float *ScalarConverter::convertToFloat(const std::string &str)
{
    char* end;
    float *result;
    char* string = stringToCharPtr(str);
    double num = std::strtod(string, &end);

    try
    {
        if (end == string || !isValidNumber(end))
            throw std::invalid_argument("Invalid float: " + str);
    }
    catch(...)
    {
        delete[] (string);
        return (NULL);
    }

    result = new float;
    *result = static_cast<float>(num);
    delete[] (string);
    return (result);
}

double *ScalarConverter::convertToDouble(const std::string &str)
{
    char* end;
    double *result;
    char* string = stringToCharPtr(str);
    double num = std::strtod(string, &end);

    try 
    {
        if (end == string || !isValidNumber(end))
            throw std::invalid_argument("Invalid double: " + str);
    }
    catch (...)
    {
        delete[] (string);
        return (NULL);
    }

    result = new double;
    *result = static_cast<double>(num);
    delete[] (string);
    return (result);
}

void printingMachine(char* c, int* i, float* f, double* d);

void ScalarConverter::convert(const std::string &str)
{
    char*   cp = NULL;
    int*    ip = NULL;
    float*  fp = NULL;
    double* dp = NULL;

    if (ft_strlen(str) == 1 && !isdigit(str[0]))
    {
        char c = str[0];
        cp = new char(static_cast<int>(c));
        ip = new int(static_cast<int>(c));
        fp = new float(static_cast<float>(c));
        dp = new double(static_cast<double>(c));
    }
    else
    {
        cp = ScalarConverter::convertToChar(str);
        ip = ScalarConverter::convertToInt(str);
        fp = ScalarConverter::convertToFloat(str);
        dp = ScalarConverter::convertToDouble(str);
    }
    printingMachine(cp, ip, fp, dp);

    delete cp;
    delete ip;
    delete fp;
    delete dp;
}