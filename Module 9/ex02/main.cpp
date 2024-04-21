#include "Pmerge.hpp"

int main(int ac, char **av) 
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./pmerge [numbers]" << std::endl;
        return 1;
    }
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


// MINI C PROGRAM TO CHECK IF THE ARGS ARE SORTED

/*

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i = 1;
    while (i < ac - 1)
    {
        if (atoi(av[i]) > atoi(av[i + 1]))
        {
            printf("KO\n");
            return 0;
        }
        i++;
    }
    printf("OK\n");
    return 0;
}

*/