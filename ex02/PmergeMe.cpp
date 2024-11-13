#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>


PmergeMe::PmergeMe(const PmergeMe& copy){
//rewrite
}
PmergeMe& PmergeMe::operator=(const PmergeMe& copy){
    return *this; //rewrite
}

void PmergeMe::printVector(){
    std::cout << "Vector" << std::endl;
    for(auto i= Vector.begin(); i != Vector.end(); ++i){
        std::cout << " " << *i << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(){
    std::cout << "Deque" << std::endl;
    for(auto i= Deque.begin(); i != Deque.end(); ++i){
        std::cout << " " << *i << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::sortVector()
{

    printVector();
    if (Vector.size()%2 == 0){
        for(int i = 0; Vector.at(i); i += 2){
            std::cout << "I " << i << " | ";
            if (Vector[i] < Vector[i+1]){
                std::swap(Vector[i],Vector[i+1]);
            }
        }
    printVector();
    }
}

void PmergeMe::sortDeque()
{
    printDeque();

    
}