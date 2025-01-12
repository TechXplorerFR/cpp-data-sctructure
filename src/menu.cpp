#include "menu.hpp"
#include "train.hpp"
#include "trainList.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Train generateRandomTrain(int id)
{
    int engineNum = rand() % 1000 + 1;
    int carsNum = rand() % 20 + 1;
    int capacity = carsNum * (rand() % 100 + 50);
    std::vector<std::string> stations = {"Station A", "Station B", "Station C", "Station D"};
    bool running = rand() % 2 == 0;
    int delayMinutes = rand() % 120;

    return Train(id, engineNum, carsNum, capacity, stations, running, delayMinutes);
}

void menu()
{
    TrainList trainList;
    srand(time(0));
    int choice;

    do
    {
        std::cout << "\nTrain Management System\n";
        std::cout << "1. Add Train\n";
        std::cout << "2. Display All Trains\n";
        std::cout << "3. Retrieve Train by ID\n";
        std::cout << "4. Update Train Information\n";
        std::cout << "5. Remove Train\n";
        std::cout << "6. Sort Trains by Delay\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id, engineNum, carsNum, seats, delay;
            bool running;
            std::cout << "Enter Travel ID: ";
            std::cin >> id;
            std::cout << "Enter Engine Number: ";
            std::cin >> engineNum;
            std::cout << "Enter Number of Cars: ";
            std::cin >> carsNum;
            std::cout << "Enter Total Capacity: ";
            std::cin >> seats;
            std::cout << "Is the train running? (1 for Yes, 0 for No): ";
            std::cin >> running;
            std::cout << "Enter Delay in Minutes: ";
            std::cin >> delay;

            std::vector<std::string> stations = {"Station A", "Station B", "Station C", "Station D"};
            Train newTrain(id, engineNum, carsNum, seats, stations, running, delay);
            trainList.addTrain(newTrain);
            std::cout << "Train added successfully.\n";
            break;
        }
        case 2:
            trainList.displayTrains();
            break;
        case 3:
        {
            int id;
            std::cout << "Enter Travel ID to retrieve: ";
            std::cin >> id;
            Train *train = trainList.retrieveTrain(id);
            if (train != nullptr)
            {
                train->display();
            }
            else
            {
                std::cout << "Train not found.\n";
            }
            break;
        }
        case 4:
        {
            int id, delay;
            bool running;
            std::cout << "Enter Travel ID to update: ";
            std::cin >> id;
            std::cout << "Enter new delay in minutes: ";
            std::cin >> delay;
            std::cout << "Is the train running? (1 for Yes, 0 for No): ";
            std::cin >> running;

            if (trainList.updateTrain(id, delay, running))
            {
                std::cout << "Train updated successfully.\n";
            }
            else
            {
                std::cout << "Train not found.\n";
            }
            break;
        }
        case 5:
        {
            int id;
            std::cout << "Enter Travel ID to remove: ";
            std::cin >> id;

            if (trainList.removeTrain(id))
            {
                std::cout << "Train removed successfully.\n";
            }
            else
            {
                std::cout << "Train not found.\n";
            }
            break;
        }
        case 6:
            trainList.sortByDelay();
            std::cout << "Trains sorted by delay.\n";
            break;
        case 7:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}
