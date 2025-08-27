#include <iostream>
using namespace std;

// Enum to represent whether an array is a palindrome or not
enum PalindromeStatus { PALINDROME, NOT_PALINDROME };

// Function to read the size of the array from the user
int ReadArraySize()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Validate size so it stays between 1 and 100
    while (n <= 0 || n > 100)
    {
        cout << "Invalid size. Enter a number between 1 and 100: ";
        cin >> n;
    }
    return n;
}

// Function to read elements into the array
// NOTE: Arrays in C++ are passed by reference (not copied)
// Changes here directly affect the original array
void ReadArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
}

// Function to print the array elements
// arr[] is passed by reference
void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to check if the array is a palindrome
// arr[] is passed by reference, so we check the original array
PalindromeStatus CheckPalindrome(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength / 2; i++)
    {
        if (arr[i] != arr[arrLength - 1 - i])
            return NOT_PALINDROME;  // Return immediately if mismatch found
    }
    return PALINDROME;  // All elements matched
}

// Function to print the result of palindrome check
void PrintPalindromeResult(PalindromeStatus status)
{
    if (status == PALINDROME)
        cout << "The array is a palindrome." << endl;
    else
        cout << "The array is NOT a palindrome." << endl;
}

int main()
{
    int arr[100];  // Array of maximum size 100

    // Step 1: Read the array size
    int arrLength = ReadArraySize();

    // Step 2: Read array elements (passed by reference)
    ReadArray(arr, arrLength);

    // Step 3: Print the array
    cout << "\nArray elements: ";
    PrintArray(arr, arrLength);

    // Step 4: Check if the array is a palindrome
    PalindromeStatus status = CheckPalindrome(arr, arrLength);

    // Step 5: Print the result
    PrintPalindromeResult(status);

    return 0;
}
