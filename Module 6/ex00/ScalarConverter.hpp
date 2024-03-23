#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdexcept>
#include <cfloat>
#include <cmath>

#define RED "\033[31m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

typedef struct t_data
{
	char *c;
	int i;
	float f;
	double d;

} s_data;

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		// converters
		static char convertToChar(const std::string &str);
		static int convertToInt(const std::string &str);
		static float convertToFloat(const std::string &str);
		static double convertToDouble(const std::string &str);

		static void convert(const std::string &str);
};

#endif