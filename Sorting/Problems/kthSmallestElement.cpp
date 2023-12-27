#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int low, int high);

int kthSortedElement(vector<int> v, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivot = partition(v, low, high);
        if (pivot - low == k - 1)
            return v[pivot];
        else if (pivot - low > k - 1)
            return kthSortedElement(v, low, pivot - 1, k);
        else
            return kthSortedElement(v, pivot + 1, high, k - (pivot - low + 1));
    }
    return -1;
}

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (pivot > v[j])
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);
    return i + 1;
}

int main()
{
    vector<int> v = {3, 5, 2, 1, 4, 7, 8, 6};
    int k = 7;

    cout << "The " << k << "th smallest number in sorted array is: " << kthSortedElement(v, 0, v.size() - 1, k) << endl;

    system("pause");
    return 0;
}

// in worst case time complexity -> O(n^2)
// in average and best case -> O(2*n -1) ~ O(n)

// space complexity -> O(logn)