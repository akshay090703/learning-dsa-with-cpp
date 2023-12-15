#include <iostream>
#include <vector>
using namespace std;

int minElementInSortedRotatedArr(vector<int> &input)
{
    int high = input.size() - 1, low = 0;
    int ans = 0;
    if (input[low] < input[high])
        return ans;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (input[mid] < input[mid - 1])
            return mid;

        if (input[mid] > input[mid + 1])
            return mid + 1;

        if (input[low] < input[mid])
            low = mid + 1;
        else if (input[low] > input[mid])
        {
            high = mid;
            ans = mid;
        }
        else
            break;
    };
    return ans;
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

    cout << "The index of the minimum element in the sorted rotated array: " << minElementInSortedRotatedArr(input);

    return 0;
}

// n => length of array
// time complexity -> O(log(n))
// space complexity -> O(1)
// The O(log n) time complexity suggests that the algorithm can handle large datasets effectively.
// However, the O(1) space complexity does mean that the algorithm has limited ability to scale up the number of queries it can handle.