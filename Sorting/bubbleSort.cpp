#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> v)
{
    int n = v.size();
    // number of passes -> n - 1
    for (int i = 0; i < n - 1; i++)
    {
        // we only have to access till the second last element
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    return v;
}

vector<int> optimizedBubbleSort(vector<int> v)
{
    int n = v.size();
    // number of passes -> n - 1
    for (int i = 0; i < n - 1; i++)
    {
        // variable used to check if any swapping operation is done or not in this pass
        bool flag = false;

        // we only have to access till the second last element
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                flag = true;
                swap(v[j], v[j + 1]);
            }
        }

        if (!flag)
            break;
    }
    return v;
}

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    vector<int> v(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // vector<int> sorted_arr = bubbleSort(v);
    vector<int> sorted_arr = optimizedBubbleSort(v);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << sorted_arr[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity: O(n^2)
// Best case time complexity of Optimized Algo. -> O(n)
// Space Complexity: O(1)