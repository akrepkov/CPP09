
#include <string>
#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include "BitcoinExchange.hpp"

void BitcoinExchange::parsingInput(std::string line, BitcoinExchange& Exchange, char del){
	std::istringstream str(line);
	std::string date;
	std::string rate;
	std::getline(str, date, del);
	std::getline(str, rate, del);
	std::cout << "Error in the date: " << date << std::endl;
	// std::cout << "CHECK " << rate << "|      |" << date << std::endl;
	if (date.empty() || rate.empty())
		return ;
	std::regex floatRegex(R"([+-]?(\d+(\.\d*)?|\.\d+))");
	if (!std::regex_match(rate, floatRegex)){
		std::cout << "Invalid number " << rate << std::endl;
		return ;
	}
	float exchange = std::stof(rate);
	Exchange.setData(date, exchange);
	
}

void BitcoinExchange::findClosest(std::string date){
	std::cout << date << std::endl;

	
	// Add catch and try everywhere
	// Add logic for finding closest date
}

void BitcoinExchange::findDate(std::string line){
	std::istringstream str(line);
	std::string date;
	std::string del;
	std::string valueStr;
	str >> date >> del >> valueStr;
    if (data.find(date) != data.end()) {
		try {
			double value = std::stod(valueStr);
			double result = value * data[date];
			std::cout << date << "=> " << value << " = "  << result << std::endl;
		}
		catch (const std::exception& e){
			std::cerr << "Error: '" << valueStr << "' is not a valid number." << std::endl;
		}
    } else {
        this->findClosest(date);
    }
}

int main(int argc, char **argv){
	BitcoinExchange DataExchange;
	if (argc == 2){
		std::ifstream dataFile("fake_data.csv");//CHANGE!!!!!!!!!!
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
			DataExchange.findDate(line);
		}
		dataFile.close();
		inputFile.close();
	}
	else
		std::cout << "The program takes 1 file as an argument" << std::endl;
}

/*Map*/

