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

int insertNumber(std::deque<int>& temp, int x, int size, int num, int flag) {
    if (flag == 0)
        temp.erase(temp.begin() + num); // Remove the element at index 'size'
    int low = 0;
    while (low <= size) {
        int mid = low + (size - low) / 2;
        if (x < temp[mid])
            size = mid - 1;
        else
            low = mid + 1;
    }
    temp.insert(temp.begin() + low, x); // Insert at the correct position
    return low;
}

std::deque<int> alghorithm(std::deque<int>& main, std::deque<int>& small) {
    std::deque<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    size_t j = 0;
    while (j < jacobsthal.size()) {
        size_t start = (jacobsthal[j] < main.size()) ? jacobsthal[j] : main.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
        while (start > end) {
            int position = insertNumber(main, main[start], end, start, 0);
            if (small[start]) {
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

std::deque<int> algthjorithmforsmallpart(std::deque<int>& main, std::deque<int>& small) {
	std::deque<int> jacobsthal = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
	main.insert(main.begin(), small[0]);
    size_t j = 0;

	while (j < jacobsthal.size()) {
        size_t start = (jacobsthal[j] < small.size()) ? jacobsthal[j] : small.size() - 1;
        size_t end = (j > 0) ? jacobsthal[j - 1] : 0;
        if (start > main.size() - 1 || end >= start) break;
		int temp = start - end;
        end = start + end + 2;
        while (temp != 0) {
            insertNumber(main, small[start], end , 0,  1); // or main.size() - 1
			start--;
            temp--;
			end++;
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

    // ACCEPT WITH " " AND WITHOUT????
    for (int i = 1; i < argc; i++) {
        try {
            int num = std::stoi(argv[i]);
            Deque.push_back(num);
            if (i > 3000) {
                std::cerr << "Error: More than 3000 numbers" << std::endl;
                return 1;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: Invalid input '" << argv[i] << std::endl;
            return 1;
        }
    }

    std::deque<int> big;
    std::deque<int> small;

    // CHECK IF UNEVEN NUMVBER
    for (size_t i = 0; i + 1 < Deque.size(); i += 2) {
        if (Deque[i] > Deque[i + 1]){
            big.push_back((Deque[i] > Deque[i + 1]) ? Deque[i] : Deque[i + 1]);
            small.push_back((Deque[i] > Deque[i + 1]) ? Deque[i + 1] : Deque[i]);
        }
    }
    big = alghorithm(big, small);
	big = algthjorithmforsmallpart(big, small);
	std::cout  << std::boolalpha << isAscending(big) << std::endl;
    return 0;
}
