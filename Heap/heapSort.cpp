#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int i, int n)
{
    int largest = i;
    int left = (i * 2);
    int right = (i * 2) + 1;

    if (left < n && v[largest] < v[left])
    {
        largest = left;
    }
    if (right < n && v[largest] < v[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(v[largest], v[i]);
        heapify(v, largest, n);
    }
}

// Time Complexity -> O(n(log(n)))
// Space Complexity -> O(1)
void heapSort(vector<int> &v, int n)
{
    int size = n;

    while (size > 1)
    {
        // Step 1: swapping first and last element in maxHeap
        // following 1 based indexing
        swap(v[1], v[size]);

        // Step 2 and 3: reduce size by 1 and then heapify
        size--;
        heapify(v, 1, size);
    }
}

int main()
{
    vector<int> v = {INT_MIN, 20, 30, 25, 5, 40, 35, 10};
    int n = v.size();
    // heap creation
    for (int i = n / 2; i > 0; i--)
    {
        heapify(v, i, n);
    }

    heapSort(v, n - 1);

    for (int i = 1; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}