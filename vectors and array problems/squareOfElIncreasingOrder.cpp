#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    vector<int> ansV;
    int left_pointer = 0, right_pointer = n - 1;
    while (left_pointer <= right_pointer)
    {
        if (abs(array[left_pointer]) > abs(array[right_pointer]))
        {
            ansV.push_back(array[left_pointer] * array[left_pointer]);
            left_pointer++;
        }
        else
        {
            ansV.push_back(array[right_pointer] * array[right_pointer]);
            right_pointer--;
        }
    }

    reverse(ansV.begin(), ansV.end());

    // Printing the output
    cout << "The increasing order of squares of array: ";
    for (int i = 0; i < ansV.size(); i++)
    {
        cout << ansV[i] << " ";
    }

    return 0;
}