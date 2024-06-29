#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
    Math calc;
    int xi, yi, zi;
    double xd, yd, zd;
    const char a = 'a', b = 'b';
    int count, v[100];

    cin >> xi >> yi >> zi >> xd >> yd >> zd;

    cout << calc.Add(xi, yi) << calc.Add(xi, yi, zi) << calc.Add(xd, yd) << calc.Add(xd, yd, zd) << endl;
    cout << calc.Mul(xi, yi) << calc.Mul(xi, yi, zi) << calc.Mul(xd, yd) << calc.Mul(xd, yd, zd) << endl;
    cout << calc.Add(4, 1, 2, 3, 4) << endl;
    cout << calc.Add(a, b);
}