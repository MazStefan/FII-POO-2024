#include <iostream>
#include <cstring>

#include "Functions.h"

using namespace std;

Student students[2];
int maxim[3]; // vector de aparitii
// max[0] => cate functii au returnat -1
// max[1] => cate functii au returnat 0
// max[2] => cate functii au returnat 1

void Bigger(int maxim[3], Student students[2])
{
	maxim[Compare_Name(students) + 2]++;
	maxim[Compare_Math(students) + 2]++;
	maxim[Compare_Engl(students) + 2]++;
	maxim[Compare_Hist(students) + 2]++;
	maxim[Compare_Avg(students) + 2]++;
}

int Result(int maxim[3])
{
	if (maxim[0] > maxim[1] && maxim[0] > maxim[2])
	{
		return 2; //al doilea student e mai mare
	}
	if (maxim[2] > maxim[1] && maxim[2] > maxim[0])
	{
		return 1; //primul student este mai mare
	}
	return 0; //cazul in care sunt egali
}