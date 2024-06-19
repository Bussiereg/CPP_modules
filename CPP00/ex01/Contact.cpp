#include "PhoneBook.hpp"

/* void Contact::setfield1(std::string field1){
	this->_FirstName = field1;
}

void Contact::setfield2(std::string field2){
	this->_LastName = field2;
}

void Contact::setfield3(std::string field3){
	this->_Nickname = field3;
}

void Contact::setfield4(std::string field4){
	this->_PhoneNumber = field4;
}

void Contact::setfield5(std::string field5){
	this->_DarkestSecret = field5;
} */

std::string Contact::get(const std::string& field){
	if (field == "_FirstName") {
		return this->_FirstName;
	} 
	else if (field == "_LastName") {
		return this->_LastName;
	} 
	else if (field == "_Nickname") {
		return this->_Nickname;
	} 
	else if (field == "_PhoneNumber") {
		return this->_PhoneNumber;
	} 
	else if (field == "_DarkestSecret") {
		return this->_DarkestSecret;
	}
	else {
		return "";
	}
}

void Contact::setfield(const std::string& field, std::string setval){
	if (field == "_FirstName") {
		this->_FirstName = setval;
	} 
	else if (field == "_LastName") {
		this->_LastName = setval;
	} 
	else if (field == "_Nickname") {
		this->_Nickname = setval;
	} 
	else if (field == "_PhoneNumber") {
		this->_PhoneNumber = setval;
	} 
	else if (field == "_DarkestSecret") {
		this->_DarkestSecret = setval;
	}

}

Contact::Contact()
{
}

Contact::~Contact()
{
}