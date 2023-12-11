#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the elements for the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the difference value: ";
    int diff;
    cin >> diff;
    int left_pointer = 0, right_pointer = n - 1;

    string message = "No";
    while (left_pointer < right_pointer)
    {
        if (abs(arr[left_pointer] - arr[right_pointer]) == diff)
        {
            message = "Yes";
            break;
        }
        else if (abs(arr[left_pointer] - arr[right_pointer]) > diff)
        {
            right_pointer--;
        }
        else
        {
            left_pointer++;
        }
    }

    cout << message;

    return 0;
}