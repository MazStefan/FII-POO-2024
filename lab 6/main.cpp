#include <iostream>
#include "Circuit.h"
#include "BMW.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"


int main() {
   Circuit c;
    c.setLength(100);
    c.setWeather(Weather::Snow);
    c.addCar(new Volvo());
    c.addCar(new BMW());
    c.addCar(new Seat());
    c.addCar(new Fiat());
    c.addCar(new RangeRover());
    c.race();
    c.showFinalRanks();
    c.showWhoDidNotFinish();


   return 0;
}