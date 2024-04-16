#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int n;
        std::vector<int> GRU;

    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);

        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class SpanException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Attempt to exceed the limit of the vector.";
                }
        };
        class TooFewElementsException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return "Too few elements to calculate the span.";
                }
        };
};

#endif