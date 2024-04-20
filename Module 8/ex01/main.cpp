#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span emptySpan = Span(5);

    try {
        std::cout << emptySpan.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << emptySpan.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    unsigned int num = 100000;
    Span largeSpan = Span(num);
    std::vector<int> largeNumbers(num);

    for (unsigned int i = 0; i < num; ++i) {
        largeNumbers[i] = i;
    }
    largeSpan.addNumber(largeNumbers.begin(), largeNumbers.end());

    try {
        std::cout << largeSpan.shortestSpan() << std::endl;
        std::cout << largeSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        largeSpan.addNumber(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}