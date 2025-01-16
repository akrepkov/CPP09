#include "BitcoinExchange.hpp"
#include <regex>
#include <iostream>
#include <chrono>
#include <iomanip> 


BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		this->data = copy.data;
	}
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	this->data = copy.data;
}

bool BitcoinExchange::leapYear(int year){
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 != 0))
		return true;
	return false;
}

std::tm nowCheck(){
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm = *std::localtime(&now_time_t);
	return (now_tm);
}

bool BitcoinExchange::validDate(int day, int month, int year){
	if (month < 1 || month > 12 || year < 1900)
		return false;
	int monthEnd[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (leapYear(year))
		monthEnd[1] = 29;
	if (day < 0 || day > monthEnd[month - 1])
		return false;
	return true;
}


bool BitcoinExchange::extractDate(std::string date){
	std::tm tm = {};
	std::tm now = nowCheck();
	std::stringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail() || !validDate(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900) \
		|| (std::difftime(std::mktime(&tm), std::mktime(&now)) > 0)){
		std::cout << "ERROR: Invalid date values for " << date << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::getRate(std::string date){
	auto it = data.find(date);
	if (it != data.end())
		return it->second;
	return 0;

}

void BitcoinExchange::setData(std::string date, float rate){
	if (extractDate(date))
		data[date] = rate;
}


std::map<std::string, float> BitcoinExchange::getData(){
	return this->data;
}

void BitcoinExchange::parsingInput(std::string line, BitcoinExchange& Exchange, char del){
	std::istringstream str(line);
	std::string date;
	std::string rate;
	std::getline(str, date, del);
	std::getline(str, rate, del);
	if (date.empty() || rate.empty())
		return ;
	std::regex floatRegex(R"([+]?(\d+(\.\d+)?|\.\d+))");
	if (!std::regex_match(rate, floatRegex)){
		std::cout << "Invalid number " << rate  << "\n" << std::endl;
		return ;
	}
	try {
		float exchange = std::stof(rate);
		Exchange.setData(date, exchange);
	} catch (std::exception& e){
		std::cerr << "Error: " <<  e.what() << std::endl;
		return;
	}
	
}

void BitcoinExchange::findClosest(std::string targetDate, int value) {
    if (data.empty()) {
        throw std::runtime_error("Data map is empty.");
    }
	auto it = data.lower_bound(targetDate);
	if (it != data.begin()) {
		auto prevIt = std::prev(it);
	std::cout << "Didn't find needed date, get the rate from " << prevIt->first << std::endl;
	std::cout << targetDate << "=> " << value << " = "  << prevIt->second * value << "\n" << std::endl;
	}
	else {
		std::cout << "The bitoin price was not measured" << "\n" << std::endl;
	}

}

void BitcoinExchange::findDate(std::string line){
	std::istringstream str(line);
	std::string date;
	std::string del;
	std::string valueStr;
	double value;
	str >> date >> del >> valueStr;
	std::regex floatRegex(R"(\d{4}-\d{2}-\d{2})");
	if (!std::regex_match(date, floatRegex)){
		std::cout << "Invalid date \n" << std::endl;
		return ;
	}
	try {
		std::regex valueRegex(R"([+]?(\d+(\.\d+)?|\.\d+))");
		if (!std::regex_match(valueStr, valueRegex)){
			std::cout << "Invalid rate \n" << std::endl;
			return ;
		}
		value = std::stod(valueStr);
		if (value < 0 || value > 1000){
			std::cerr << "Error: '" << valueStr << "' is not a valid rate." << "\n" << std::endl;
			return ;
		}
	} catch (const std::exception& e){
		std::cerr << "Error: '" << valueStr << "' is not a valid number." << "\n" << std::endl;
		return ;
	}
    if (data.find(date) != data.end()) {
		double result = value * data[date];
		std::cout << date << "=> " << value << " = "  << result << "\n" << std::endl;
    } else {
       	this->findClosest(date, value);
    }
}