#include <iostream>
#include "Array.hpp"

int main()
{
    // create array of 5 integers

    Array<int> numbers(5);

    unsigned int i;
    i = 0;
    while (i < numbers.size())
    {
        numbers[i] = i + 1;
        i++;
    }
    i = 0;
    while (i < numbers.size())
    {
        std::cout << numbers[i] << std::endl;
        i++;
    }

    // create empty array
    std::cout << std::endl;

    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // try to access empty array
    std::cout << std::endl;

    try
    {
        empty[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": Accessing empty array" << std::endl;
    }

    // create array of 3 char pointers
    std::cout << std::endl;

    Array<char *> strings(3);
    
    char str[] = "Hello";
    strings[0] = str;

    char str2[] = "World";
    strings[1] = str2;

    char str3[] = "!";
    strings[2] = str3;

    
    i = 0;

    while (i < strings.size())
    {
        std::cout << strings[i] << std::endl;
        i++;
    }

    // modify first string 
    std::cout << std::endl;

    strings[0][0] = 'Y';

    std::cout << strings[0] << std::endl;

    return (0);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }