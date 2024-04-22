#include "Pmerge.hpp"

Pmerge::Pmerge(int ac, char **av) 
{
    for (int i = 1; i < ac; i++) 
    {
        if (std::isdigit(*av[i]) == 0 && *av[i] != '+' && *av[i] != '-') 
        {
            std::cerr << "Error: Invalid character" << std::endl;
            exit(1);
        }
        dq.push_back(std::atoi(av[i]));
        GRU.push_back(std::atoi(av[i]));
    }
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

void Pmerge::sort_deque(std::deque<int>::iterator first, std::deque<int>::iterator last)
{
    int distance = std::distance(first, last);
    std::deque<int>::iterator middle;
    if (distance == 2) 
    {
        if (*first > *std::next(first)) 
            std::sort(first, last);
    } 
    else if (distance > 2) 
    {
        middle = std::next(first, distance / 2);
        sort_deque(first, middle);
        sort_deque(middle, last);
        std::inplace_merge(first, middle, last);
    }
    else 
        return ;
}

void Pmerge::sort_vector(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    int distance = std::distance(first, last);
    std::vector<int>::iterator middle;
    if (distance == 2) 
    {
        if (*first > *std::next(first)) 
            std::sort(first, last);
    } 
    else if (distance > 2) 
    {
        middle = std::next(first, distance / 2);
        sort_vector(first, middle);
        sort_vector(middle, last);
        std::inplace_merge(first, middle, last);
    }
    else 
        return ;
}

void Pmerge::sortdq() 
{
    std::time_t start = std::clock();
    sort_deque(this->dq.begin(), this->dq.end());
    std::time_t end = std::clock();
    this->total_dq = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void Pmerge::sortgru() 
{
    std::time_t start = std::clock();
    sort_vector(this->GRU.begin(), this->GRU.end());
    std::time_t end = std::clock();
    this->total_gru = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
}

void Pmerge::print_deque() 
{
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++) 
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Pmerge::print_vector() 
{
    for (std::vector<int>::iterator it = GRU.begin(); it != GRU.end(); it++) 
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Pmerge::print_time_dq()
{
    std::cout << "Time to process a range of " << this->dq.size() 
              << " elements with std::deque is: " << std::fixed << std::setprecision(5) 
              << this->total_dq << " us" << std::endl;
}

void Pmerge::print_time_gru()
{
    std::cout << "Time to process a range of " << this->GRU.size() 
              << " elements with std::vector is: " << std::fixed << std::setprecision(5) 
              << this->total_gru << " us" << std::endl;
}
