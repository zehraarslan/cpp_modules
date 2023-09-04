#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> inputVector;
    std::deque<int> inputDeque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &pmerge);
    PmergeMe &operator=(const PmergeMe &pmerge);
    ~PmergeMe();

    template <typename T>
    void printContainer(T container);

    int fordJohnson(int argc, char **argv);
    int argumantControl(std::string argv);


    int mergeInsertVector(std::vector<int> &container, int begin, int end, int threshold);
    int insertVector(std::vector<int> &con, int begin, int end);
    int mergeVector(std::vector<int> &con, int begin, int mid, int end);

    int mergeInsertDeque(std::deque<int> &container, int begin, int end, int threshold);
    int insertDeque(std::deque<int> &con, int begin, int end);
    int mergeDeque(std::deque<int> &con, int begin, int mid, int end);

};


#endif