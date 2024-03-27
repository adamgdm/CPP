#include "iter.hpp"

template <typename T> void iter(T *array, size_t len, void (*func)(T &))
{
    size_t i = 0;
    while (array[i] && i < len)
    {
        func(array[i]);
        i++;
    }
}

template <typename T> void print(T &i)
{
    std::cout << i << std::endl;
}

template <typename T> void capitalize(T &i)
{
    if (i >= 'a' && i <= 'z')
        i -= 32;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    
    char array2[] = {'a', 'b', 'c', 'd', 'e'};
    iter(array2, 5, print);
    
    float array3[] = {1.1, 2.3, 3.5, 4.7, 5.9};
    iter(array3, 5, print);

    char array4[] = {'x', 'y', 'z'};
    iter(array4, 3, capitalize);
    iter(array4, 3, print);

    return 0;
}