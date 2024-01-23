#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int signum(int x, int y)
{
    if (x == y)
        return 0;
    else if (x > y)
        return 1;
    else
        return -1;
}

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;

    case 1:
        if (element > median)
        {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;

    case -1:
        if (element > median)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;

    default:
        break;
    }
}

// we will have maxHeap and minHeap and the middle element is median
// n for loop and log(n) for each push function into heap
// Time Complexity -> O(nlogn)
// Space Complexity -> O(n) // minHeap and maxHeap
vector<int> findMedian(vector<int> &arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    int median = -1;

    for (int i = 0; i < n; i++)
    {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{
    vector<int> stream = {1, 2, 3};
    int n = 3;
    vector<int> result = findMedian(stream, n); // 1 1 2
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}