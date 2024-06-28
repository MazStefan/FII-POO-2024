#pragma once
class Sort
{
    int lista[100], nrElem;

public:
    Sort(int n, int minim, int maxim);
    Sort(int lista[]);
    Sort(int v[100], int n);
    Sort(int n, ...);
    Sort(const char s[100]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};