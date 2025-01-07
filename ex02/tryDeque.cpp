#include <deque>
#include <iostream>
#include <algorithm>

bool isAscending(const std::deque<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] <= numbers[i - 1]) {
            std::cout << "Numbers not in ascending order at index " << i << ": " 
                      << numbers[i - 1] << " >= " << numbers[i] << std::endl;
            return false;
        }
    }
    return true;
}

int insertNumber(std::deque<int>& temp, int x, int size, int num) {
    temp.erase(temp.begin() + num); // Remove the element at index 'size'

    int low = 0;
    int high = size;
    int mid;

    if (x < temp[0]) {
        temp.insert(temp.begin(), x); // Insert at the beginning
        return 0;
    }
    else if (x > temp[size]) {
        temp.insert(temp.begin() + size + 1, x); // Insert at the end
        return size + 1;
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
    return low;
}

std::deque<int> alghorithm(std::deque<int>& main, std::deque<int>& small) {
    std::deque<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t j = 0;

    while (j < jacobsthal.size()) {
        size_t start = (jacobsthal[j] < main.size()) ? jacobsthal[j] : main.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;

        std::cout << "Start: " << start << ", End: " << end << std::endl;
        if (start > main.size() - 1 || end > start) break;
		int temp = start;
        while (start > end) {
            int position = insertNumber(main, main[temp], end, temp);
            if (small[start]) {
				int x = small[start];
				small.erase(small.begin() + start);
				small.insert(small.begin() + position, x);
			}
            end++;
        }
        j++;
    }

    std::cout << "SMALL: ";
    for (auto m = small.begin(); m != small.end(); ++m) {
        std::cout << *m << " ";
    }

    std::cout << "\nBIG: ";
    for (auto m = main.begin(); m != main.end(); ++m) {
        std::cout << *m << " ";
    }
    std::cout << "\n";
    return main;
}

std::deque<int> insertSmall(std::deque<int>& temp, int x, int size) {
    int low = 0;
    int high = size;
    int mid;

    if (x < temp[0]) {
        temp.insert(temp.begin(), x); // Insert at the beginning
    }
    else if (x > temp[size]) {
        temp.insert(temp.begin() + size + 1, x); // Insert at the end
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

std::deque<int> algthjorithmforsmallpart(std::deque<int>& main, std::deque<int>& small) {
	std::deque<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	main.insert(main.begin(), small[0]);
    size_t j = 0;

	while (j < jacobsthal.size()) {
        size_t start = (jacobsthal[j] < small.size()) ? jacobsthal[j] : small.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
        if (start > main.size() - 1 || end >= start) break;

		int temp = start - end;
        while (temp != 0) {
			end += 2;
            main = insertSmall(main, small[start], main.size() - 1);
			start--;
            temp--;
        }
        j++;
    }
    return main;
}

int main(int argc, char **argv) {
	/*ADD PROTECTION FOR 1-2 numbers*/
    if (argc < 2) {
        std::cerr << "Error: Incorrect input.\n";
        return 1;
    }

    std::deque<int> Deque;

    // Convert command-line arguments to integers
    for (int i = 1; i < argc; i++) {
        try {
            int num = std::stoi(argv[i]);
            Deque.push_back(num);
        }
        catch (const std::exception& e) {
            std::cout << "Error: Invalid input '" << argv[i] << "'\n";
            return 1;
        }
    }

    std::deque<int> big;
    std::deque<int> small;

    // Swap adjacent elements in pairs
    for (size_t i = 0; i + 1 < Deque.size(); i += 2) {
        if (Deque[i] < Deque[i + 1])
            std::swap(Deque[i], Deque[i + 1]);
    }

    // Split into big and small deque
    for (size_t i = 0; i + 1 < Deque.size(); i += 2) {
        big.push_back(Deque[i]);
    }
    for (size_t i = 1; i < Deque.size(); i += 2) {
        small.push_back(Deque[i]);
    }

    // Apply the algorithm to the 'big' deque
    big = alghorithm(big, small);
	big = algthjorithmforsmallpart(big, small);

	std::cout  << std::boolalpha << isAscending(big) << std::endl;
    return 0;
}
