#include "BMW.h"

float BMW::timeToRace(float length, Weather weather) const {
    float speed;
    switch (weather) {
        case Weather::Rain:
            speed = getSpeedWhenRain();
            break;
        case Weather::Snow:
            speed = getSpeedWhenSnow();
            break;
        case Weather::Sunny:
            speed = getSpeedWhenSunny();
            break;
    }
    if (getFuelCapacity() - length * getFuelConsumption() <= 0)
        return -1;
    return length*1.0 / speed;
}