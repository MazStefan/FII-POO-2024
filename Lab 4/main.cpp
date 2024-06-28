#include <iostream>

int main()
{
    Sort test1(1, 3, 2);
    test1.Print();
    cout << endl;
    cout << test1.GetElementsCount() << " " << test1.GetElementFromIndex(3) << endl;
    test1.BubbleSort(false);
    test1.Print();
    cout << endl;

    int v[] = { 5, 4, 9, 3, 8 };
    Sort test2(v, 5);
    cout << endl;
    test2.Print();
    cout << endl;
    cout << test2.GetElementsCount() << " " << test2.GetElementFromIndex(3) << endl;
    test2.InsertSort(false);
    test2.Print();
    cout << endl;

    Sort test3(1, 8, 6, 4, 20, 18);
    cout << endl;
    test3.Print();
    cout << endl;
    cout << test3.GetElementsCount() << " " << test3.GetElementFromIndex(3) << endl;
    test3.QuickSort(false);
    test3.Print();
    cout << endl;

    Sort test4("8,4,5,6,2");
    cout << endl;
    test4.Print();
    cout << endl;
    cout << test4.GetElementsCount() << " " << test4.GetElementFromIndex(3) << endl;

    return 0;
}