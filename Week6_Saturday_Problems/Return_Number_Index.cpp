#include <iostream>
using namespace std;

// Function to read the size of the array from the user
int ReadArraySize()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Validate the size so it stays between 1 and 500
    while (n <= 0 || n > 500)
    {
        cout << "Invalid size. Enter a number between 1 and 100: ";
        cin >> n;
    }
    return n;
}

// Function to read elements into the array
// NOTE: Arrays in (C++, C#, java, python....) are passed by reference (not copied).
// That means changes here will directly affect the original array.
void ReadArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Enter element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

// Function to print the array elements
// Again, arr[] is passed by reference (no copying).
void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";  // Print each element followed by a space
    cout << endl;
}

// Function to read the target number we want to find
int ReadTargetNumber()
{
    int target;
    cout << "\nEnter the number to find: ";
    cin >> target;
    return target;
}

// Function to search for the target number in the array
// Returns the index if found, otherwise returns -1
// arr[] is passed by reference (so we are checking the actual array).
int FindIndex(int arr[], int arrLength, int target)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == target)  // If the element matches the target
            return i;          // Return its index
    }
    return -1; // Target not found
}

// Function to print the result of the search
void PrintIndex(int index, int target)
{
    if (index != -1)
        cout << "The number " << target << " is at index " << index << endl;
    else
        cout << "The number " << target << " is not in the array." << endl;
}

int main()
{
    int arr[500];  // Array of maximum size 500

    // Step 1: Read array size
    int arrLength = ReadArraySize();

    // Step 2: Read array elements (passed by reference to the function)
    ReadArray(arr, arrLength);

    // Step 3: Print all elements of the array
    cout << "\nArray elements: ";
    PrintArray(arr, arrLength);

    // Step 4: Ask user for a number to search
    int target = ReadTargetNumber();  

    // Step 5: Find the index of the target number
    int index = FindIndex(arr, arrLength, target);

    // Step 6: Print the result
    PrintIndex(index, target);

    return 0;
}
