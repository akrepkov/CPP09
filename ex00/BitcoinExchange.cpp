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
	}
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
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
	// std::cout << "NOW DATE " << std::put_time(&now_tm, "%Y-%m-%d") << std::endl;
	return (now_tm);
}

bool BitcoinExchange::validDate(int day, int month, int year){
	// std::cout << "DATE " << year << " and " << month << " and " << day << std::endl;
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
    // std::cout << "GIVEN DATE " << tm.tm_mday << "  " << tm.tm_mon + 1  << "  " << tm.tm_year + 1900 << std::endl;
	if (ss.fail() || !validDate(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900) \
		|| (std::difftime(std::mktime(&tm), std::mktime(&now)) > 0)){
		std::cout << "ERROR: Invalid date values for " << date << std::endl;
		return false;
	}
	return true;
}


// bool BitcoinExchange::extractDate(std::string date){
// 	std::tm given_date = parseDate(date);
// 	std::cout << "DATE " << std::put_time(&given_date, "%Y-%m-%d") << std::endl;
// 	return true;
// }


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

// std::string BitcoinExchange::getDate(std::map<std::string, float> data){
// 	return data[rate];
// }

std::map<std::string, float> BitcoinExchange::getData(){
	return this->data;
}