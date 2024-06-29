#pragma once
#include "Contact.h"
#include <vector>
class AddressBook {
	std::vector<Contact*> contacts;
public:
	std::vector<Contact*> search_by_name(std::string Nume);
	std::vector<Contact*> friend_list();
	void contact_delete(std::string Nume);
	void contact_add(Contact* toInsert);
};