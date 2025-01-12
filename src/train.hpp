#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <vector>
#include <string>
#include <iostream>

class Train
{
public:
    int travelId;
    int engineNumber;
    int carsCount;
    int capacity;
    std::vector<std::string> stations;
    bool isRunning;
    int delay;

    Train(int idTravel, int engineNum, int carsNum, int seats, std::vector<std::string> servedStations, bool running, int delayMinutes);
    
    void display() const;

    // Comparison operator for sorting by travelId
    bool operator<(const Train &other) const;
};

#endif
