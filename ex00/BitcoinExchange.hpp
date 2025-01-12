

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP
#include <map>
#include <string>

class BitcoinExchange{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		BitcoinExchange(const BitcoinExchange& copy);
		bool leapYear(int year);
		bool validDate(int day, int month, int year);
		float getRate(std::string date);
		std::map<std::string, float> getData();
		void setData(std::string date, float rate);
		bool extractDate(std::string date);
		void findDate(std::string line);
		// std::string getDate(std::map<std::string, float> data);

		void parsingInput(std::string line, BitcoinExchange& Exchange, char del);
		void findClosest(std::string date, int value);

};

#endif
