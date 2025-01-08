#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <exception> 

bool isIntegerString(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}


/*
check for doubles
Check for empty str
1 number
2 numbers str
`shuf -i 1-100000 -n 3000 | tr "\n" " "`
*/
int main(int argc, char **argv){
	PmergeMe SequenceSort;
	std::string token;
	try {
		for (int i = 1; i < argc; ++i) {
		std::string token = argv[i];
		if (isIntegerString(token)) {
			int num = std::stoi(token);
			SequenceSort.addToVector(num);
			SequenceSort.addToDeque(num);
		} else {
			std::cerr << "Error: Invalid format for token: " << token << std::endl;
			return 1;
		}
	}
	SequenceSort.sortContainer();    
	}
	catch(const std::exception& e){
		std::cerr << "Error " << e.what() << std::endl; //add exceptions
	}
return 0;
}

/*
Vector:
Random access to elements is very fast, with O(1) time complexity since elements are stored contiguously in memory. 
Insertions and deletions at the end of a vector are efficient, O(1) on average. However, insertions or deletions at the beginning or middle are slower, O(n), because all subsequent elements must be shifted.

Deque:
A std::deque (double-ended queue) is not contiguous in memory. Instead, it’s implemented as a series of chunks (blocks of memory) or arrays, each pointing to another.
Insertions and deletions are O(1) at both the front and the back. Inserting at the middle is O(n), similar to std::vector.

*/

/*
<p>Now you have to check this operation by using the following command as an <br>
argument to the program:</p>

`shuf -i 1-1000 -n 3000 | tr "\n" " " `


<p>If the command works correctly, the person being evaluated should be able to <br>
explain the difference in time used for each container selected.</p>
*/

/*

*/