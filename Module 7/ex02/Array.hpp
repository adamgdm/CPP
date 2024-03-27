#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array 
{
    private:
        T *arr;
        unsigned int size_arr;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();

        Array &operator=(Array const &other);
        T &operator[](unsigned int i);

        unsigned int size() const;
};

#include "Array.tpp"

#endif