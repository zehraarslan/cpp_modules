#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T t, int number)
{
   typename T::iterator iter = std::find(t.begin(), t.end(), number);
   if (iter == t.end())
    throw std::runtime_error("Out of range!");
   return iter;
}

#endif