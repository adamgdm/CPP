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

    std::list<int> lst;

    for (int i = 0; i < 10; i++)
        lst.push_back(i);

    try
    {
        std::cout << easyfind(lst, 1) << std::endl;
        std::cout << easyfind(lst, 68) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::deque<int> dq;

    for (int i = 0; i < 10; i++)
        dq.push_back(i);
    
    try
    {
        std::cout << easyfind(dq, 1) << std::endl;
        std::cout << easyfind(dq, 68) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}