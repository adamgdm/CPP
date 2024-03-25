#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define ORANGE "\033[1;35m"
#define PURPLE "\033[1;36m"
#define PINK "\033[1;37m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define UNDERLINE_BOLD_YELLOW "\033[4;33;1m"

typedef struct s_data
{
    int    id;
    std::string Name;
    std::string Surname;
} Data;

class Serializer
{
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
