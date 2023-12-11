#include <iostream>
using namespace std;

int main()
{
    cout << "Give the length of the array: ";
    int n;
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array in increasing order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Give an integer x to check in the array: ";
    int x;
    cin >> x;

    // checking for the pair sum to be equal to x
    string message = "No";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((array[i] + array[j]) == x)
            {
                message = "Yes";
                break;
            }
        }
    }

    cout << message;

    return 0;
}