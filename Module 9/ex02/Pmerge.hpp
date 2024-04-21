#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <ctime>

class Pmerge
{
    private:
        //starting time in microseconds
        std::deque<int>     dq;
        std::vector<int>    GRU;
        std::clock_t        total_dq;
        std::clock_t        total_gru;
        
    public:
        Pmerge(int ac, char **av);
        ~Pmerge();
        Pmerge(const Pmerge &other);
        Pmerge &operator=(const Pmerge &other);

        void sortdq();
        void sortgru();

        void sort_deque(std::deque<int>::iterator first, std::deque<int>::iterator last);
        void sort_vector(std::vector<int>::iterator first, std::vector<int>::iterator last);

        void print_deque();
        void print_vector();

        void print_time_dq();
        void print_time_gru();
};

#endif