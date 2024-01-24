#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time Complexity -> O(n+n) ~ O(n)
// Space Complexity -> O(n)
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 2};
    int n = arr.size();
    cout << maximumFrequency(arr, n) << endl;
    // answer: 1

    return 0;
}