#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

class RPN {
    private: 
        std::stack<double> heap;
    public:
        RPN(std::string str);
        ~RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);

        double getRes();
};

#endif


