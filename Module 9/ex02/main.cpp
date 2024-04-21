#include "Pmerge.hpp"

int main(int ac, char **av) 
{
    Pmerge numbers(ac, av);
    std::cout << "Before: ";
    numbers.print_deque();
    numbers.sortdq();
    numbers.sortgru();
    std::cout << "After in dq: ";
    numbers.print_deque();

    numbers.print_time_dq();
    numbers.print_time_gru();
}