#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int current_el = v[i];

        // finding the correct position for our current element
        int j = i - 1;
        while (j >= 0 && v[j] > current_el)
        {
            v[j + 1] = v[j];
            j--;
        }

        // inserting the current element at correct position
        v[j + 1] = current_el;
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
    insertionSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n^2)
// Best case time complexity of Algo. -> O(n)
// Space Complexity -> O(1)