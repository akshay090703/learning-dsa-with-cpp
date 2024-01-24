#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity -> O(n)
// Space Complexity -> O(n)
int lengthOfLongestSubArrayWithSum0(vector<int> &input)
{
    unordered_map<int, int> m;
    int prefixSum = 0;
    int maxlen = 0;

    for (int i = 0; i < input.size(); i++)
    {
        prefixSum += input[i];

        if (prefixSum == 0)
        {
            maxlen++;
        }

        if (m.find(prefixSum) != m.end())
        {
            maxlen = max(maxlen, i - m[prefixSum]);
        }
        else
        {
            m[prefixSum] = i;
        }
    }

    return maxlen;
}

int main()
{
    // vector<int> input = {15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> input = {1, 2, 3};
    cout << "Length of the longest subarray with sum 0 is: " << lengthOfLongestSubArrayWithSum0(input) << endl;

    return 0;
}