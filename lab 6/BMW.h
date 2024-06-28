#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class BMW : public Car {
    public:
        BMW() : Car { "BWM", 200, 1, 100, 120, 90 } { }
    virtual float timeToRace(float length, Weather weather) const;
};