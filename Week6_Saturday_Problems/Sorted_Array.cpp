#include <iostream>
using namespace std;

// Enum to represent whether an array is sorted or not
enum SortedStatus { SORTED, NOT_SORTED };

// Function to read the size of the array from the user
int ReadArraySize()
{
    int n;
    cout << "Enter the number of elements in the array (1 to 500): ";
    cin >> n;

    // Validate size so it stays between 1 and 500
    while (n <= 0 || n > 500)
    {
        cout << "Invalid input. Please enter a number between 1 and 500: ";
        cin >> n;
    }
    return n;
}

// Function to read elements into the array
// NOTE: Arrays in C++ are passed by reference (not copied)
// Any changes or reads directly affect the original array
void ReadArray(int arr[], int arrLength)
{
    cout << "Enter " << arrLength << " integer elements of the array separated by spaces:\n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Function to print the array elements
// arr[] is passed by reference (no copy)
void PrintArray(int arr[], int arrLength)
{
    cout << "Array elements: ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to check if the array is sorted in non-decreasing order
// arr[] is passed by reference, so the function works on the original array
SortedStatus CheckSorted(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength - 1; i++)
        if (arr[i] > arr[i + 1])  // If current element > next element, array is not sorted
            return NOT_SORTED;

    return SORTED;  // All elements checked, array is sorted
}

// Function to print the result of the sorted check
void PrintSortedResult(SortedStatus status)
{
    if (status == SORTED)
        cout << "The array is sorted in non-decreasing order." << endl;
    else
        cout << "The array is NOT sorted." << endl;
}

int main()
{
    int arr[500];  // Array of maximum size 500

    // Step 1: Read the array size
    int arrLength = ReadArraySize();

    // Step 2: Read array elements (passed by reference)
    ReadArray(arr, arrLength);

    // Step 3: Print the array elements
    PrintArray(arr, arrLength);

    // Step 4: Check if the array is sorted
    SortedStatus status = CheckSorted(arr, arrLength);

    // Step 5: Print the result
    PrintSortedResult(status);

    return 0;
}
