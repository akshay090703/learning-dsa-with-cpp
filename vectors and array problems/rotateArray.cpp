#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int k = 24;
    // k can be greater than n as well
    k %= n;

    int ansArray[n];
    int j = 0;

    // inserting last k elements in new array
    for (int i = n - k; i < n; i++)
    {
        ansArray[j++] = array[i];
    }

    // inserting first n-k elements in new ans array
    for (int i = 0; i < n - k; i++)
    {
        ansArray[i + k] = array[i];
    }

    cout << "Array after rotations: ";
    for (int i = 0; i < n; i++)
    {
        cout << ansArray[i] << " ";
    }

    return 0;
}