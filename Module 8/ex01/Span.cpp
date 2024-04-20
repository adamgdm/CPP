#include "Span.hpp"

Span::Span(unsigned int n) : n(n)
{

}

Span::~Span()
{

}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->n = other.n;
        this->GRU = other.GRU;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (GRU.size() >= this->n)
        throw SpanException();
    GRU.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (GRU.size() + std::distance(begin, end) > n)
        throw SpanException();
    GRU.insert(GRU.end(), begin, end);
}

int Span::shortestSpan()
{
    unsigned int i = 0;
    
    if (GRU.size() <= 1)
        throw TooFewElementsException();
    std::sort(GRU.begin(), GRU.end());
    int min = GRU[1] - GRU[0];
    while (i < GRU.size() - 1)
    {
        if (GRU[i + 1] - GRU[i] < min)
            min = GRU[i + 1] - GRU[i];
        i++;
    }
    return (min);
}

int Span::longestSpan()
{
    if (GRU.size() <= 1)
        throw TooFewElementsException();

    int max = *std::max_element(GRU.begin(), GRU.end());
    int min = *std::min_element(GRU.begin(), GRU.end());

    return (max - min);
}
