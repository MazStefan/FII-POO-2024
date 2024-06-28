#include <iostream>
#include <cstring>
#include "Class.h"
#include "Class.cpp"
#include "Functions.h"
#include "Functions.cpp"

using namespace std;

int main()
{
    Student students[2];

    char name1[256], name2[256];
    cin.getline(name1, 256);
    cin.getline(name2, 256);

    int grade_math[2], grade_engl[2], grade_hist[2];
    cin >> grade_math[0] >> grade_math[1];
    cin >> grade_engl[0] >> grade_engl[1];
    cin >> grade_hist[0] >> grade_hist[1];

    students[0].Set_Name(name1);
    students[0].Set_Grade_Math(grade_math[0]);
    students[0].Set_Grade_Engl(grade_engl[0]);
    students[0].Set_Grade_Hist(grade_hist[0]);
    int average1 = students[0].Average_Grade();

    students[1].Set_Name(name1);
    students[1].Set_Grade_Math(grade_math[1]);
    students[1].Set_Grade_Engl(grade_engl[1]);
    students[1].Set_Grade_Hist(grade_hist[1]);
    int average2 = students[1].Average_Grade();

    int maxim[3];
    Bigger(maxim, students);
    Result(maxim);
}