#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>


PmergeMe::PmergeMe(const PmergeMe& copy){
	this->Vector = copy.Vector;
	this->Deque = copy.Deque;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& copy){
	if (this != &copy){
		this->Vector = copy.Vector;
		this->Deque = copy.Deque;		
	}
	return *this;
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

void findInsertPos(std::vector<int>& temp, int x, int size){
	int mid;
	if (x < temp[0])
		temp.insert(temp.begin(), x);
	else if (x > temp.back())
		temp.insert(temp.end(), x);
	else{
		int low = 0;
		int high = size;
		while (high > low){
			mid = low + (high - low)/2;
			if (x < temp[mid])
				high = mid;
			 else
				low = mid + 1;
			
			std::cout << "Loop " << x  << std:: endl;
		}
		temp.insert(temp.begin() + mid, x);
	}	
}

std::vector<int> PmergeMe::mergeInsertionVector(std::vector<int> big){
	
	std::vector<int> temp;
	if (big.size() == 2){
		if (Vector[0] > Vector[1])
			std::swap(Vector[0], Vector[1]);
	}
	else{
		temp.push_back(big[0]);
		for (size_t i = 2, iter = 1; i <= big.size(); i+=2, iter++){
			std::cout << " FOR Loop " << i  << std:: endl;
			if (iter % 2 == 0)
				findInsertPos(temp, big[i], temp.size());
			else
				findInsertPos(temp, big[i-1], temp.size());
		}
	}
	return temp;
}


void PmergeMe::sortVector()
{
	std::vector<int> big;
	// std::vector<int> small;

	printVector();
	// if (Vector.size() == 0)
	// 	std::cout << "Error";
	for (size_t i = 0; i+1 < Vector.size(); i+=2){
		if (Vector[i] < Vector[i+1])
			std::swap(Vector[i], Vector[i+1]);
	}
	for (size_t i = 0; i+1 < Vector.size(); i+=2){
		big.push_back(Vector[i]);
	}
	// for (size_t i = 1; i < Vector.size(); i+=2){
	// 	small.push_back(Vector[i]);
	// }
	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << " BIG  " << *i << " ";
	}
	if (big.size() > 1)
		big = mergeInsertionVector(big);
	// if (Vector.size() %2 != 0){
	// 	odd = true;
	// 	big.push_back(Vector.back());
	// }

	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << " BIG  " << *i << " ";
	}
	// for(auto i= small.begin(); i != small.end(); ++i){
	// 	std::cout << " SMALL  " << *i << " ";
	// }
}

void PmergeMe::sortDeque()
{
	// printDeque();

	
}