#pragma once
#include <cstring>
#include "Weather.h"

class Car {
    private:
        char m_name[50];
        float m_fuelCapacity;
        float m_fuelConsumption;
        int m_speedWhenRain;
        int m_speedWhenSunny;
        int m_speedwhenSnow;
    public:
        Car() 
            : m_name { "Unknown Car" }, m_fuelCapacity{ 150 }, m_fuelConsumption{ 0.7 }, 
              m_speedWhenRain{ 80 }, m_speedwhenSnow{ 70 }, m_speedWhenSunny{ 100 } { }
        Car(const char * name, float fuelCapacity, float fuelConsumption, int speedwhenRain, int speedwhenSunny, int speedwhenSnow) 
            : m_fuelCapacity{ fuelCapacity }, m_fuelConsumption{ fuelConsumption }, 
              m_speedWhenRain{ speedwhenRain }, m_speedwhenSnow{ speedwhenSnow }, m_speedWhenSunny{ speedwhenSunny } { strcpy(m_name, name); }
        virtual float timeToRace(float length, Weather weather) const { return -9; };
        const char * getName() const { return m_name; };
        int getFuelCapacity() const { return m_fuelCapacity; };
        int getFuelConsumption() const { return m_fuelConsumption; };
        int getSpeedWhenRain() const { return m_speedWhenRain; };
        int getSpeedWhenSunny() const { return m_speedWhenSunny; };
        int getSpeedWhenSnow() const { return m_speedwhenSnow; };
};