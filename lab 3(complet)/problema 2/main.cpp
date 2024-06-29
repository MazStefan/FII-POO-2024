#include <iostream>
#include <chrono>
#include <thread>
#include "Canvas.h"

int main()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    
    Canvas Canvas;
    Canvas.Clear();

    Canvas.DrawCircle(15, 15, 15, '*');
    Canvas.FillCircle(15, 15, 15, '-');
    Canvas.Print();
    sleep_for(seconds(5));
    Canvas.Clear();

    Canvas.DrawRect(15, 15, 35, 35, '*');
    Canvas.FillRect(15, 16, 35, 35, '-');
    Canvas.Print();
    sleep_for(seconds(5));
    Canvas.Clear();

    Canvas.SetPoint(15, 35, '*');
    Canvas.SetPoint(40, 50, '*');
    Canvas.DrawLine(15, 35, 40, 50, '-');
    sleep_for(seconds(5));
}