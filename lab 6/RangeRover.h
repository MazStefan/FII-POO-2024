#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class RangeRover : public Car {
    public:
        RangeRover() : Car { "RangeRover", 300, 3.2, 100, 120, 90 } { }
    virtual float timeToRace(float length, Weather weather) const;
};