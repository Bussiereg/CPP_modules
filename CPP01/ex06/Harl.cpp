#include "Harl.hpp"

void	Harl::debug(void){
	std::cout << "<DEBUG>" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
}

void	Harl::info(void){
	std::cout << "<INFO>" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void){
	std::cout << "<WARNING>" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void){
	std::cout << "<ERROR>" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::_displayComplain (int lev, std::string comp){
    for (int i = lev; i < 4; i++){
        if(comp == this->_comp[i])
        {
            (this->*_ptr[i])();
            break;
        }
    }
}

void Harl::complain( std::string level )
{
    switch (this->_limit)
    {
    case 0:
        this->_displayComplain(0, level);
        break;
    case 1:
        this->_displayComplain(1, level);
        break;
    case 2:
        this->_displayComplain(2, level);
        break;
    case 3:
        this->_displayComplain(3, level);
        break;
    default:
        break;
    }
}

Harl::Harl(std::string limit){
	this->_ptr[0] = &Harl::debug;
	this->_ptr[1] = &Harl::info;
	this->_ptr[2] = &Harl::warning;
	this->_ptr[3] = &Harl::error;
    this->_comp[0] = "DEBUG";
	this->_comp[1] = "INFO";
	this->_comp[2] = "WARNING";
	this->_comp[3] = "ERROR";
    for (int i = 0; i < 4; i++){
        if (this->_comp[i] == limit){
            this->_limit = i;
            break;
        }
        else{
            this->_limit = 5;
        }
    }
    if (this->_limit == 5)
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::~Harl()
{
}