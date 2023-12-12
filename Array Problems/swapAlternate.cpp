#include <iostream>
using namespace std;

void swapAlternate(int *arr, int n)
{
    for (int i = 0; i <= n - 2; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
};

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    cout << "Enter the elements for the array: ";
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Alternative swapped array: ";
    swapAlternate(array, n);
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}