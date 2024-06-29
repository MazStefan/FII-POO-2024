#pragma once
#include <string>
class Contact {
public:
	std::string Name;
	virtual std::string Type() = 0;
	Contact(std::string nume) : Name(nume) {};
	Contact() : Name("N/A") { };
};