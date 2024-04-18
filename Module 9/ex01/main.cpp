#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    std::cout << rpn.getRes() << std::endl;
    return 0;
}