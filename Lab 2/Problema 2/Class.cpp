#include <iostream>
#include <cstring>

#include "Class.h"

using namespace std;

void Student::Set_Name(char set_name[256])
{
	strcpy_s(name, set_name);
}
char* Student::Get_Name()
{
	return name;
}

void Student::Set_Grade_Math(float grade)
{
	math = grade;
}
float Student::Get_Grade_Math()
{
	return math;
}

void Student::Set_Grade_Engl(float grade)
{
	engl = grade;
}
float Student::Get_Grade_Engl()
{
	return engl;
}

void Student::Set_Grade_Hist(float grade)
{
	hist = grade;
}
float Student::Get_Grade_Hist()
{
	return hist;
}

float Student::Average_Grade()
{
	return (math + engl + hist) / 3;
}