#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &v, int k)
{
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(v[dq.front()]);

    for (int i = k; i < v.size(); i++)
    {
        int curr = v[i];

        if (dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(v[dq.front()]);
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = maxSlidingWindow(nums, 3);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}