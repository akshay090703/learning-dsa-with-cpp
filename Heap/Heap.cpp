#include <iostream>
using namespace std;

class Heap
{
    int capacity;
    int size;
    int *arr;

public:
    Heap(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        this->arr = new int[capacity + 1]; // to allow indexing from 1
    }

    ~Heap()
    {
        delete[] arr;
    }

    // Time Complexity -> O(log(n))
    void insert(int data)
    {
        this->size++;
        int index = size;
        this->arr[index] = data;
        int parent = index / 2;

        while (index > 1 && arr[parent] < arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
            parent = index / 2;
        }
    }

    // Time Complexity -> O(log(n))
    void deleteRoot()
    {
        if (this->size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step 1: put last element into first index
        arr[1] = arr[size];

        // step 2: remove last index element
        size--;

        // step 3: take root to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = (2 * i) + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// code written for Max Heap
// Time Complexity -> O(log(n))
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    else if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    Heap h(10);
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.deleteRoot();
    h.printHeap();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array now: ";
    for (int i = 1; i <= n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}