#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "USAGE: ./RPN \" ... \"" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    std::cout << rpn.getRes() << std::endl;
    return 0;
}