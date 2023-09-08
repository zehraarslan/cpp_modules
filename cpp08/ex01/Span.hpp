#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>


class Span
{
private:
    std::vector<int> valArr;
public:
    Span();
    Span(unsigned int size);
    Span(const Span &_span);
    Span &operator=(const Span &_span);
    ~Span();

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void printNumbers();
};




#endif