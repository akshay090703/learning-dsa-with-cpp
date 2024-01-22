#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time Complexity -> O(nlog(k))
// Space Complexity -> O(k)
int kThSmallestELement(vector<int> &input, int k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < k; i++)
    {
        maxHeap.push(input[i]);
    }

    int i = k;
    while (i < input.size())
    {
        if (maxHeap.top() > input[i])
        {
            maxHeap.pop();
            maxHeap.push(input[i]);
        }
        i++;
    }

    return maxHeap.top();
}

// we can also find the kth largest element using min heap

int main()
{
    vector<int> input = {7, 10, 4, 20, 15};
    int k;
    cout << "Enter k: ";
    cin >> k;
    cout << "K-th smallest element is: " << kThSmallestELement(input, k) << endl;

    return 0;
}