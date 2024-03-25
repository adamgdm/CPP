#include "helpers.hpp"

size_t ft_strlen(std::string str)
{
    size_t i;

    i = 0;
    while (str[i])
        ++i;
    return i;
}

char* stringToCharPtr(const std::string& str)
{
    size_t len;
    char* ret;
    size_t i;

    len = ft_strlen(str);
    ret = new char[len + 1];
    i = 0;
    while (i < len)
    {
        ret[i] = str[i];
        ++i;
    }
    ret[len] = '\0';
    return ret;
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
