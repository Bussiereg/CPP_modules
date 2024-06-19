#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;
	void	_printMapContent();
	void	_createMap(std::string fileName);
	void	_checkSeparator(std::string const & str);
	void	_checkDateFormat(std::string const & date);
	void	_checkValueValidity(std::string const & date);
	void	_displayOutput(std::string const & inputFile);
	float	_findClosestRate(std::string const & date);
	BitcoinExchange(BitcoinExchange const & rhs);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);
	BitcoinExchange();
public:
	BitcoinExchange(std::string file, std::string inputFile);
	~BitcoinExchange();
	std::map<std::string, double> getDatabase();
};



#endif