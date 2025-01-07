#include <vector>
#include <iostream>
#include <algorithm>

bool isAscending(const std::vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] <= numbers[i - 1]) {
            std::cout << "Numbers not in ascending order at index " << i << ": " 
                      << numbers[i - 1] << " >= " << numbers[i] << std::endl;
            return false;
        }
    }
    return true;
}


std::vector<int> insertNumber(std::vector<int>& temp, int x, int size, int num) {
    // if (size > temp.size()) {
    //     std::cerr << "Error: Invalid size for erase operation.\n";
    //     return temp;
    // }

    temp.erase(temp.begin() + num); // Remove the element at index 'size'

    int low = 0;
    int high = size;
    int mid;

    if (x < temp[0]) {
        temp.insert(temp.begin(), x); // Insert at the beginning
    }
    else if (x > temp[size]) {
		std::cout << "Should add at the end"<< std::endl;
        temp.insert(temp.begin() + size + 1, x); // Insert at the end
		for (auto m = temp.begin(); m != temp.begin() + size; ++m) {
			std::cout << " main  " << *m << " ";
		}
		std::cout << "\n";
    }
    else {
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (x < temp[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        temp.insert(temp.begin() + low, x); // Insert at the correct position
    }
    return temp;
}

std::vector<int> alghorithm(std::vector<int>& main) {
    std::vector<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t j = 0;
    for (auto m = main.begin(); m != main.end(); ++m) {
        std::cout << *m << " ";
    }
    std::cout << "\n";
    while (j < jacobsthal.size()) {
        // Ensure start does not go out of bounds
        size_t start = (jacobsthal[j] < main.size()) ? jacobsthal[j] : main.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;

        if (start > main.size() - 1 || end > start) break;
        std::cout << "Start: " << start << ", End: " << end << std::endl;
		int temp = start;
        while (start > end) {
            std::cout << " insert " << main[temp] << "\n";
            main = insertNumber(main, main[temp], end, temp);
            end++;
        }
        j++;
    }

    for (auto m = main.begin(); m != main.end(); ++m) {
        std::cout << " main  " << *m << " ";
    }
    std::cout << "\n";
    return main;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided.\n";
        return 1;
    }

    std::vector<int> Vector;

    // Convert command-line arguments to integers
    for (int i = 1; i < argc; i++) {
        try {
            int num = std::stoi(argv[i]);
            Vector.push_back(num);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: Invalid input '" << argv[i] << "'\n";
            return 1;
        }
    }

    std::vector<int> big;
    std::vector<int> small;

    // Swap adjacent elements in pairs
    for (size_t i = 0; i + 1 < Vector.size(); i += 2) {
        if (Vector[i] < Vector[i + 1])
            std::swap(Vector[i], Vector[i + 1]);
    }

    // Split into big and small vectors
    for (size_t i = 0; i + 1 < Vector.size(); i += 2) {
        big.push_back(Vector[i]);
    }
    for (size_t i = 1; i < Vector.size(); i += 2) {
        small.push_back(Vector[i]);
    }

    // Apply the algorithm to the 'big' vector
    big = alghorithm(big);

    std::cout << " result: \n";
    for (auto i = big.begin(); i != big.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
	std::cout  << std::boolalpha << isAscending(big) << std::endl;
    return 0;
}
