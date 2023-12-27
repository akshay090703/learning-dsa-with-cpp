#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<double> &arr);

// for 0-1 range
// void bucketSort(vector<double> &v)
// {
//     int n = v.size();
//     vector<vector<double>> buckets(n);

//     // putting elements in buckets
//     for (int i = 0; i < n; i++)
//     {
//         int index = v[i] * n;
//         buckets[index].push_back(v[i]);
//     }

//     // sorting each bucket using insertion sort (it is also stable)
//     for (int i = 0; i < n; i++)
//     {
//         insertionSort(buckets[i]);
//     }

//     vector<double> answerArr(n);
//     // merging all the arrays
//     int idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (buckets[i].size() != 0)
//         {
//             for (int j = 0; j < buckets[i].size(); j++)
//             {
//                 answerArr[idx++] = buckets[i][j];
//             }
//         }
//     }

//     // copying elements to the original array
//     for (int i = 0; i < n; i++)
//     {
//         v[i] = answerArr[i];
//     }
// }

// for more than 0-1 range
void bucketSort(vector<double> &v)
{
    int n = v.size();
    vector<vector<double>> buckets(n);

    // finding the range
    double max_element = v[0];
    double min_element = v[0];
    for (int i = 1; i < n; i++)
    {
        max_element = max(max_element, v[i]);
        min_element = min(min_element, v[i]);
    }
    double range = (max_element - min_element) / n;

    // putting elements in buckets
    for (int i = 0; i < n; i++)
    {
        int index = (v[i] - min_element) / range;

        // boundary elements
        double diff = (v[i] - min_element) / range - index;
        if (diff == 0 && v[i] != min_element)
            index--;

        buckets[index].push_back(v[i]);
    }

    // sorting each bucket using insertion sort (it is also stable)
    for (int i = 0; i < n; i++)
    {
        insertionSort(buckets[i]);
    }

    vector<double> answerArr(n);
    // merging all the arrays
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (buckets[i].size() != 0)
        {
            for (int j = 0; j < buckets[i].size(); j++)
            {
                answerArr[idx++] = buckets[i][j];
            }
        }
    }

    // copying elements to the original array
    for (int i = 0; i < n; i++)
    {
        v[i] = answerArr[i];
    }
}

void insertionSort(vector<double> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        double current_element = arr[i];

        // finding current position of current element
        int j = i - 1;
        while (j >= 0 && current_element < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // inserting current element at the correct position
        arr[j + 1] = current_element;
    }
}

int main()
{
    vector<double> v = {0.13, 0.45, 0.12, 1.89, 0.75, 0.63, 0.85, 10.39};
    // vector<double> v = {0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39};

    bucketSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
