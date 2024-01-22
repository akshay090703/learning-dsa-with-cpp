#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &v, int i, int n)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

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
        swap(v[i], v[largest]);
        heapify(v, largest, n);
    }
}

// Time Complexity -> O((n+m)log(n+m))
// Space Complexity -> O(n+m)
vector<int> merge2BinaryMaxHeap(vector<int> &heap1, vector<int> &heap2)
{
    vector<int> mergeHeap;
    int i = 0, j = 0;
    while (i < heap1.size() && j < heap2.size())
    {
        if (heap1[i] > heap2[j])
            mergeHeap.push_back(heap1[i++]);
        else
            mergeHeap.push_back(heap2[j++]);
    }

    while (i < heap1.size())
    {
        mergeHeap.push_back(heap1[i++]);
    }

    while (j < heap2.size())
    {
        mergeHeap.push_back(heap2[j++]);
    }

    int size = heap1.size() + heap2.size();

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(mergeHeap, i, size);
    }

    return mergeHeap;
}

void printArray(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    vector<int> v1 = {10, 5, 6, 2};
    for (int i = (v1.size() / 2) - 1; i >= 0; i--)
    {
        heapify(v1, i, v1.size());
    }
    printArray(v1);

    vector<int> v2 = {12, 7, 9};
    for (int i = (v2.size() / 2) - 1; i >= 0; i--)
    {
        heapify(v2, i, v2.size());
    }
    printArray(v2);

    vector<int> ans = merge2BinaryMaxHeap(v1, v2);
    cout << "The merged and sorted array is: ";
    printArray(ans);

    return 0;
}