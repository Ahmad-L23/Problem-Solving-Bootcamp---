#include <iostream>
#include <vector>
using namespace std;

// Function to read the size of the array from the user
int readSize() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    return n;
}

// Function to read 'n' elements into a vector
void readArray(vector<int>& arr, int n) {
    arr.resize(n); // allocate space for n elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i]; // input each element
    }
}

// Function to move all zeroes to the end while keeping the order of non-zero elements
void moveZeroes(vector<int>& arr) {
    int insertPos = 0; // position to insert the next non-zero number

    // First pass: move non-zero elements forward
    for (int x : arr) {
        if (x != 0) {
            arr[insertPos++] = x; // place non-zero value at insertPos and move insertPos forward
        }
    }

    // Second pass: fill the remaining positions with zeroes
    while (insertPos < (int)arr.size()) {
        arr[insertPos++] = 0;
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " "; // print each element with a space
    }
    cout << endl; // new line after printing array
}

int main() {
    // Step 1: Read size from user
    int n = readSize();

    // Step 2: Declare a vector to hold numbers
    vector<int> nums;

    // Step 3: Read elements into the vector
    readArray(nums, n);

    // Step 4: Call function to move zeroes to the end
    moveZeroes(nums);

    // Step 5: Print the final result
    cout << "Array after moving zeroes: ";
    printArray(nums);
}
