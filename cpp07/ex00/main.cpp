#include "whatever.hpp"


template<typename T>
void swap(T &index1, T &index2)
{
    T new_index = index1;
    index1 = index2;
    index2 = new_index;
}

template<typename T>
T min(T index1, T index2)
{
    return index1 < index2 ? index1 : index2;
}

template<typename T>
T max(T index1, T index2)
{
    return index1 > index2 ? index1 : index2;
}



int main(void)
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    return 0;
}