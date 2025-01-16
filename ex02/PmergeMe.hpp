#pragma once
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int> Vector;
        std::deque<int> Deque;
		bool odd = false;
		int oddNum;
    public:
        PmergeMe() = default;
        ~PmergeMe() = default;

        PmergeMe(PmergeMe& copy);

        PmergeMe& operator=(const PmergeMe& copy);

        void addToVector(int num){Vector.push_back(num);}
        void addToDeque(int num){Deque.push_back(num);}
		void sortContainer();

		template <typename Container>
		int insertNumber(Container& temp, int x, int size, int num, int flag);

		template <typename Container>
		Container& alghorithm(Container& main, Container& small);

		template <typename Container>
		Container& algthjorithmforsmallpart(Container& main, Container& small);

		template <typename Container>
		void	printSequence(Container& x);

};
