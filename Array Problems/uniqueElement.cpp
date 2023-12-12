#include <iostream>
using namespace std;

// XOR property:
// a ^ a = 0
// a ^ 0 = a

int findUnique(int *arr, int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    };
    return ans;
};

int main()
{
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    cout << "Enter elements of the array: ";
    int arr[n];
    for (auto &element : arr) // using a reference to modify array elements
    {
        cin >> element;
    }

    int uniqueElement = findUnique(arr, n);
    cout << "Unique Element: " << uniqueElement << endl;

    return 0;
}