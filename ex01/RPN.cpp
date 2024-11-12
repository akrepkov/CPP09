#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>

RPN& RPN::operator=(const RPN& copy){
    if (this == &copy) {
        return *this;
    }
    numbers = copy.numbers;
    return *this;    
}
RPN::RPN(const RPN& copy){
    numbers = copy.numbers;
}

void RPN::extractInput(std::string data){
    std::stringstream ss(data);
    std::string token;
    while(ss >> token){
        //std::cout << "Token : " << token << " size " <<numbers.size() << std::endl;
        if (isdigit(token[0]))
            numbers.push(stoi(token));
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
            if (token == "neg")
                token = "-";
            if (numbers.size() < 2) {
                std::cerr << "Error: Not enough arguments before operator" << std::endl;
                return ;
            }
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            if (token == "+") {
                numbers.push(a + b);
            } else if (token == "-") {
                numbers.push(a - b);
            } else if (token == "*") {
                numbers.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return ;
                }
                numbers.push(a / b);
            }
        }
    }
    //printStack(numbers);
    if (numbers.size() == 1)
        std::cout << "Result: " << numbers.top() << std::endl;
    else {
        std::cerr << "Error: Invalid input" << std::endl;
        return ;
    }
}