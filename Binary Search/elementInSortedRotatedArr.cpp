#include <iostream>
#include <vector>
using namespace std;

int elementInSortedRotatedArr(vector<int> &input, int &target)
{
    int low = 0, high = input.size() - 1;
    while (low <= high)
    {
        int mid = low + ((high - low)) / 2;
        if (input[mid] == target)
            return mid;
        if (input[mid] >= input[low])
        {
            if (target >= input[low] && target <= input[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target >= input[mid] && target <= input[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    };
    return -1;
}

int main()
{
    cout << "Enter the size of vector: ";
    int n;
    cin >> n;

    vector<int> input(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    };

    cout << "Enter the target element: ";
    int target;
    cin >> target;

    cout << "The index of the target element in the sorted rotated array: " << elementInSortedRotatedArr(input, target) << endl;

    return 0;
}
