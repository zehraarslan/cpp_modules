#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ctime>

template<class T>
class Array
{
private:
    T *array;
    size_t _size;
public:
    Array()
    {
        _size = 0;
        array = nullptr;
    }

    Array(int n)
    {
        _size = n;
        array = new T[n];
    }

    Array(const Array &arr)
    {
        *this = arr;
    }

    Array &operator=(const Array &arr)
    {
        _size = arr._size;
        for (size_t j = 0; j < arr._size; j++)
        {
            array[j] = arr[j];
        }
        return *this;
    }

    ~Array()
    {
        delete[] array;
    }

    T &operator[](int i)
    {
        if (i < 0 || i >= this->_size)
            throw std::out_of_range("invalid value");
        else
            return array[i];

    }

    size_t size(void)
    {
        return _size;
    }
};


#endif