#include <iostream>
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include "AddressBook.h"
using namespace std;

int main() {
	AddressBook a;
	a.contact_add(new Friend("Alex", 15, 06, 2004, "07374932", "str. geloziei"));
	a.contact_add(new Acquiantance("Stefan", "07234444"));
	a.contact_add(new Colleague("Petrica", "123456789", "hollywood productions", "LA"));
	a.search_by_name("Alex");
	cout << endl;
	a.friend_list();
	cout << endl;
	a.contact_delete("Alex");
	cout << endl;
	a.friend_list();
	return 0;
}