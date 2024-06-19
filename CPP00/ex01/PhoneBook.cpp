#include "PhoneBook.hpp"

bool CheckIndex(std::string str) {
    if (str.empty() || str.length() != 1) {
        return false;
    }
    return (str[0] >= '1' && str[0] <= '8');
}

void	SearchReturn(std::string str)
{
	if (str.length() >= 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::setfill(' ') << str;
	std::cout << "|";
}

void	DisplayContacts(Contact *contact){
	std::cout <<"---------------------------------------------" << std::endl;
	std::cout <<"|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout <<"---------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++){
		std::cout << "|" << std::setw(10) << std::setfill(' ') << i + 1 << "|";
		SearchReturn(contact[i].get("_FirstName"));
		SearchReturn(contact[i].get("_LastName"));
		SearchReturn(contact[i].get("_Nickname"));
		std::cout <<std::endl;
		std::cout <<"---------------------------------------------" << std::endl;
	}
	return ;
}

PhoneBook::PhoneBook(void)
{
	std::string buf;
	std::string index;
	int it = -1;
	int j = 0;

	std::cout << "--------Welcome to your Awesome PhoneBook!--------" 
		<< std::endl << std::endl;
	std::cout << "-->Enter one of the following command: ADD, SEARCH or EXIT" 
		<< std::endl;
	std::getline(std::cin, buf);
	while((buf.compare("EXIT"))){
		if ((!buf.compare("ADD")))
		{
			if (++it == 8)
				it = 0;
			if (this->_add(&this->contact[it])){
				std::cout << std::endl << "Your contact was successfully added!" 
					<< std::endl << std::endl;			
			}
			else{
				std::cout << std::endl << "!!!FAILED to add contact, no empty field please" 
					<< std::endl << std::endl;
				it--;
			}
		}
		else if ((!buf.compare("SEARCH")))
		{
			int flag = 0;
			while (flag == 0){
				if ( j == 0)
					DisplayContacts(this->contact), j++;
				std::cout << "-->Which contact do you want to diplay ? Enter an index: " << std::endl;
				std::getline(std::cin, index);
				if (CheckIndex(index))
					this->_search(&this->contact[index[0] - 48 - 1]), flag++, j--;
				else
					std::cout << "!!!The index has to be a digit between 1 and 8." << std::endl << std::endl;
			}
		}
		std::cout << "-->Enter one of the following command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, buf);
	}
	return;
}

PhoneBook::~PhoneBook()
{
	std::cout << "------Awesome Phonebook closed! See you soon------" << std::endl;
	return;
}

int PhoneBook::_add(Contact *contact)
{
	std::string field1;
	std::string field2;
	std::string field3;
	std::string field4;
	std::string field5;

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, field1);
	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, field2);
	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, field3);
	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, field4);
	std::cout << "darkest secret: " << std::endl;
	std::getline(std::cin, field5);
	if (field1.empty() || field2.empty() || field3.empty() || field4.empty() || field5.empty())
		return 0;
	contact->setfield("_FirstName", field1);
	contact->setfield("_LastName", field2);
	contact->setfield("_Nickname", field3);
	contact->setfield("_PhoneNumber", field4);
	contact->setfield("_DarkestSecret", field5);
	return 1;
}

void PhoneBook::_search(Contact *contact)
{
	std::cout << "First name: " << contact->get("_FirstName") << std::endl;
	std::cout << "Last name: " << contact->get("_LastName") << std::endl;
	std::cout << "Nickname: " << contact->get("_Nickname") << std::endl;
	std::cout << "Phone number: " << contact->get("_PhoneNumber") << std::endl;
	std::cout << "Darkest Secret: " << contact->get("_DarkestSecret") << std::endl;
	return ;
}

int main(void)
{
	PhoneBook instance;

	return 0;
}
