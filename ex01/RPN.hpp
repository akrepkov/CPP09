#pragma once
#include <stack>
#include <iostream>


class RPN{
	private:
		std::stack<int> numbers;
	public:
		RPN();
		~RPN();
		RPN& operator=(const RPN& copy);
		RPN(const RPN& copy);
		void extractInput(std::string data);

};

