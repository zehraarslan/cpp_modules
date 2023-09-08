#include "iter.hpp"

template<typename T, typename F>
void iter(T *array, size_t length, F func)
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }

}

template<typename T>
void ShowValue(T index)
{
    std::cout << index << std::endl;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 4, ShowValue<int>);

    std::string arr2[] = {"Zehra", "Merve", "Şeyma", "Hülya"};
    iter(arr2, 4, ShowValue<std::string>);
    return 0;
}