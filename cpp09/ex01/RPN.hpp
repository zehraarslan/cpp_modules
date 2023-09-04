#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
    std::stack<double> inputStack;
    
    int argumentControl(const std::string argv);

public:
    RPN();
    RPN(const RPN &rpn);
    RPN &operator=(const RPN &rpn);
    ~RPN();

    int calculate(const std::string argv);
};



#endif