#include "BitcoinExchange.hpp"

void BitcoinExchange::_printMapContent(){
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator ite = _database.end();

	for (it=_database.begin(); it != ite; it++)
		std::cout << it->first << "," << it->second << std::endl;
}

void BitcoinExchange::_createMap(std::string fileName){
	std::ifstream file(fileName.c_str());
	if (!file.is_open()) {
		std::cout << "Error while opening the file data.csv " << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)){
		std::stringstream buffer(line);
		std::string key, value;
		std::getline(buffer, key, ',');
		std::getline(buffer, value, ',');
		_database.insert(std::pair<std::string, double>(key , std::atof(value.c_str())));
	}
}

void	BitcoinExchange::_checkValueValidity(std::string const & value){
    if (value.empty()){
		std::cout << "Error:: empty number" << std::endl;
        throw std::exception();
	}

    bool dotFound = false;
    for (size_t i = 0; i < value.size(); ++i) {
        if (isdigit(value[i]) || value[i] == '-' || value[i] == '+') {
            continue;
        } 
		else if (value[i] == '.') {
            if (dotFound){
				std::cout << "Error:: not a number" << std::endl;
				throw std::exception();
			}
            dotFound = true;
        } 
		else {
			std::cout << "Error:: not a number" << std::endl;
			throw std::exception();
		}
    }

    double number = atof(value.c_str());
    if (number > 1000){
		std::cout << "Error: too large number" << std::endl;
		throw std::exception();
	}
    else if (number < 0){
		std::cout << "Error: not a positive number" << std::endl;
		throw std::exception();
	}
}

void	BitcoinExchange::_checkSeparator(std::string const & str){
	if (str.find(" | ") == std::string::npos){
		std::cout << "Error: bad input => "<< str << std::endl;
		throw std::exception();
	}
}

void	BitcoinExchange::_checkDateFormat(std::string const & date){
    if (date.size() != 10 ){
		std::cout << "Error: bad input" << " => " << date << std::endl;
        throw std::exception();
	}
	if (date[4] != '-' || date[7] != '-'){
		std::cout << "Error: bad input" << " => " << date << std::endl;
        throw std::exception();
	}

    int year, month, day;
    char dash;
    std::istringstream iss(date);
    iss >> year >> dash >> month >> dash >> day;

    if (iss.fail() || iss.peek() != EOF || year < 0 || month < 1 || month > 12 || day < 1 || day > 31){
		std::cout << "Error:: bad input" << " => " << date << std::endl;
        throw std::exception();
	}

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (!isLeapYear && day > 28){
		std::cout << "Error:: bad input" << " => " << date << std::endl;
        throw std::exception();
	}
        if (isLeapYear && day > 29){
		std::cout << "Error:: bad input" << " => " << date << std::endl;
        throw std::exception();
	}
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
		std::cout << "Error:: bad input" << " => " << date << std::endl;
        throw std::exception();
	}
}

float	BitcoinExchange::_findClosestRate(std::string const & date){
	if (_database.find(date) != _database.end())
		return (_database.find(date)->second);
    std::istringstream iss(date);
    int year, month, day;
    char dash;
    iss >> year >> dash >> month >> dash >> day;
	int datum[3] = {year, month, day};
	std::map<std::string, double>::iterator it;
	std::map<std::string, double>::iterator ite = _database.end();
	std::map<std::string, double>::iterator itStart = _database.begin();
	for (int i = 0; i < 3; i++){
		for (it = itStart; it!=ite; ++it){

			std::istringstream iss2(it->first);
			int year2, month2, day2;
			iss2 >> year2 >> dash >> month2 >> dash >> day2;
			int datum2[3] = {year2, month2, day2};
			if ((datum[i] < datum2[i]) && it == _database.begin()){
				return 0;
			}
			else if (datum[i] < datum2[i]){
				itStart = --it;
				break;
			}
			else if (datum[i] == datum2[i]){
				itStart = it;
				break;
			}
		}
		if (it == ite){
			itStart = --ite;
			break;
		}
	}
	return itStart->second;

}

void BitcoinExchange::_displayOutput(std::string const & inputFile){
	std::ifstream file(inputFile.c_str());
	if (!file.is_open()) {
		std::cout << "Error while opening the file: " << inputFile << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)){
		std::stringstream buffer(line);
		std::string date, value;
		try
		{
			_checkSeparator(line);
			std::getline(buffer, date, '|');
			std::getline(buffer, value, '|');
			if (!date.empty() && (date[date.size() - 1] == ' '))
				date.erase(date.size() - 1);
			if (!value.empty() && (value[0] == ' '))
				value.erase(0, 1);
			_checkDateFormat(date);
			_checkValueValidity(value);
			std::cout << date << " => " << value << " = " << std::atof(value.c_str()) * _findClosestRate(date) << std::endl;
		}
		catch(const std::exception& e){}
	}
}

BitcoinExchange::BitcoinExchange(std::string fileName, std::string inputFile)
{
	_createMap(fileName);
	_displayOutput(inputFile);
}

std::map<std::string, double> BitcoinExchange::getDatabase(){
	return (_database);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & rhs){
	if (this != &rhs)
		*this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){
	_database = rhs._database;
	return *this;
}

BitcoinExchange::BitcoinExchange(){
	std::cout << "You can't instantiate from this constructor" << std::endl;
}

BitcoinExchange::~BitcoinExchange(){
}
