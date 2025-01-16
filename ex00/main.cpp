
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	BitcoinExchange DataExchange;
	if (argc == 2){
		std::ifstream dataFile("data.csv");
		std::ifstream inputFile(argv[1]);
		if (!dataFile || !inputFile){
			std::cout << "Can't open the file" << std::endl;
			return 0;
		}
		std::string line;
		std::getline(dataFile, line);
		while(std::getline(dataFile, line)){
			DataExchange.parsingInput(line, DataExchange, ',');
		}
		std::string line2;
		while(std::getline(inputFile, line)){
			if (line == "date | value")
				continue ;
			std::cout << "\033[1;32m" << line << "\033[0m" << std::endl;
			DataExchange.findDate(line);
		}
		dataFile.close();
		inputFile.close();
	}
	else
		std::cout << "The program takes 1 file as an argument" << std::endl;
}

/*Map
The keys (dates) in std::map are automatically kept sorted. 

Since the dates are stored as keys, you can easily find the closest earlier date using functions like lower_bound()
*/

