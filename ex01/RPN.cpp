#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>

RPN::RPN(){};
RPN::~RPN(){};
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
		if (token.length() > 1){
			std::cerr << "Error: More than 1 digit" << std::endl;
            return ;
        }
		if (isalpha(token[0])){
			std::cerr << "Error: Wrong character" << std::endl;
            return ;
        }
        if (isdigit(token[0]))
            numbers.push(stoi(token));
        else if (token == "+" || token == "-" || token == "*" || token == "/"){
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
        std::cout << "\033[1;32mResult: " << numbers.top() << "\033[0m" << std::endl;
    else {
        std::cerr << "Error: Invalid input" << std::endl;
        return ;
    }
}