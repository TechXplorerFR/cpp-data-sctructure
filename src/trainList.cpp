#include "trainList.hpp"
#include <algorithm>

int TrainList::binarySearch(int travelId) const
{
    int low = 0, high = trains.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (trains[mid].travelId == travelId)
        {
            return mid; // Found
        }
        else if (trains[mid].travelId < travelId)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

void TrainList::addTrain(const Train &train)
{
    auto it = std::lower_bound(trains.begin(), trains.end(), train);
    trains.insert(it, train);
}

void TrainList::displayTrains() const
{
    if (trains.empty())
    {
        std::cout << "No trains in the list." << std::endl;
        return;
    }

    for (const auto &train : trains)
    {
        train.display();
        std::cout << "--------------------------" << std::endl;
    }
}

Train *TrainList::retrieveTrain(int travelId)
{
    int index = binarySearch(travelId);
    if (index != -1)
    {
        return &trains[index];
    }
    return nullptr;
}

bool TrainList::updateTrain(int travelId, int newDelay, bool newStatus)
{
    Train *train = retrieveTrain(travelId);
    if (train != nullptr)
    {
        train->delay = newDelay;
        train->isRunning = newStatus;
        return true;
    }
    return false;
}

bool TrainList::removeTrain(int travelId)
{
    int index = binarySearch(travelId);
    if (index != -1)
    {
        trains.erase(trains.begin() + index);
        return true;
    }
    return false;
}

void TrainList::sortByDelay()
{
    std::sort(trains.begin(), trains.end(),
              [](const Train &a, const Train &b)
              { return a.delay < b.delay; });
}
