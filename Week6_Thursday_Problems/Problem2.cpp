#include <iostream>
using namespace std;

int ReadArraySize()
{
    int size;
    
    cout << "How many elements do you want in the array? ";
    cin >> size;
    
    return size;
}

void ReadArrayElements(int arr[], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int CopyEvenNumbers(int source[], int sourceLength, int target[])
{
    int evenCount = 0;
    for (int i = 0; i < sourceLength; i++)
    {
        if (source[i] % 2 == 0)
        {
            target[evenCount] = source[i];
            evenCount++;
        }
    }
    return evenCount;
}

int main()
{
    int arr[500], evenArr[500], arrLength, evenLength;

    arrLength = ReadArraySize();
    ReadArrayElements(arr, arrLength);

    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);

    evenLength = CopyEvenNumbers(arr, arrLength, evenArr);

    cout << "\nEven numbers copied: ";
    PrintArray(evenArr, evenLength);
}
