#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <iostream>
#include <climits>
#include <cmath>

size_t  ft_strlen(std::string str);
char*   stringToCharPtr(const std::string& str);
int     ft_strcmp(const char *str1, const char *str2);
bool    isValidNumber(const char* str);
bool    isValidNumberF(const char* str);

#endif