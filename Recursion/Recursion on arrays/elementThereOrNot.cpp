#include <iostream>
using namespace std;

bool elementPresentOrNot(int *arr, int n, int i, int x)
{
    if (i == n)
        return false;

    return (arr[i] == x) || elementPresentOrNot(arr, n, i + 1, x);
};

int main()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    string answer = (elementPresentOrNot(arr, size, 0, x) ? "Yes" : "No");

    cout << "Result: " << answer << endl;

    return 0;
}