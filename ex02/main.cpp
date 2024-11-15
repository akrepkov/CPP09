#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>


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
*/
int main(int argc, char **argv){
    if (argc == 2){
       PmergeMe VectorSort;
       PmergeMe DequeSort;
       //check if it's valid and has numbers
       std::stringstream ss(argv[1]);
       std::string token;
       while(ss >> token){
            if (isIntegerString(token)){ 
                int num = stoi(token);
                VectorSort.addToVector(num);
                DequeSort.addToDeque(num);
            }
       }
        VectorSort.sortVector();
        DequeSort.sortDeque();       
    }
    else
        std::cout << "Error" << std::endl; //add exceptions
    //check doubles
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