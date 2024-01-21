#include <iostream>
#include <vector>
using namespace std;

// For min Heap now
void heapify(int *arr, int i, int n)
{
    int smallest = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest, n);
    }
}

vector<int> buildMinHeap(int *arr, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        vect.push_back(arr[i]);
    }

    return vect;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {9, 3, 2, 6, 7};
    vector<int> sortedArr = buildMinHeap(arr, 5);
    cout << "The created min heap is: ";
    printVector(sortedArr);

    return 0;
}