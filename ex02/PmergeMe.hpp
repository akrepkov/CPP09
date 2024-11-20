#pragma once
#include <vector>
#include <deque>


class PmergeMe {
    private:
        std::vector<int> Vector;
        std::deque<int> Deque;
    public:
		bool odd = false;
        PmergeMe() = default;
        ~PmergeMe() = default;
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& copy);
        std::vector<int>& getVector(){return Vector;}
        std::deque<int>& getDeque(){return Deque;}
        void addToVector(int num){Vector.push_back(num);}
        void addToDeque(int num){Deque.push_back(num);}
        void sortDeque();
        void sortVector();
		std::vector<int> mergeInsertionVector(std::vector<int>& big);
		void alghorithm(std::vector<int>& main, std::vector<int> small);
		void printVector(std::vector<int> vec);


        void printDeque();
        void printVector();
};