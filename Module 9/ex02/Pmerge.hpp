#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>

class Pmerge
{
    private:
        std::deque<int>     dq;
        std::vector<int>    GRU;
        

    public:
        Pmerge();
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        void merge(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);
        void merge(std::deque<int>::iterator &begin, std::deque<int>::iterator &end);
        void copy(std::vector<int>::iterator &begin, std::vector<int>::iterator &end);
        void copy(std::deque<int>::iterator &begin, std::deque<int>::iterator &end);
        void sort();
        void print();
};

Pmerge::Pmerge() 
{

}

Pmerge::~Pmerge() 
{

}

Pmerge::Pmerge(const Pmerge &other) 
{
    dq = other.dq;
    GRU = other.GRU;
}

Pmerge &Pmerge::operator=(const Pmerge &other) 
{
    if (this != &other) 
    {
        dq = other.dq;
        GRU = other.GRU;
    }
    return *this;
}



#endif