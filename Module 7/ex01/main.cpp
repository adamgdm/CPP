#include "iter.hpp"

template <typename T> void iter(T *array, size_t len, void (*func)(T &))
{
    size_t i = 0;
    while (i < len)
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

template <typename T> void square(T &i)
{
    i *= i;
}

int main()
{
    // Test with int array
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    std::cout << "--------------------------" << std::endl;

    // Test with char array
    char array2[] = {'a', 'b', 'c', 'd', 'e'};
    iter(array2, 5, print);
    std::cout << "--------------------------" << std::endl;

    // Test with float array
    float array3[] = {1.1, 2.3, 3.5, 4.7, 5.9};
    iter(array3, 5, print);
    std::cout << "--------------------------" << std::endl;

    // Test with char array and capitalize function
    char array4[] = {'x', 'y', 'z'};
    iter(array4, 3, capitalize);
    iter(array4, 3, print);
    std::cout << "--------------------------" << std::endl;

    // Test with empty array
    int emptyArray[] = {};
    iter(emptyArray, 0, print);
    std::cout << "If this is the only line between the dashes,"
        << "the function did not iterate over the empty array" << std::endl;
    std::cout << "--------------------------" << std::endl;

    // Test with different function
    int array5[] = {1, 2, 3, 4, 5};
    iter(array5, 5, square);
    iter(array5, 5, print); 
    std::cout << "--------------------------" << std::endl;

    // Test with string array
    std::string strArray[] = {"Hello", "World"};
    iter(strArray, 2, print);
    std::cout << "--------------------------" << std::endl;

    return 0;
}