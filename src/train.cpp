#include "train.hpp"

Train::Train(int idTravel, int engineNum, int carsNum, int seats, std::vector<std::string> servedStations, bool running, int delayMinutes)
    : travelId(idTravel), engineNumber(engineNum), carsCount(carsNum), capacity(seats), stations(servedStations), isRunning(running), delay(delayMinutes) {}

void Train::display() const
{
    std::cout << "Travel ID: " << travelId
              << ", Engine: " << engineNumber
              << ", Cars: " << carsCount
              << ", Capacity: " << capacity
              << ", Running: " << (isRunning ? "Yes" : "No")
              << ", Delay: " << delay << " minutes" << std::endl;
    std::cout << "Stations: ";
    for (const std::string &station : stations)
    {
        std::cout << station << " ";
    }
    std::cout << std::endl;
}

bool Train::operator<(const Train &other) const
{
    return travelId < other.travelId;
}
