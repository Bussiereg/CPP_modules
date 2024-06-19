#include "StreamReplace.hpp"

void	StreamReplace::_replace(std::string str1, std::string str2){        

        std::ifstream ifs(this->_infile.c_str());
        if (!ifs.is_open()) {
            std::cerr << "Error while opening the file: " << this->_infile << std::endl;
            return ;
        }
        std::ofstream ofs(this->_outfile.c_str());
        if (!ofs.is_open()) {
            std::cerr << "Error while creating the file: " << this->_outfile << std::endl;
            ifs.close();
            return ;
        }

        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string bufString = buffer.str();
        if (bufString.empty()){
            ofs << str2;
        }
        else if (str1.empty()){
            ofs << bufString;
        }
        else{
            size_t pos = bufString.find(str1, 0);
            while(pos != std::string::npos){
                bufString.erase(pos, str1.length());
                bufString.insert(pos, str2);
                pos = bufString.find(str1, pos + str2.length());
            }
            ofs << bufString;
        }

        ifs.close();
        ofs.close();
        return ;
}

StreamReplace::StreamReplace(std::string filename, std::string str1, std::string str2) : _infile(filename)
{
	this->_outfile = filename + ".replace";
    this->_replace(str1, str2);
}

StreamReplace::~StreamReplace()
{
}