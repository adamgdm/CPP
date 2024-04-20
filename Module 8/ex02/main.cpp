#include "MutantStack.hpp"

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





// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }

// int main()
// {
//     std::list<int> mstack;
//     mstack.push_back(5);
//     mstack.push_back(17);
//     std::cout << mstack.back() << std::endl;
//     mstack.pop_back();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(std::deque<int>(mstack.begin(), mstack.end()));
//     return 0;
// }