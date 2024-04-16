#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try
    {
        std::cout << easyfind(vec, 1) << std::endl;
        std::cout << easyfind(vec, 69) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}