#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time Complexity -> ((n^2)*log(k))
// where log(k) is the time complexity of minHeap operation (push)
// Space Complexity -> O(k)
int kThLargestSumSubArray(vector<int> &input, int k)
{
    int n = input.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += input[j];
            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            else
            {
                if (minHeap.top() < sum)
                {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "The kth largest sum of subarray in the given array is: ";
    cout << kThLargestSumSubArray(v, 3) << endl;

    return 0;
}