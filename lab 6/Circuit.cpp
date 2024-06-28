#include <iostream>
#include "Circuit.h"

void insertionSort(float arr[10][2], int n, bool descending)
{
    for (int j = 2; j < n; j++)
    {
        int key = arr[j][0];
        int i = j - 1;
        while (i > 0 && (descending? arr[i][0] < key : arr[i][0] > key)) 
        {
            arr[i + 1][0] = arr[i][0];
            i--;
        }
        arr[i + 1][0] = key;
    }
}

void Circuit::addCar(Car* car) {
    m_cars[m_nrOfCars++] = car;
};
void Circuit::race() {
    float standings[10][2];
    int finishers = 0;
    strcpy(m_finalRanks, "");
    strcpy(m_whoDidNotFinish, "");
    
    for (int i = 0; i < m_nrOfCars; i++) {
        int time = m_cars[i]->timeToRace(m_length, m_weather);
        if (time > 0)
        {
            standings[finishers][0] = time;
            standings[finishers][1] = i;
            ++finishers;
        }
        else {
            strcat(m_whoDidNotFinish, m_cars[i]->getName());
            strcat(m_whoDidNotFinish, " ");
        }
    }
    insertionSort(standings, finishers, 0);
    for (int i = 0; i < finishers; i++) {
        strcat(m_finalRanks, m_cars[(int)standings[i][1]]->getName());
        strcat(m_finalRanks, " ");
    }
    std::cout << '\n';
};
void Circuit::showFinalRanks() {
    std::cout << "Final Ranks: " << m_finalRanks << '\n';
}
void  Circuit::showWhoDidNotFinish() {
    std::cout << "Losers: " << m_whoDidNotFinish << '\n';
}