#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rpn)
{
    *this = rpn;
}

RPN &RPN::operator=(const RPN &rpn)
{
    this->inputStack = rpn.inputStack;
    return *this;
}

RPN::~RPN() {}

int RPN::argumentControl(const std::string argv)
{
    int _return = 0;
    std::string control = "0123456789+-*/";
    for (int i = 0; i < argv.length(); i++)
    {
        if(!isspace(argv[i]))
        {
            for (int j = 0; j < control.length(); j++)
            {
                if (argv[i] == control[j])
                    break;
                if (j == control.length() - 1)
                {
                    std::cout << "Error" << std::endl;
                    return 1;
                }
            }  
        }
    }
    return 0;
}

int RPN::calculate(const std::string argv)
{
    if (argumentControl(argv))
        return 1;

    for (int i = 0; i < argv.length(); i++)
    {
       
        if (!isspace(argv[i]) && isdigit(argv[i]))
        {
            inputStack.push(argv[i] - 48);
        }
        else if(!isspace(argv[i]))
        {
            if (inputStack.size() < 2)
            {
                std::cout << "Error"  << std::endl;
                return 1; 
            }
            double value2 = inputStack.top();
            inputStack.pop();
            double value1 = inputStack.top();
            inputStack.pop();

            switch (argv[i])
            {
            case '+':
                inputStack.push(value1 + value2);
                break;
            case '-':
                inputStack.push(value1 - value2);
                break;
            case '*':
                inputStack.push(value1 * value2);
                break;
            case '/':
                if (value2 == 0)
                {
                    std::cout << "Error"  << std::endl;
                    return 1;
                }
                inputStack.push(value1 / value2);
                break;
            }
        }
    }
    std::stack<double> copyStack;

    while (!inputStack.empty())
    {
        copyStack.push(inputStack.top());
        inputStack.pop();
    }

    while (!copyStack.empty())
    {
        std::cout << copyStack.top() << " ";
        copyStack.pop();
    }
    
    std::cout << std::endl;
    return 0;
}