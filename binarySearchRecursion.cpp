#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(int *arr, int size)
{
    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

int sumOfArray(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    cout << "Size: " << size << endl;
    int sum = arr[0] + sumOfArray(arr + 1, size - 1);
    cout << "Sum: " << sum << endl;

    return sum;
}

bool LinearSearch(int arr[], int size, int key)
{
    // print(arr, size);
    if (size == 0)
    {
        return false;
    }
    if (key == arr[0])
    {
        return true;
    }
    else
    {
        bool remainingPart = LinearSearch(arr + 1, size - 1, key);
        return remainingPart;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    // bool ans = isSorted(arr, size);

    // int ans = sumOfArray(arr, size);

    // int ans = LinearSearch(arr, size, 4);

    return 0;
}