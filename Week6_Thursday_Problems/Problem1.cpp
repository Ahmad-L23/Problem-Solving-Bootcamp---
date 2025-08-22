#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
    int num = 0;
    
    cout << "\nEnter Number You want to Check: ";
    cin >> num;
    
    return num;
}

int ReadLength()
{
    int num = 0;

    cout << "\nEnter array length: ";
    cin >> num;

    return num;
}

void ReadArrayElements(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void PrintArray(int arr[], int arrLength, string message = "")
{
    if (!message.empty())
        cout << message;

    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int RepeatedNumber(int arr[], int arrLength, short numberToCheck)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == numberToCheck)
            counter++;
    }
    return counter;
}

int main()
{
    int arr[500];
    int arrLength;
    int numberToCheck;
    arrLength = ReadLength();
    ReadArrayElements(arr, arrLength);

    PrintArray(arr, arrLength, "\nOriginal array: ");

    numberToCheck = ReadPositiveNumber();

    cout << "\nNumber " << numberToCheck << " is repeated ";
    cout << RepeatedNumber(arr, arrLength, numberToCheck) << " time(s)\n";
}
