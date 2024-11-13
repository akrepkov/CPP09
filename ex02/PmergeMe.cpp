#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>

PmergeMe::PmergeMe(const PmergeMe& copy){
//rewrite
}
PmergeMe& PmergeMe::operator=(const PmergeMe& copy){
    return *this; //rewrite
}

void PmergeMe::printVector(){
    for(auto i= Vector.begin(); i != Vector.end(); ++i){
        std::cout << " " << *i << " " << std::endl;
    }
}

void PmergeMe::printDeque(){
    for(auto i= Deque.begin(); i != Deque.end(); ++i){
        std::cout << " " << *i << " " << std::endl;
    }
}


void PmergeMe::sortVector()
{
    printVector();


}

void PmergeMe::sortDeque()
{
    printDeque();

    
}