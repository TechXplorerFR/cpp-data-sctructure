
# Train Management System

The Train Management System is a simple program written in C++ that allows users to manage a list of trains. The program provides functionalities to:

- Add new trains to the list.
- Display all trains currently in the list.
- Retrieve a specific train by its Travel ID.
- Update the status and delay information of a train.
- Remove a train from the list.
- Sort trains by delay time.

## Features
1. Add Train  
2. Display All Trains
3. Retrieve Train by ID
4. Update Train Information
5. Remove Train  
6. Sort Trains by Delay  

## How to Build and Run

### Prerequisites
1. Ensure you have a C++ compiler installed, such as `g++`.  
2. Use a system with C++11 or higher support.

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/TechXplorerFR/train-management-system.git
   cd train-management-system
   ```

2. Compile the program:
   ```bash
   g++ -o main main.cpp train.cpp trainList.cpp menu.cpp -std=c++11
   ```

3. Run the program:
   ```bash
   ./main
   ```

## Known Limitations
1. Unfinished Tasks:
   - There is no functionality to persist train data between runs. Once the program terminates, all data is lost.
   - Random station data is generated and currently fixed for all trains. Future work may include dynamic station input.
   
2. Bugs:
   - No input validation for incorrect data (e.g., entering non-numeric values for numeric inputs).
   - Binary search logic assumes that all trains have unique travel IDs, and no check is performed during the addition of duplicate IDs.

3. Performance:
   - Since the train list is re-sorted during every insertion, performance may degrade with large datasets.

## Future Enhancements
- Add a database or file system for saving train data persistently.
- Provide detailed error handling and input validation for all user inputs.
- Improve the sorting logic to optimize performance for large train datasets.
- Allow dynamic station input for each train during the addition process.

## License
This project is licensed under the [MIT License](LICENSE).
