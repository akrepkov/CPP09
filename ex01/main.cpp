#include "RPN.cpp"

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
        std::cout << "0" << std::endl;
    return 0;
}

/*
add exceptions, cases for operators, Makefile
*/