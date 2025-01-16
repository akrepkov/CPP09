#include "RPN.hpp"

// void printStack(std::stack<int> stack) {
//     std::cout << "Result: ";
//     if (stack.empty()) {
//         std::cout << "Empty stack" << std::endl;
//         return;
//     }
//     while (!stack.empty()) {
//         std::cout << stack.top() << " ";
//         stack.pop();
//     }
//     std::cout << std::endl;
// }

int main(int argc, char* argv[]){
    if (argc == 2){
        RPN notation;
        notation.extractInput(argv[1]);
    }
    else
        std::cerr << "Error" << std::endl;
    return 0;
}
/*
Stack 

The essence of evaluating an RPN expression revolves around pushing numbers onto the stack and popping two numbers off the stack when encountering an operator.

*/