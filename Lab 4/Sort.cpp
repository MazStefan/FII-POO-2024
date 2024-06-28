#include <iostream>
#include <cstdlib>
#include <stdarg.h>
#include <cstring>
#include "Sort.h"

using namespace std;

Sort::Sort(int n, int minim, int maxim)
{
    nrElem = n;

    int range = maxim - minim;
    for (int i = 0; i < nrElem; i++)
    {
        lista[i] = minim + (rand() % range);
    }
}

Sort::Sort(int lista[])
{
    nrElem = l;
}

Sort::Sort(int v[100], int n)
{
    nrElem = n;
    for (int i = 0; i < nrElem; i++)
    {
        lista[i] = v[i];
    }
}

Sort::Sort(int n, ...)
{
    va_list args;
    va_start(args, n);

    nrElem = n;
    int i = 0;

    while (n != 0)
    {
        lista[i] = va_arg(args, int);
        i++;
        n--;
    }
    va_end(args);
}

Sort::Sort(const char s[100])
{
    nrElem = 0;

    int lung = strlen(s);
    int i = 0;
    int nrCurent = 0;

    while (i < lung)
    {
        if (s[i] != ',')
        {
            nrCurent = nrCurent * 10 + (int)(s[i] - '0');
        }
        else
        {
            lista[nrElem] = nrCurent;
            nrElem++;
            nrCurent = 0;
        }
        i++;
    }
    lista[nrElem] = nrCurent;
    nrElem++;
}

void Sort::InsertSort(bool ascendent = false)
{
    int key;
    for (int i = 1; i < nrElem; i++)
    {
        key = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > key)
        {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = key;
    }
    ascendent = true;
}

int partitie(int lista[], int l, int h)
{
    int x = lista[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (lista[j] <= x) 
        {
            i++;
            int aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
    int aux = lista[i + 1];
    lista[i + 1] = lista[h];
    lista[h] = aux;
    return (i + 1);
}

void Sort::QuickSort(bool ascendent)
{
    int l = 0;
    int h = nrElem - 1;
    int stiva[h - l + 1];
    int top = -1;

    stiva[++top] = l;
    stiva[++top] = h;

    while (top >= 0) 
    {
        h = stiva[top--];
        l = stiva[top--];

        int p = partitie(lista, l, h);

        if (p - 1 > l)
        {
            stiva[++top] = l;
            stiva[++top] = p - 1;
        }

        if (p + 1 < h)
        {
            stiva[++top] = p + 1;
            stiva[++top] = h;
        }
    }
    ascendent = true;
}

void Sort::BubbleSort(bool ascendent = false)
{
    for (int i = 0; i < nrElem - 1; i++)
    {
        for (int j = 0; j < nrElem - i - 1; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                int aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
    ascendent = true;
}

void Sort::Print()
{
    for (int i = 0; i < nrElem; i++)
    {
        cout << lista[i] << " ";
    }
}

int Sort::GetElementsCount()
{
    return nrElem;
}

int Sort::GetElementFromIndex(int index)
{
	return lista[index];
}