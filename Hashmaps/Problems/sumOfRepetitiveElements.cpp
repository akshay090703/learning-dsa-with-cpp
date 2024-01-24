#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time COmplexity -> O(n)
// Space COmplexity -> O(n)
int sumOfRepetitiveElements(vector<int> &v)
{
    unordered_map<int, int> m;

    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]]++;
    }
    int res = 0;
    for (auto it : m)
    {
        if (it.second > 1)
        {
            res += it.first;
        }
    }

    return res;
}

int main()
{
    vector<int> input = {1, 2, 1, 3, 3, 3, 4, 5, 6, 7, 6};
    cout << "Sum of repetitive elements: " << sumOfRepetitiveElements(input) << endl;

    return 0;
}