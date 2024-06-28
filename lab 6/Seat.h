#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class Seat : public Car {
    public:
        Seat() : Car { "Seat", 110, 0.9, 90, 140, 110 } { }
    virtual float timeToRace(float length, Weather weather) const;
};
