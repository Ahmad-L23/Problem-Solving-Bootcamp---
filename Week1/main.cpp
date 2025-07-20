#include <iostream>
#include <vector>
using namespace std;

void readTestCases(int& testCases) {

    // Just to read the number of test cases, then read the test cases based on that number.
    // We are using call by reference
    cout << "Enter the number of test cases: ";
    cin >> testCases;
}

vector<int> getUniqueValues(int testCases) {
    vector<int> values;
    int a, b, c;

    for (int i = 0; i < testCases; ++i) {
        cout << "Enter three integers for test case " << i + 1 << ": ";
        cin >> a >> b >> c;

        /* Check if all the numbers are not equal to each other (there is no unique number)
            => then the value will be 0, which means there is no unique number. */
            // and it works as valditon to check that all the three numbers are not equal to each other
        if(a != b && a != c && c!=b){
           values.push_back(0);
           continue;
        }

        // Check if the value of (a) is not equal to the other two numbers if so it's unique.
        if (a != b && a != c)
            values.push_back(a);

        // Check if the value of (b) is not equal to the other two numbers if so it's unique.
        else if (b != c && b != a)
            values.push_back(b);

        // In the first two checks, we know that a and b are not unique, so the unique one must be (c).
        else
            values.push_back(c);
    }

    return values;
}


// Just to print the unique values by looping through the vector
void printValues(const vector<int>& values) {
    cout << "\nUnique values from each test case:\n";
    for (int i = 0; i < values.size(); ++i)
        cout << "Test Case " << i + 1 << ": " << values[i] << endl;
}

int main() {
    int testCases = 3; // The initial value is 3 to demonstrate how call by reference works.
                     // Try removing the call by reference to see that the input won’t affect the value and it will remain 3.
    readTestCases(testCases);
    vector<int> values = getUniqueValues(testCases);
    printValues(values);
    return 0;
}
