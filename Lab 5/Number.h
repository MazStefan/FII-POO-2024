#pragma once

class Number
{
public:
	char* valoare;
	int baza;
	Number(const char* value, int base);
	~Number();
	Number(const Number& n);
	Number(Number& n);
	Number(const char* s);
	Number(int x);
	Number() { valoare = nullptr; baza = 0; }
	friend Number operator + (Number& n1, Number& n2); 
	friend Number operator - (Number& n1, Number& n2);
	char* operator += (Number& n);
	char* operator = (Number& n);
	char operator [](int i);
	bool operator < (Number& n);
	bool operator > (Number& n);
	bool operator >= (Number& n);
	bool operator <= (Number& n);
	bool operator == (Number& n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
};