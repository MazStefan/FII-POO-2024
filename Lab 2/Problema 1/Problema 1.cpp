#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    NumberList vector;
    int x[10], length;
    cin >> length;
    for (int i=0;i<length;i++)
    {
        cin >> x[i];
    }
    vector.Init();
    for (int i=0;i<length;i++)
    {
        vector.Add(x[i]);
    }
    vector.Sort();
    vector.Print();
}
