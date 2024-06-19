#ifndef STREAMREPLACE_HPP
# define STREAMREPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <sstream>

class StreamReplace
{
private:
	std::string _outfile;
	std::string _infile;
	void	_replace(std::string str1, std::string str2);
public:
	StreamReplace(std::string filename, std::string str1, std::string str2);
	~StreamReplace();
};

#endif