
#include <string>
#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <sstream>
#include <map>
#include <regex>
#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include "BitcoinExchange.hpp"

void BitcoinExchange::parsingInput(std::string line, BitcoinExchange& Exchange, char del){
	std::istringstream str(line);
	std::string date;
	std::string rate;
	std::getline(str, date, del);
	std::getline(str, rate, del);
	// std::cout << "Error in the date: " << date << std::endl;
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

void BitcoinExchange::findClosest(std::string targetDate, int value) {
    if (data.empty()) {
        throw std::runtime_error("Data map is empty.");
    }
	auto it = data.lower_bound(targetDate);
	if (it != data.begin()) {
		auto prevIt = std::prev(it);
	std::cout << "Didn't find needed date, get the rate from " << prevIt->first << std::endl;
	std::cout << targetDate << "=> " << value << " = "  << prevIt->second * value << std::endl;
	}

}

void BitcoinExchange::findDate(std::string line){
	std::istringstream str(line);
	std::string date;
	std::string del;
	std::string valueStr;
	double value;
	str >> date >> del >> valueStr;
	try {
		value = std::stod(valueStr);
		if (value < 0){
			std::cerr << "Error: '" << valueStr << "' is not a valid rate." << std::endl;
			return ;
		}
	} catch (const std::exception& e){
		std::cerr << "Error: '" << valueStr << "' is not a valid number." << std::endl;
		return ;
	}
    if (data.find(date) != data.end()) {
		double result = value * data[date];
		std::cout << date << "=> " << value << " = "  << result << std::endl;
    } else {
       	this->findClosest(date, value);
    }
}

int main(int argc, char **argv){
	BitcoinExchange DataExchange;
	if (argc == 2){
		std::ifstream dataFile("data.csv");//CHANGE!!!!!!!!!!
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
			DataExchange.findDate(line);
		}
		dataFile.close();
		inputFile.close();
		/*
		skip date | value 
		check non existing dates
		*/
	}
	else
		std::cout << "The program takes 1 file as an argument" << std::endl;
}

/*Map*/

