#pragma once
#include "Contact.h"
class Friend : public Contact {
	int day;
	int month;
	int year;
	std::string phone;
	std::string address;
public:
	Friend(std::string nume, int d, int m, int y, std::string nr, std::string addr) : Contact(nume), day(d), month(m), year(y), phone(nr), address(addr) { };
	Friend() : Contact(), day(0), month(0), year(0), phone("0"), address("N/A") { };
	~Friend();
	std::string Type() {
		std::string toReturn = "Friend";
		return toReturn;
	}
};