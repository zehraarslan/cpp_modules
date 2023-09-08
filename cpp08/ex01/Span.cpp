#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int size)
{
    valArr.reserve(size);
}

Span::Span(const Span &span)
{
    *this = span;
}

Span &Span::operator=(const Span &span)
{

    valArr = span.valArr;
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(int number)
{
    if (valArr.size() < valArr.capacity())
    {
        valArr.push_back(number);

    }
    else
    {
        throw std::runtime_error("Full of span!");
    }
}

int Span::shortestSpan()
{
    if (valArr.size() < 2)
        throw std::runtime_error("Not enough numbers!");

    std::vector<int> vec;
    vec = valArr;
    std::sort(vec.begin(), vec.end());

    int min = vec[vec.size() - 1];
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (min > (vec[i + 1] - vec[i]))
            min = vec[i + 1] - vec[i];
    }
    return min;
}


int Span::longestSpan()
{
    if (valArr.size() < 2)
        throw std::runtime_error("Not enough numbers!");

    std::vector<int> vec;
    vec = valArr;
    std::sort(vec.begin(), vec.end());
    return (vec[vec.size() - 1] - vec[0]);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        if (valArr.size() >= valArr.capacity())
        {
            throw std::runtime_error("Full of span!");
        }
        valArr.push_back(*begin);
        ++begin;
    }
}

void Span::printNumbers()
{
    std::vector<int>::iterator iter = valArr.begin();
    while (iter != valArr.end())
    {
        std::cout << *iter++ << " ";
    }
    std::cout << std::endl;
}