#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ReadArraySize()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    while (n <= 0 || n > 100)
    {
        cout << "Invalid size. Enter a number between 1 and 100: ";
        cin >> n;
    }
    return n;
}

void FillOrderedArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

void PrintArray(int arr[], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int RandomNumber(int from, int to)
{
    return from + rand() % (to - from + 1);
}

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ShuffleArray(int arr[], int arrLength)
{
    for (int i = arrLength - 1; i > 0; i--)
    {
        int j = RandomNumber(0, i);
        Swap(arr[i], arr[j]);
    }
}

int main()
{
    srand(time(0));

    int arr[500];
    int arrLength = ReadArraySize();

    FillOrderedArray(arr, arrLength);

    cout << "\nOriginal ordered array: ";
    PrintArray(arr, arrLength);

    ShuffleArray(arr, arrLength);

    cout << "\nShuffled array: ";
    PrintArray(arr, arrLength);
}
