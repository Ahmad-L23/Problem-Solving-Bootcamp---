#include <iostream>
#include <cstdlib>
#include <ctime>
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

// Function to generate a random number in a given range [from, to]
int RandomNumber(int from, int to)
{
    return from + rand() % (to - from + 1);
}

// Function to fill the array with random numbers
// NOTE: Arrays in (C++, C#, Java, Python) are passed by reference (not copied).
// That means the function modifies the original array directly.
void FillRandomArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 20);  // Store a random number between 1 and 20
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

// Function to compute the prefix sum of an array
// prefix[i] = sum of arr[0] + arr[1] + ... + arr[i]
// Both arr[] and prefix[] are passed by reference.
void ComputePrefixSum(int arr[], int arrLength, int prefix[])
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];      // Add current element to running sum
        prefix[i] = sum;    // Store sum in prefix array
    }
}

int main()
{
    srand(time(0));  // Seed random number generator with current time

    int arr[500], prefix[500];  // Original array and prefix sum array
    int arrLength = ReadArraySize();

    // Step 1: Fill the array with random numbers
    FillRandomArray(arr, arrLength); 

    // Step 2: Print the original random array
    cout << "\nRandom array: ";
    PrintArray(arr, arrLength);

    // Step 3: Compute the prefix sum of the array
    ComputePrefixSum(arr, arrLength, prefix);

    // Step 4: Print the prefix sum array
    cout << "\nPrefix sum array: ";
    PrintArray(prefix, arrLength);

    return 0;
}
