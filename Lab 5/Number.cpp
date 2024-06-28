#include <cstring>
#include <iostream>
#include "Number.h"

using namespace std;

Number::Number(const char* value, int base)
{
    baza = base;
    valoare = new char(strlen(value) + 1);
    memcpy(valoare, value, strlen(value) + 1);
}
Number::~Number()
{
    delete valoare;
    valoare = nullptr;
}

Number::Number(const Number& n)
{
    baza = n.baza;
    valoare = new char(strlen(n.valoare) + 1);
    memcpy(valoare, n.valoare, strlen(n.valoare) + 1);
}
Number::Number(Number& n)
{
    baza = n.baza;
    valoare = nullptr;
    valoare = n.valoare;
}
Number::Number(const char* s)
{
    baza = 0;
    int i = 0;
    while (s[i])
    {
        if ((int)(s[i] - '0') > baza)
        {
            baza = (int)(s[i] - '0');
        }
    }
    cout << valoare;
}
Number::Number(int x)
{
    baza = 10;
    char n[100];
    if (x == 0)
    {
        n[0] = '0';
        n[1] = '\0';
    }
    else
    {
        n[0] = '\0';
        int i = 0;
        while (x)
        {
            n[i] = (char)((x % 10) + '0');
            x /= 10;
            i++;
        }
        n[i] = '\0';
        int len = strlen(n);
        for (int i = 0; len / 2; i++)
        {
            char aux = n[i];
            n[i] = n[i + len - 1];
            n[i + len - 1] = aux;
        }
    }
    valoare = n;
}
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
char reVal(int num)
{
    if (num <= 0 && num >= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
void reverse_char(char* val1)
{
    int len = strlen(val1);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = val1[i];
        val1[i] = val1[len - i - 1];
        val1[len - i - 1] = temp;
    }
}
int inBaza10(char* valoare, int baza)
{
    char val1[100];
    val1[0] = '\0';
    strcat_s(val1, valoare);
    int len = strlen(val1);
    int power = 1;
    int num = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        num += val(val1[i]) * power;
        power = power * baza;
    }
    return num;
}
char* dinBaza10(int num, int baza)
{
    int p = 1, rest, index = 0;
    char aux[100];
    aux[0] = '\0';
    while (num != 0)
    {
        rest = num % baza;
        num /= baza;
        if (rest <= 9)
        {
            aux[index] = (char)(rest + '0');
        }
        else
        {
            aux[index] = (char)(rest % 10 + 'A');
        }
        index++;
        p *= 10;
    }
    aux[index] = '\0';
    reverse_char(aux);
    return aux;
}
Number operator + (Number& n1, Number& n2)
{
    Number suma;
    if (n1.baza < n2.baza)
    {
        suma.baza = n2.baza;
    }
    else
    {
        suma.baza = n1.baza;
    }

    int num1 = inBaza10(n1.valoare, n1.baza);
    int num2 = inBaza10(n2.valoare, n2.baza);
    int sum10 = num1 + num2;

    suma.valoare = dinBaza10(sum10, n1.baza);
    return suma;
}
char* operator + (Number& n1, Number& n2)
{
    if (n1.baza < n2.baza)
    {
        n1.baza = n2.baza;
    }

    int num1 = inBaza10(n1.valoare, n1.baza);
    int num2 = inBaza10(n2.valoare, n2.baza);
    int sum10 = num1 + num2;

    n1.valoare = dinBaza10(sum10, n1.baza);
    return n1.valoare;
}
Number operator - (Number& n1, Number& n2)
{
    Number dif;
    if (n1.baza < n2.baza)
    {
        dif.baza = n2.baza;
    }
    else
    {
        dif.baza = n1.baza;
    }

    int num1 = inBaza10(n1.valoare, n1.baza);
    int num2 = inBaza10(n2.valoare, n2.baza);
    int dif10 = num1 - num2;

    dif.valoare = dinBaza10(dif10, n1.baza);
    return dif;
}
char* operator - (Number& n1, Number& n2)
{
    if (n1.baza < n2.baza)
    {
        n1.baza = n2.baza;
    }

    int num1 = inBaza10(n1.valoare, n1.baza);
    int num2 = inBaza10(n2.valoare, n2.baza);
    int dif10 = num1 - num2;

    n1.valoare = dinBaza10(dif10, n1.baza);
    return n1.valoare;
}
char* Number::operator += (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);
    num1 += num2;

    if (baza < n.baza)
    {
        baza = n.baza;
    }
    valoare = dinBaza10(num1, baza);

    return valoare;
}
char* Number::operator = (Number& n)
{
    baza = n.baza;
    valoare = n.valoare;
    return valoare;
}
char Number::operator [] (int i)
{
    return valoare[i];
}
bool Number::operator < (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);

    return num1 < num2;
}
bool Number::operator > (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);

    return num1 > num2;
}
bool Number::operator >= (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);

    return num1 >= num2;
}
bool Number::operator <= (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);

    return num1 <= num2;
}
bool Number::operator == (Number& n)
{
    int num1 = inBaza10(valoare, baza);
    int num2 = inBaza10(n.valoare, n.baza);

    return num1 == num2;
}
void Number::SwitchBase(int newBase)
{
    char val1[100];
    val1[0] = '\0';
    strcat_s(val1, valoare);
    int len = strlen(val1);
    int power = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        num += val(val1[i]) * power;
        power = power * baza;
    }
    int p = 1, rest, index = 0;
    char aux[100];
    aux[0] = '\0';
    while (num != 0)
    {
        rest = num % newBase;
        num /= newBase;
        if (rest <= 9)
        {
            aux[index] = (char)(rest + '0');
        }
        else
        {
            aux[index] = (char)(rest % 10 + 'A');
        }
        index++;
        p = 10;
    }
    aux[index] = '\0';
    reverse_char(aux);
    valoare[0] = '\0';
    valoare = aux;
    baza = newBase; 
    delete[] valoare;
    valoare = new char[strlen(aux) + 1];
    strcpy_s(valoare, strlen(aux), aux);
    cout << valoare;
    baza = newBase;
}
void Number::Print()
{
    cout << valoare << endl;
}
int Number::GetDigitsCount()
{
    return strlen(valoare);
}
int Number::GetBase()
{
    return baza;
}