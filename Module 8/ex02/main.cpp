#include "MutantStack.hpp"

#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> heap;

    heap.push(1);
    heap.push(2);
    heap.push(3);

    MutantStack<int>::iterator it = heap.begin();

    // Print them all, iterating with ++, using *
    while (it != heap.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // Pop an element from the stack
    heap.pop();
    std::cout << "After popping, the top element is: " << heap.top() << std::endl;

    // Push more elements to the stack
    heap.push(4);
    heap.push(5);

    // Print the stack size
    std::cout << "The stack size is: " << heap.size() << std::endl;

    // Print all elements again
    it = heap.begin();
    while (it != heap.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}