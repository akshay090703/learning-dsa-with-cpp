#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        // assuming that the first index is the minimum element in the unsorted array and then finding the minimum element
        int min_index = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[min_index] > v[j])
                min_index = j;
        }

        // placing the minimum element at the beginning
        if (min_index != i)
            swap(v[i], v[min_index]);
    }
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

    cout << "Sorted array is: ";
    selectionSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)