#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
    int left = 0, middle = 0, right = n - 1;

    // In this approach we only see the middle pointer and adjust other pointers accordingly
    while (middle <= right)
    {
        if (arr[middle] == 0)
        {
            swap(arr[left], arr[middle]);
            left++;
            middle++;
        }
        else if (arr[middle] == 1)
        {
            middle++;
        }
        else if (arr[middle] == 2)
        {
            swap(arr[middle], arr[right]);
            right--;
        }
    }
};

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    cout << "Enter elements of the array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };

    cout << "Sorted Array of 0, 1 and 2: ";
    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}