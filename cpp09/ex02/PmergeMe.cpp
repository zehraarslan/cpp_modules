#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &pmerge)
{
    *this = pmerge;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmerge)
{
    this->inputVector = pmerge.inputVector;
    this->inputDeque = pmerge.inputDeque;

    return *this;
}

PmergeMe::~PmergeMe() { }

int PmergeMe::insertVector(std::vector<int> &con, int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int value = con[i];
        int j = i - 1;
        while (j >= begin && con[j] > value)
        {
            con[j + 1] = con[j];
            j--;
        }
        con[j+1] = value;
    }

    return 0;
}

int PmergeMe::mergeVector(std::vector<int> &con, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    std::vector<int> leftContainer(leftSize);
    std::vector<int> rightContainer(rightSize);

    for (int i = 0; i < leftSize; i++)
        leftContainer[i] = con[begin + i];

    for (int i = 0; i < rightSize; i++)
        rightContainer[i] = con[mid + 1 + i];
    
    int l = 0;
    int r = 0;
    int i = begin;
    
    while (l < leftSize && r < rightSize)
    {
        if (leftContainer[l] <= rightContainer[r])
        {
            con[i] = leftContainer[l];
            l++;
            i++;
        }
        else
        {
            con[i] = rightContainer[r];
            r++;
            i++;
        }
    }

    while (l < leftSize)
    {
        con[i] = leftContainer[l];
        l++;
        i++;
    }

    while (r < rightSize)
    {
        con[i] = rightContainer[r];
        r++;
        i++;
    }
    return 0;
}

int PmergeMe::mergeInsertVector(std::vector<int> &container, int begin, int end, int threshold)
{
    if (begin < end)
    {
        if (end - begin + 1 <= threshold)
            insertVector(container, begin, end);
        else
        {
            int mid = begin + ((end - begin) / 2);
            mergeInsertVector(container, begin, mid, threshold);
            mergeInsertVector(container, mid + 1, end, threshold);

            mergeVector(container, begin, mid, end);
        }
    }

    return 0;
}

int PmergeMe::insertDeque(std::deque<int> &con, int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int value = con[i];
        int j = i - 1;

        while (j >= begin && con[j] > value)
        {
            con[j + 1] = con[j];
            j--;
        }
        con[j + 1] = value;
    }

    return 0;
}

int PmergeMe::mergeDeque(std::deque<int> &con, int begin, int mid, int end)
{
    int leftSize = mid - begin + 1;
    int rightSize = end - mid;

    std::deque<int> leftContianer;
    std::deque<int> rightContianer;

    for (int i = 0; i < leftSize; i++)
        leftContianer[i] = con[i + begin];
    
    for (int i = 0; i < rightSize; i++)
    {
        rightContianer[i] = con[mid + 1 + i];
    }

    int l = 0;
    int r = 0;
    int i = begin;

    while (l < leftSize && r < rightSize)
    {
        if (leftContianer[l] <= rightContianer[r])
        {
            con[i] = leftContianer[l];
            l++;
            i++;
        }
        else
        {
            con[i] = rightContianer[r];
            r++;
            i++;
        }
    }
    
    while (l < leftSize)
    {
        con[i] = leftContianer[l];
        l++;
        i++;
    }

    while (r < rightSize)
    {
        con[i] = rightContianer[r];
        r++;
        i++;
    }
    
    return 0;
}

int PmergeMe::mergeInsertDeque(std::deque<int> &container, int begin, int end, int threshold)
{
    if (begin < end)
    {
        if (begin - end + 1 <= threshold)
            insertDeque(container, begin, end);
        else
        {
            int mid = begin + ((end - begin) / 2);
            mergeInsertDeque(container, begin, mid, threshold);
            mergeInsertDeque(container, mid + 1, end, threshold);

            mergeDeque(container, begin, mid, end);
        }
    }
    return 0;
}

template <typename T>
void PmergeMe::printContainer(T container)
{
    for (int i = 0; i < container.size(); i++)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

int PmergeMe::argumantControl(std::string argv)
{
    std::string control = "0123456789";

    for (int i = 0; i < argv.size(); i++)
    {
        for (int j = 0; j < control.length(); j++)
            {
                if (argv[i] == control[j])
                    break;
                if (j == control.length() - 1)
                {
                    return 1;
                }
            }   
    }
    return 0;
}
int PmergeMe::fordJohnson(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if(argumantControl(argv[i]) || !(atoi(argv[i]) >= 0 && atof(argv[i]) <= INT_MAX))
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        inputVector.push_back(atoi(argv[i]));
        inputDeque.push_back(atoi(argv[i]));
    }

    std::cout << "Before: " ;
    printContainer(inputVector);

    clock_t start_vector = clock();
    mergeInsertVector(inputVector, 0, inputVector.size() - 1, 3);
    clock_t end_vector = clock();

    clock_t start_deque = clock();
    mergeInsertDeque(inputDeque, 0, inputDeque.size() - 1, 3);
    clock_t end_deque = clock();

    std::cout << "After: " ;
    printContainer(inputDeque);


    double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC * 1000;
    double time_deque = static_cast<double>(end_deque - start_deque)  / CLOCKS_PER_SEC * 1000;


    std::cout << "Time to process a range of " << inputVector.size() << " elements with std::vector : " << time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size() <<  " elements with std::deque  : " << time_deque <<  " us" << std::endl;

    return 0;
}

