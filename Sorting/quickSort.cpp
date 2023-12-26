#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int high);

void quickSort(vector<int> &v, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot = partition(v, low, high);
    quickSort(v, low, pivot - 1);
    quickSort(v, pivot + 1, high);
}

// pivot -> last element
int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[j], v[i]);
        }
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

// pivot -> first element
// int partition(vector<int> &v, int low, int high)
// {
//     int pivot = v[low];
//     int i = high + 1;

//     for (int j = high; j >= low + 1; j--)
//     {
//         if (v[j] > pivot)
//         {
//             i--;
//             swap(v[j], v[i]);
//         }
//     }

//     swap(v[i - 1], v[low]);
//     return i - 1;
// }

int main()
{
    vector<int> v = {3, 7, 1, 8, 10, 9};

    quickSort(v, 0, v.size() - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity:
// Best Case: "Sigma"(nlogn)
// Average case: "Theta"(nlogn)
// Worst Case: O(n^2)

// Space Complexity: O(logn)