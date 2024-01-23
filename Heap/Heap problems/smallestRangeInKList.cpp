#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int value;
    int pos;
    int vec;

    Node(int value, int pos, int vec)
    {
        this->value = value;
        this->pos = pos;
        this->vec = vec;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->value > b->value; // for minHeap
    }
};

// Time Complexity -> O(klogk) + O(n*k*logk) ~ O(n*k*log(k))
// Space Complexity -> O(k)
int kSorted(vector<vector<int>> &a, int k, int n)
{
    if (k <= 0)
        return -1;

    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int range1 = INT_MAX;
    int range2 = INT_MIN;

    // step1: creating a min heap for starting element of all list and tracking min and max element
    for (int i = 0; i < k; i++)
    {
        Node *new_node = new Node(a[i][0], 0, i);
        minHeap.push(new_node);
        range2 = max(range2, new_node->value);
    }
    range1 = min(range1, minHeap.top()->value);
    int start = range1, end = range2;

    // processing ranges
    while (!minHeap.empty())
    {
        Node *mini = minHeap.top();
        int i = mini->vec;
        int j = mini->pos;
        minHeap.pop();

        // min range fetched
        range1 = mini->value;

        // if the new less is greater than the old distance, then change
        if (range2 - range1 < end - start)
        {
            start = range1;
            end = range2;
        }

        // if next element exists(from the smallest element) and setting it as range2 and pushing into heap
        if (j + 1 < n)
        {
            Node *new_node = new Node(a[i][j + 1], j + 1, i);
            minHeap.push(new_node);
            range2 = max(range2, a[i][j + 1]);
        }
        else
            break;
    }

    // returning the difference in ranges of value
    return (end - start + 1);
}

int main()
{
    // vector<vector<int>> listArray = {{2, 4, 5}, {5, 6, 7}};
    vector<vector<int>> listArray = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
    // vector<vector<int>> listArray = {{1, 1}, {9, 12}, {4, 9}};
    // vector<vector<int>> listArray = {{1, 2, 12}, {4, 7, 30}, {20, 40, 50}};
    int n = listArray[0].size();
    int k = listArray.size();
    cout << "The smallest range in k sorted linked lists is: ";
    cout << kSorted(listArray, k, n) << endl;

    return 0;
}