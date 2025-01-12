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

void mergeSort(std::vector<Train> &trains, int lowerB, int upperB)
{
    if (lowerB >= upperB)
    {
        return;
    }

    int middle = lowerB + (upperB - lowerB) / 2;
    mergeSort(trains, lowerB, middle);
    mergeSort(trains, middle + 1, upperB);
    mergeArray(trains, lowerB, middle, upperB);
}

void mergeArray(std::vector<Train> &trains, int lowerB, int middle, int upperB)
{
    int sizeLeft = middle - lowerB + 1;
    int sizeRight = upperB - middle;

    // Create temporary vectors for left and right halves
    std::vector<Train> leftArray(sizeLeft);
    std::vector<Train> rightArray(sizeRight);

    // Fill leftArray and rightArray
    for (int i = 0; i < sizeLeft; i++)
    {
        leftArray[i] = trains[lowerB + i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
        rightArray[i] = trains[middle + 1 + i];
    }

    int i = 0, j = 0, k = lowerB;

    // Merge the arrays based on the `delay` property
    while (i < sizeLeft && j < sizeRight)
    {
        if (leftArray[i].delay <= rightArray[j].delay)
        {
            trains[k] = leftArray[i];
            i++;
        }
        else
        {
            trains[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from leftArray
    while (i < sizeLeft)
    {
        trains[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements from rightArray
    while (j < sizeRight)
    {
        trains[k] = rightArray[j];
        j++;
        k++;
    }
}

void TrainList::sortByDelay()
{
    if (!trains.empty())
    {
        mergeSort(trains, 0, trains.size() - 1);
    }
}
