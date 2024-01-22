#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity -> O(nlogk)
// Space Complexity -> O(k)
int kThLargestELement(vector<int> &input, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < k; i++)
    {
        minHeap.push(input[i]);
    }

    for (int i = k; i < input.size(); i++)
    {
        if (minHeap.top() < input[i])
        {
            minHeap.pop();
            minHeap.push(input[i]);
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> input = {7, 10, 4, 20, 15};
    int k;
    cout << "Enter k: ";
    cin >> k;
    cout << "K-th largest element is: " << kThLargestELement(input, k) << endl;

    return 0;
}