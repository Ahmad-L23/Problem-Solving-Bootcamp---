#include <iostream>
#include <string>
using namespace std;

// Enum to represent danger status
enum enDangerStatus { NotDangerous = 0, Dangerous = 1 };

// Reads the string input representing players' positions from the user
string ReadSituation()
{
    string s;
    cout << "Enter players' positions (0s and 1s): ";
    cin >> s;  // User enters a string like "00110001111111"
    return s;
}

// Checks whether the input situation is dangerous or not
enDangerStatus CheckDangerStatus(const string& situation)
{
    int counter = 1;  // Counter for consecutive same characters

    // Start from the second character and compare with the previous one
    for (int i = 1; i < situation.length(); ++i)
    {
        if (situation[i] == situation[i - 1] && situation[i] == '1')  // Check if current char matches the previous
        {
                counter++;  // Increase counter if they match

            if (counter >= 7)
                return enDangerStatus::Dangerous;  // Return immediately if 7 or more same chars
        }
        else
        {
            counter = 1;  // Reset counter if characters are different
        }
    }

    // If loop completes without triggering danger, return NotDangerous
    return enDangerStatus::NotDangerous;
}

// Check if the stuiation is dangerous
string IsDangerousSituation(string situation)
{
    enDangerStatus status = CheckDangerStatus(situation);
    return (status == enDangerStatus::Dangerous ? "Yes" : "No");
}

// Displays the result to the user
void PrintResult(string result)
{
    cout << "Is the situation dangerous? " << result << endl;
}


int main()
{
    cout << "=== Football Game Situation Analyzer ===" << endl;

    // Read the situation from the user
    // Determine if the situation is dangerous
    // Output the result
    PrintResult(IsDangerousSituation( ReadSituation()));

    return 0;
}
