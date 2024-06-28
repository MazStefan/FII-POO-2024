#pragma once
#include "Class.h"

int Compare_Name(Student students[2])
{
	if (strcmp(students[0].Get_Name(), students[1].Get_Name()) < 0)
	{
		return -1;
	}
	if (strcmp(students[0].Get_Name(), students[1].Get_Name()) == 0)
	{
		return 0;
	}
	if (strcmp(students[0].Get_Name(), students[1].Get_Name()) > 0)
	{
		return 1;
	}
}

int Compare_Math(Student students[2])
{
	if (students[0].Get_Grade_Math() < students[1].Get_Grade_Math())
	{
		return -1;
	}
	if (students[0].Get_Grade_Math() == students[1].Get_Grade_Math())
	{
		return 0;
	}
	if (students[0].Get_Grade_Math() > students[1].Get_Grade_Math())
	{
		return 1;
	}
}

int Compare_Engl(Student students[2])
{
	if (students[0].Get_Grade_Engl() < students[1].Get_Grade_Engl())
	{
		return -1;
	}
	if (students[0].Get_Grade_Engl() == students[1].Get_Grade_Engl())
	{
		return 0;
	}
	if (students[0].Get_Grade_Engl() > students[1].Get_Grade_Engl())
	{
		return 1;
	}
}

int Compare_Hist(Student students[2])
{
	if (students[0].Get_Grade_Hist() < students[1].Get_Grade_Hist())
	{
		return -1;
	}
	if (students[0].Get_Grade_Hist() == students[1].Get_Grade_Hist())
	{
		return 0;
	}
	if (students[0].Get_Grade_Hist() > students[1].Get_Grade_Hist())
	{
		return 1;
	}
}

int Compare_Avg(Student students[2])
{
	if (students[0].Average_Grade() < students[1].Average_Grade())
	{
		return -1;
	}
	if (students[0].Average_Grade() == students[1].Average_Grade())
	{
		return 0;
	}
	if (students[0].Average_Grade() > students[1].Average_Grade())
	{
		return 1;
	}
}

