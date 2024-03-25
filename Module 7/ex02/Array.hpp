#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

class Array 
{
    private:
        int *arr;
        unsigned int size_arr;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();

        Array &operator=(Array const &other);
        int &operator[](unsigned int i);

        unsigned int size() const;
};

Array::Array() 
{
    this->arr = NULL;
    this->size_arr = 0;
}

Array::Array(unsigned int n)
{
    this->arr = new int[n];
    this->size_arr = n;
}

Array::Array(Array const &other)
{
    int i;

    i = 0;
    this->arr = new int[other.size()];
    this->size_arr = other.size_arr;
    while (i < other.size_arr)
    {
        this->arr[i] = other.arr[i];
        i++;
    }
}

Array::~Array()
{
    delete[] (this->arr);
}

Array &Array::operator=(Array const &other)
{
    int i;

    i = 0;
    if (this != &other)
    { 
        delete [] this->arr;
        this->arr = new int[other.size()];
        this->size_arr = other.size_arr;
        while (i < other.size_arr)
        {
            this->arr[i] = other.arr[i];
            i++;
        }
    }
    return (*this);
}

int &Array::operator[](unsigned int i)
{
    if (i < 0 || i >= this->size_arr)
        throw std::exception();
    return (this->arr[i]);
}

unsigned int Array::size() const
{
    return (this->size_arr);
}

#endif