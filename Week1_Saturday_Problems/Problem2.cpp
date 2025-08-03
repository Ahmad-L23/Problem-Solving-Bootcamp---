#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Reads and returns the total number of magnets to be processed from user input
int readNumberOfMagnets()
{
    int numberOfMagnets;
    cout << "Enter the number of magnets: ";
    cin >> numberOfMagnets;
    return numberOfMagnets;
}

// Checks if the given polarity string is valid (must be either "01" or "10")
bool isValidPolarity(string polarity)
{
    return polarity == "01" || polarity == "10";
}

// Reads the polarity of each magnet from the user, validating input as "01" or "10"
vector<string> readMagnets(int numberOfMagnets)
{
    vector<string> magnets(numberOfMagnets);  // Create a vector to hold magnet polarities
    cout << "Enter the polarity of each magnet (must be '01' or '10'):" << endl;

    for (int i = 0; i < numberOfMagnets; ++i)
    {
        string input;
        do
        {
            cout << "Magnet " << (i + 1) << ": ";
            cin >> input;
        } while (!isValidPolarity(input));  // Repeat until a valid polarity is entered

        magnets[i] = input;
    }

    return magnets;  // Return the list of valid magnet polarities
}

// Calculates and returns the number of groups formed based on magnet attraction rules
int NumberOfAttractMagnets(const vector<string>& magnets)
{
    int groups = 1;  // At least one group always exists
    for (int i = 1; i < magnets.size(); ++i)
    {
        // A new group is formed when the current polarity differs from the previous one
        if (magnets[i] != magnets[i - 1])
            groups++;
    }
    return groups;
}

// Displays the total number of groups formed by the magnets
void printNumberOfAttractMagnets(int groups)
{
    cout << "\nThe number of groups formed by attractive magnets is: " << groups << endl;
}

// Main function - entry point of the program
int main()
{
    int numberOfMagnets = readNumberOfMagnets();             // Step 1: Get number of magnets
    vector<string> magnets = readMagnets(numberOfMagnets);   // Step 2: Read magnet polarities
    int groups = NumberOfAttractMagnets(magnets);            // Step 3: Calculate number of groups
    printNumberOfAttractMagnets(groups);                     // Step 4: Display result
    return 0;
}
