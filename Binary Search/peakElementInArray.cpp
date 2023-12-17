#include <iostream>
#include <vector>
using namespace std;

int peakElementInArray(vector<int> &input)
{
    int start = 0, end = input.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (input[mid - 1] < input[mid])
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
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

    cout << "Peak element index in the array is: " << peakElementInArray(input) << endl;

    system("pause");
    return 0;
}
