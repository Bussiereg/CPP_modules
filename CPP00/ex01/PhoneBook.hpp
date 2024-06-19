#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int _add(Contact *contact);
		void _search(Contact *contact);
	public:
		Contact contact[8];
		PhoneBook();
		~PhoneBook();

};

#endif