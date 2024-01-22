#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
int twoSmallestElements(vector<int> &v)
{
    int minCost = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < v.size(); ++i)
    {
        minHeap.push(v[i]);
    }

    while (minHeap.size() > 1)
    {
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        minCost += x + y;
        minHeap.push(x + y);
    }

    return minCost;
}

int main()
{
    vector<int> input = {4, 3, 2, 6};
    cout << "The minimum cost of ropes is: ";
    cout << twoSmallestElements(input) << endl;

    return 0;
}