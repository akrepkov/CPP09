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
/* Need to avoid iterator invalidation*/
void findInsertPos(std::vector<int>& temp, int x, int size, int arr){
	// std::cout << " temp[size-1] " << temp[size-1] << std:: endl;
	// std::cout << "temp" << std::endl;
	// for(auto i= temp.begin(); i != temp.end(); ++i){
	// 	std::cout << " " << *i << " ";
	// }
	int mid;
	// std::cout << "check " << x << " " << temp[0] << " ";
	if (x < temp[0]){
		temp.insert(temp.begin(), x);}
	else if (x > temp[size-1])
		temp.insert(temp.begin()+size, x);
	else{
		int low = 0;
		int high = size - 1;
		std::cout << " FOR findInsertPos " << low << " " << high << " " << x << std:: endl;
		while (high > low){
			mid = low + (high - low)/2;
			if (x < temp[mid])
				high = mid;
			 else
				low = mid + 1;
			
			// std::cout << "Loop " << x  << std:: endl;
		}
		temp.insert(temp.begin() + mid, x);

	}	
	if (arr == 1){
		temp.erase(temp.begin()+size);
		temp.reserve(1); //do I need it?
	}
}

std::vector<int> PmergeMe::mergeInsertionVector(std::vector<int>& big){
	
	if (big.size() == 2){
		if (Vector[0] > Vector[1])
			std::swap(Vector[0], Vector[1]);
	}
	else{
		for (size_t i = 2, iter = 0; i < big.size(); i+=2, iter++){
			// std::cout << " FOR Loop " << i  << std:: endl;
			if (iter % 2 == 0){
				findInsertPos(big, big[i], i, 1);
				// big.erase(big.begin()+i);
			}
			else {
				findInsertPos(big, big[i-1], i-1, 1);
				// big.erase(big.begin()+i - 1);
			}
		}
	}
	return big;
}

void PmergeMe::alghorithm(std::vector<int>& main, std::vector<int> small){
	findInsertPos(main, small[0], 0, 0);
    if (small.size() == 2) {
        findInsertPos(main, small[1], 1, 0);  // Ido i need it?
    }
	for (size_t i = 2, iter = 2; i < small.size(); i+=2, iter++){
		// if (odd == true){
		// 	if (iter == (main.size() / 2) - 2){
		// 		findInsertPos(main, main.back(), i, 0);
		// 		continue;
		// 	}
		// }
		//std::cout << " FOR Loop " << i  << std:: endl;
		if (iter % 2 == 0)
			findInsertPos(main, small[i], i, 0);
		else
			{
				std::cout << "checking " << small[i-1] << std::endl;
				findInsertPos(main, small[i-1], i-1, 0);}
	}
}


void PmergeMe::sortVector()
{
	std::vector<int> big;
	std::vector<int> small;

	printVector();
	if (Vector.size() == 0)
		std::cout << "Error";
	for (size_t i = 0; i+1 < Vector.size(); i+=2){
		if (Vector[i] < Vector[i+1])
			std::swap(Vector[i], Vector[i+1]);
	}
	for (size_t i = 0; i+1 < Vector.size(); i+=2){
		big.push_back(Vector[i]);
	}
	for (size_t i = 1; i < Vector.size(); i+=2){
		small.push_back(Vector[i]);
	}
	if (big.size() > 1)
		big = mergeInsertionVector(big);
	if (Vector.size() %2 != 0){
		odd = true;
		big.push_back(Vector.back());
	}
	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << " BIG  " << *i << " ";
	}
	std::cout << "\n";
	for(auto i= small.begin(); i != small.end(); ++i){
		std::cout << " SMALL  " << *i << " ";
	}
	std::cout << "\n\n";
	std::cout << std::endl;
	alghorithm(big, small);
	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << " BIG  " << *i << " ";
	}
}

void PmergeMe::sortDeque()
{
	// printDeque();

	
}