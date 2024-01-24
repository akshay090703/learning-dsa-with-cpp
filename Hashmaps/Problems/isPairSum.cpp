#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity -> O(n)
// Space Complexity -> O(n)
pair<int, int> isPairSum(vector<int> &input, int target)
{
    unordered_map<int, int> m; // key: element, value: index
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < input.size(); ++i)
    {
        int diff = target - input[i];
        if (m.find(diff) == m.end())
        {
            m[input[i]] = i;
        }
        else
        {
            ans.first = diff;
            ans.second = input[i];
            break;
        }
    }

    return ans;
}

int main()
{
    // vector<int> v = {1, 4, 5, 11, 13, 10, 2};
    vector<int> v = {9, 10, 2, 3, 5};
    int target = 15;
    pair<int, int> res = isPairSum(v, target);
    cout << "Numbers in the array that adds to " << target << " are " << res.first << " and " << res.second << endl;

    return 0;
}