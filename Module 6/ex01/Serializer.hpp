#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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
