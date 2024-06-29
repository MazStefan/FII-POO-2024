#include "AddressBook.h"
#include <iostream>
using namespace std;

std::vector<Contact*> AddressBook::search_by_name(std::string Nume) {
	vector<Contact*> toReturn;
	for (auto i : contacts)
		if (i->Name == Nume) {
			toReturn.push_back(i);
			return toReturn;
		}
}

std::vector<Contact*> AddressBook::friend_list() {
	vector<Contact*> toReturn;
	for (auto i : contacts)
		if (i->Type() == "Friend")
			toReturn.push_back(i);
	return toReturn;
}

void AddressBook::contact_delete(std::string Nume) {
	int it = 0;
	for (auto i : contacts) {
		if (i->Name == Nume)
			contacts.erase(contacts.begin() + it);
		it++;
	}

}

void AddressBook::contact_add(Contact* toInsert) {
	contacts.push_back(toInsert);
}