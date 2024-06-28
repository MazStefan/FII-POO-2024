#pragma once
#include <iostream>
#include "Car.h"
#include "Weather.h"

class Fiat : public Car {
    public:
        Fiat() : Car { "Fiat", 100, 0.7, 80, 100, 60 } { }
    virtual float timeToRace(float length, Weather weather) const;
};
