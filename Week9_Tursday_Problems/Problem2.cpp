#include <iostream>
using namespace std;

// Function to read the friend's house coordinate from the user
int readFriendHouseCoordinate() {
    int coordinate = 0;
    cout << "Enter your friend's house coordinate (positive integer): ";
    cin >> coordinate; // input coordinate
    return coordinate;
}

// Function to calculate the minimum steps required
// Each step moves 5 units forward until we reach or pass the coordinate
int minimumStepsGetFriendHouse(int coordinate) {
    int steps = 0;

    // Keep moving forward in steps of 5 until the coordinate is reached or passed
    while (coordinate > 0) {
        coordinate -= 5; // move 5 units
        steps++;         // count this step
    }

    return steps; // return the total number of steps taken
}

// Function to print the result
void print(int steps) {
    cout << "Minimum number of steps required to reach your friend's house: " 
         << steps << endl;
}

int main() {
    // Step 1: Read the coordinate of the friend's house
    int coordinate = readFriendHouseCoordinate();

    // Step 2: Compute how many steps of length 5 are needed
    int steps = minimumStepsGetFriendHouse(coordinate);

    // Step 3: Print the result
    print(steps);

    return 0; // end of program
}
