#pragma once
#include "Contact.h"
class Colleague : public Contact {
	std::string phone;
	std::string company;
	std::string address;
public:
	Colleague(std::string nume, std::string nr, std::string comp, std::string addr) : Contact(nume), phone(nr), company(comp), address(addr) { };
	Colleague() : Contact(), phone("0"), company("N/A"), address("N/A") { };
	~Colleague();
	std::string Type() {
		std::string toReturn = "Colleague";
		return toReturn;
	}
};