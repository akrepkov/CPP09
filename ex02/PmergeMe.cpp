#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <chrono>

template <typename Container>
void	PmergeMe::printSequence(Container& x) {
	for (int nbr : x) {
		std::cout << " " << nbr << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(PmergeMe& copy){
	this->Deque = copy.Deque;
	this->Vector = copy.Vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy){
	if (this != &copy){
		this->Vector = copy.Vector;
		this->Deque = copy.Deque;	
	}
	return *this;
}
template <typename Container>
bool isAscending(Container& numbers) {
	for (size_t i = 1; i < numbers.size(); ++i) {
		if (numbers[i] < numbers[i - 1]) {
			std::cout << "Error: " << numbers[i - 1] << " >= " << numbers[i] << std::endl;
			return false;
		}
	}
	return true;
}

template <typename Container>
int PmergeMe::insertNumber(Container& temp, int x, int size, int num, int flag) {
	if (flag == 0)
    	temp.erase(temp.begin() + num);
    int low = 0;
    int high = size;
    int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (x < temp[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        temp.insert(temp.begin() + low, x);;
    return low;
}

template <typename Container>
Container& PmergeMe::alghorithm(Container& main, Container& small) {
    std::vector<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t j = 0;
	size_t end;
    while (j < jacobsthal.size()) {
        size_t start = ((size_t)jacobsthal[j] < main.size()) ? jacobsthal[j] : main.size() - 1;
        end = (j > 0) ? jacobsthal[j - 1] : 0;
        if (start > main.size() - 1 || end > start) break;
		int temp = start;
        while (start > end) {
			if (odd && end == main.size() - 1) 
				continue;
            int position = insertNumber(main, main[temp], end, temp, 0);
			if (start <small.size()){
				int x = small[start];
				small.erase(small.begin() + start);
				small.insert(small.begin() + position, x);
			}
            end++;
        }
        j++;
    }
    return main;
}

template <typename Container>
Container& PmergeMe::algthjorithmforsmallpart(Container& main, Container& small) {
	std::vector<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	main.insert(main.begin(), small[0]);
    size_t j = 0;
	while (j < jacobsthal.size()) {
        size_t start = ((size_t)jacobsthal[j] < small.size()) ? jacobsthal[j] : small.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
        if (start > main.size() - 1 || end >= start) break;
		int temp = start - end;
        end = start + end + 2;
        while (temp != 0) {
            insertNumber(main, small[start], end , 0,  1);
			start--;
            temp--;
			end++;
        }
        j++;
    }
	if (odd) 
		insertNumber(main, oddNum, main.size() - 1, 0, 1);
    return main;
}

void PmergeMe::sortContainer()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> startVector = std::chrono::high_resolution_clock::now();
	std::cout  << "\033[1;32mBefore:\033[0m ";
	printSequence(Vector);
	std::cout  << "\033[1;34mVector check:\033[0m" << std::endl;
    std::vector<int> bigVector;
    std::vector<int> smallVector;
    for (size_t i = 0; i + 1 <= Vector.size(); i += 2) {
		if (Vector.size()%2 != 0 && i == Vector.size() - 1){
			odd = true;
			oddNum = Vector[i];
		}
		else {
			bigVector.push_back((Vector[i] > Vector[i + 1]) ? Vector[i] : Vector[i + 1]);
			smallVector.push_back((Vector[i] > Vector[i + 1]) ? Vector[i + 1] : Vector[i]);
		}
    }
	if (Vector.size() > 1){
		bigVector = alghorithm(bigVector, smallVector);
		bigVector = algthjorithmforsmallpart(bigVector, smallVector);
	}
	std::chrono::time_point<std::chrono::high_resolution_clock> endVector = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elapsedVector = endVector - startVector;
	std::cout  << "After: ";
	printSequence(bigVector);
	std::cout << "Time to process a range of " << Vector.size() << " elements with std::vector is " << elapsedVector.count() << " us" << std::endl;
	std::cout  << std::boolalpha << isAscending(bigVector) << std::endl;

	std::chrono::time_point<std::chrono::high_resolution_clock> startDeque = std::chrono::high_resolution_clock::now();
	std::cout  << "\033[1;34mDeque check:\033[0m" << std::endl;
    std::deque<int> bigDeque;
    std::deque<int> smallDeque;
    for (size_t i = 0; i + 1 <= Deque.size(); i += 2) {
		if (Deque.size()%2 != 0 && i == Deque.size() - 1){
			odd = true;
			oddNum = oddNum = Deque[i];;
		}
		else {
			if (Deque[i] > Deque[i + 1]) {
				bigDeque.push_back(Deque[i]);
				smallDeque.push_back(Deque[i + 1]);
			} else {
				bigDeque.push_back(Deque[i + 1]);
				smallDeque.push_back(Deque[i]);
			}
		}
    }
	if (Deque.size() > 1){
		bigDeque = alghorithm(bigDeque, smallDeque);
		bigDeque = algthjorithmforsmallpart(bigDeque, smallDeque);
	}
	std::chrono::time_point<std::chrono::high_resolution_clock> endDeque = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro>  elapsedDeque = endDeque - startDeque;
	std::cout  << "After: ";
	printSequence(bigDeque);
	std::cout << "Time to process a range of " << Deque.size() << " elements with std::deque is "  << elapsedDeque.count() << " us" << std::endl;
	std::cout  << std::boolalpha << isAscending(bigDeque) << std::endl;
	std::cout  << std::endl;

}

