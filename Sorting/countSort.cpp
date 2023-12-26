#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &v)
{
    int n = v.size();

    // finding max element
    int max_element = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max_element)
        {
            max_element = v[i];
        }
    }

    // getting a frequency array
    vector<int> cumulative_freqArr(max_element + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cumulative_freqArr[v[i]]++;
    }

    // getting cumulative frequency array
    for (int i = 1; i <= max_element; i++)
    {
        cumulative_freqArr[i] += cumulative_freqArr[i - 1];
    }

    // making an answer array
    // starting from last element so that it can be stable
    vector<int> answerArr(n);
    for (int i = n - 1; i >= 0; i--)
    {
        cumulative_freqArr[v[i]]--;
        answerArr[cumulative_freqArr[v[i]]] = v[i];
    }

    // copying sorted array elements to original array
    for (int i = 0; i < n; i++)
    {
        v[i] = answerArr[i];
    }
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 3, 2};

    countSort(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity -> O(n + max) ~ O(n) when max < n or comparable
// Space Complexity -> O(n + max) as we made one freq array and one answer array