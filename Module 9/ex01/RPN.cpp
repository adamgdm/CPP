#include "RPN.hpp"

void printAndExit(std::string str, double exitCode)
{
    std::cerr << str << std::endl;
    exit(exitCode);
}

RPN::RPN(std::string str) 
{
    double                  op1;
    double                  op2;
    std::string::iterator   it;

    it = str.begin();
    while (it != str.end()) 
    {
        if (std::isdigit(*it)) 
        {
            heap.push(*it - '0');
            ++it;
        } 
        else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') 
        {
            if (heap.size() < 2) 
                printAndExit("Error: Attempting to perform calculation with less than 2 elements.", 1);
            op2 = heap.top(); 
            heap.pop();
            op1 = heap.top(); 
            heap.pop();

            switch (*it) 
            {
                case '+':
                    heap.push(op1 + op2); 
                    break;
                case '-': 
                    heap.push(op1 - op2); 
                    break;
                case '*': 
                    heap.push(op1 * op2); 
                    break;
                case '/':
                    if (op2 == 0)
                        printAndExit("Error: Division by zero", 1);
                    heap.push(op1 / op2);
                    break;
            }
            ++it;
        } 
        else if (std::isspace(*it)) 
        {
            while (it != str.end() && std::isspace(*it)) ++it;
        } 
        else 
            printAndExit("Error: Invalid character", 1);
    }
}

RPN::~RPN()
{

}

RPN::RPN(const RPN& other)
{
    if (this != &other)
    {
        heap = other.heap;
    }
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        heap = other.heap;
    }
    return (*this);
}

double RPN::getRes()
{
    if (heap.empty())
        printAndExit("Stack is empty", 0);
    if (heap.size() > 1)
        printAndExit("Error: Invalid expression", 1);
    return (heap.top());
}