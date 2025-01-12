#ifndef TRAINLIST_HPP
#define TRAINLIST_HPP

#include <vector>
#include "train.hpp"

class TrainList
{
private:
    std::vector<Train> trains;

    // Binary search helper function
    int binarySearch(int travelId) const;

public:
    void addTrain(const Train &train);
    void displayTrains() const;
    Train *retrieveTrain(int travelId);
    bool updateTrain(int travelId, int newDelay, bool newStatus);
    bool removeTrain(int travelId);
    void sortByDelay();
};

#endif
