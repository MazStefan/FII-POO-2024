#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class Volvo : public Car {
    public:
        Volvo() : Car { "Volvo", 200, 1.5, 110, 110, 110 } { }
    virtual float timeToRace(float length, Weather weather) const;
};
