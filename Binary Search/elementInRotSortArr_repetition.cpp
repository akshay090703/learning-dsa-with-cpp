#include <iostream>
#include <vector>
using namespace std;

bool elementInSortedRotatedArr(vector<int> &input, int &target)
{
    int start = 0, end = input.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (input[mid] == target)
            return 1;

        if (input[start] == input[mid] && input[mid] == input[end])
        {
            start++;
            end--;
        }
        else if (input[mid] >= input[start])
        {
            if (input[start] <= target && target <= input[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (input[mid] <= target && target <= input[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return 0;
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

    cout << "Is the target element in the sorted rotated array: " << elementInSortedRotatedArr(input, target) << endl;

    system("pause");
    return 0;
}
