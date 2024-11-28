#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

void	PmergeMe::printVector(std::vector<int> vec) {
	for (int nbr : vec) {
		std::cout << " " << nbr << " ";
	}
	std::cout << std::endl;
}

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
bool insertNumber(std::vector<int>& temp, int x, int size) {
	temp.erase(temp.begin() + size);
	int low = 0;
	int high = size - 1;
	int mid;
	if (x < temp[0]) {
		temp.insert(temp.begin(), x);
	}
	else if (x > temp[size]) {
		temp.insert(temp.begin() + size, x);
		return true;
	} else {
		while (low <= high) { 
			mid = low + (high - low) / 2;
			if (x < temp[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		temp.insert(temp.begin() + low, x);
	}
	// for(auto m= temp.begin(); m < (temp.begin() + size + 1); ++m){
	// 		std::cout << " loop  " << *m << " ";
	// 	}
	// 	std::cout << "\n";
	return false;

}

bool insertNumberS(std::vector<int>& temp, int x, int size) {
	int low = 0;
	int high = size - 1;
	int mid;
	if (x < temp[0]) {
		temp.insert(temp.begin(), x);
	}
	else if (x > temp[size]) {
		temp.insert(temp.begin() + size, x);
		return true;
	} else {
		while (low <= high) { 
			mid = low + (high - low) / 2;
			if (x < temp[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		temp.insert(temp.begin() + low, x);
	}
	// for(auto m= temp.begin(); m < (temp.begin() + size + 1); ++m){
	// 		std::cout << " loop  " << *m << " ";
	// 	}
	// 	std::cout << "\n";
	return false;

}
std::vector<int> PmergeMe::alghorithm(std::vector<int>& main) {
	std::vector<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	size_t j = 0;
	while (j < jacobsthal.size()) {
		size_t start = (static_cast<size_t>(jacobsthal[j]) < (main.size() - 1)) ? jacobsthal[j] : (main.size() - 1);
		size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
		std::cout << "Start: " << start << ", End: " << end << std::endl;
		while (start > end) {
			std::cout << " insert " << main[start] << "\n";
			insertNumber(main, main[start], start);
			start--;
		}
		if (start >= main.size() - 1) break;
		j++;
	}
	for(auto m= main.begin(); m != main.end(); ++m){
		std::cout << " main  " << *m << " ";
	}
	std::cout << "\n";
	return main;
}
std::vector<int> PmergeMe::alghorithmSmall(std::vector<int>& main, std::vector<int>& small) {
	std::vector<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	insertNumber(main, small[0], 1);
	size_t j = 0;
	while (j < jacobsthal.size()) {
		size_t start = (static_cast<size_t>(jacobsthal[j]) < (small.size() - 1)) ? jacobsthal[j] : (small.size() - 1);
		size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
		std::cout << "Start: " << start << ", End: " << end << std::endl;
		int i = start;
		while (start > end) {
			std::cout << " insert " << small[start] << "\n";
			insertNumberS(main, small[start], i);
			start--;
		}
		if (start >= small.size() - 1) break;
		j++;
	}
	for(auto m= main.begin(); m != main.end(); ++m){
		std::cout << " main  " << *m << " ";
	}
	std::cout << "\n";
	return main;
}

void PmergeMe::sortVector()
{
	std::vector<int> big;
	std::vector<int> small;

	
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
	// for(auto i= big.begin(); i != big.end(); ++i){
	// 	std::cout  << *i << " ";
	// }
	if (Vector.size() %2 != 0){
		odd = true;
		big.push_back(Vector.back());
	}  
	if (big.size() > 1)
		big = alghorithm(big);
	alghorithmSmall(big, small);
	// std::sort(big.begin(), big.end());
	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << " BIG  " << *i << " ";
	}
	std::cout << "\n";
	// for(auto i= small.begin(); i != small.end(); ++i){
	// 	std::cout << " SMALL  " << *i << " ";
	// }
	std::cout << "\n";
	// alghorithmSmall(big, small);

	
	// std::cout << "\n";
	// std::cout << "\n\n";
	// std::cout << std::endl;
	// alghorithm(big, small);
}

void PmergeMe::sortDeque()
{
	// printDeque();

	
}
