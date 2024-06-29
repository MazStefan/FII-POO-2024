#pragma once
#include "Contact.h"
class Acquiantance : public Contact {
	std::string phone;
public:
	Acquiantance(std::string nume, std::string nr) : Contact(nume), phone(nr) { };
	Acquiantance() : Contact(), phone("0") { };
	~Acquiantance();
	std::string Type() {
		std::string toReturn = "Acquiantance";
		return toReturn;
	}
};