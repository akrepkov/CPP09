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
	std::cout << "Input " << std::endl;
	for(auto i= Vector.begin(); i != Vector.end(); ++i){
		std::cout << *i << " ";
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

bool findInsertPos(std::vector<int>& temp, int x, int size, int arr){
	int mid;
	if (x < temp[0]){
		temp.insert(temp.begin(), x);}
	else if (x > temp[size]){
		temp.insert(temp.begin()+size, x);
		return 1;
	}
	else{
		int low = 0;
		int high = size;
		while (high >= low){
			mid = low + (high - low)/2;
			if (x <= temp[mid])
				high = mid - 1;
			 else
				low = mid + 1;
		}
		temp.insert(temp.begin() + low, x);

	}
	if (arr == 1){
		temp.erase(temp.begin()+size);
	}
	return 0;
}

int binarySearch(std::vector<int>& arr, int key, int low, int high) {
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::insertionSortVector(std::vector<int>& main){
	for (size_t i = 1; i < main.size(); ++i) {
		int key = main[i];
		int insertPos = binarySearch(main, key, 0, i);
		for (int j = i; j > insertPos; --j) {
			main[j] = main[j - 1];
		}
		main[insertPos] = key;
	}
}

void insertionSmallVector(std::vector<int>& main, int i) {
	auto pos = binarySearch(main, i, 0, main.size());
	main.insert(main.begin() + pos, i);
	for(int h = 0; main[h]; h++)
		std::cout << " " << main[h] << " ";
	std::cout << "\n";
}

void PmergeMe::alghorithm(std::vector<int>& main, std::vector<int> small){
	std::vector<int> jacobsthal = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	int jIndex = 1;
	int j = 0;
	insertionSmallVector(main, small[0]); 
	while(static_cast<size_t>(jacobsthal[jIndex]) <= small.size()){
		j = std::min(static_cast<size_t>(jacobsthal[jIndex]), small.size());
		std::cout << "J " << j << std::endl;
		for (int i = j; i > jacobsthal[jIndex-1]; i--){
		
			std::cout << "small[i] " << small[i] << std::endl;
			insertionSmallVector(main, small[i]); 
		}
		jIndex++;
	}

}
void PmergeMe::sortVector()
{
	std::vector<int> big;
	std::vector<int> small;

	printVector();
	if (Vector.size() < 2){
		if (Vector.size() < 1) std::cerr << "The input is empty" << std::endl;
		else std::cout << "Result: "<< Vector[0] << std::endl;
		return ;
	}
	for (size_t i = 0; i < Vector.size(); i+=2){
		if (Vector[i] < Vector[i+1])
			std::swap(Vector[i], Vector[i+1]);
	}
	for (size_t i = 0; i < Vector.size(); i+=2){
		big.push_back(Vector[i]);
	}
	for (size_t i = 1; i < Vector.size(); i+=2){
		small.push_back(Vector[i]);
	}
	insertionSortVector(big);
	alghorithm(big, small);
	std::cout << "Result: ";
	for(auto i= big.begin(); i != big.end(); ++i){
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortDeque()
{
	// printDeque();

	
}
