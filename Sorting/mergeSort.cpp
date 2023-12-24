#include <iostream>
#include <vector>
using namespace std;

// my code
vector<int> merge(vector<int> v1, vector<int> v2)
{
    int i = 0, j = 0;

    vector<int> result;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] >= v2[j])
        {
            result.push_back(v2[j]);
            j++;
        }
        else
        {
            result.push_back(v1[i]);
            i++;
        }
    }

    while (i < v1.size())
    {
        result.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        result.push_back(v2[j]);
        j++;
    }

    return result;
}

vector<int> mergeSort(vector<int> &v, int start, int end)
{
    int mid = start + ((end - start) / 2);
    if (start >= end)
        return {v[mid]};

    return merge(mergeSort(v, start, mid), mergeSort(v, mid + 1, end));
}

// A little optimized one
void optimizedMerge(vector<int> &v, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Creating temporary arrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = v[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = v[(mid + 1) + j];

    // Merging of the arrays
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements
    while (i < n1)
    {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        v[k] = right[j];
        j++;
        k++;
    }
}

void optimizedMergeSort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);

        // Sort first and second halves
        optimizedMergeSort(v, start, mid);
        optimizedMergeSort(v, mid + 1, end);

        // Merge the sorted halves
        optimizedMerge(v, start, mid, end);
    }
    else
        return;
}

int main()
{
    vector<int> v = {10, 28, 24, 6, 34, 18, 38, 44, 28};

    cout << "Sorted Array: ";
    vector<int> sorted_array = mergeSort(v, 0, v.size() - 1);
    for (size_t i = 0; i < sorted_array.size(); i++)
    {
        cout << sorted_array[i] << " ";
    }
    cout << endl;

    // optimizedMergeSort(v, 0, v.size() - 1);
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    system("pause");
    return 0;
}

// Both the approaches has same time and space complexity
// But the optimized one optimizes the space complexity by performing
// the merging in-place instead of creating temporary vectors for the left and right halves
// Time Complexity-> O(nlogn)
// Space Complexity -> O(1)