#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// My Approach
// in the input all the vectors are of n size and are sorted
// let m = n*k as n*k are all the elements in all the vectors combined
// Time Complexity -> O(n*k*log(n*k)) ~ O(m(log(m)));
// Space Complexity -> O(n*k) ~ O(m)
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < kArrays.size(); i++)
    {
        for (int j = 0; j < kArrays[i].size(); j++)
        {
            minHeap.push(kArrays[i][j]);
        }
    }

    vector<int> ans;

    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}

// Youtube Approach
struct Node
{
    int data;
    int vec;
    int element;

    Node(int data, int vec, int element)
    {
        this->data = data;
        this->vec = vec;
        this->element = element;
    }
};

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// Time Complexity -> O(n*k*log(k))
// Space Complexity -> O(n*k)
vector<int> mergeKSarrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // step1: insert all k arrays first element
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step2
    while (minHeap.size() > 0)
    {
        Node *first = minHeap.top();
        ans.push_back(first->data);
        minHeap.pop();

        int i = first->vec;
        int j = first->element;

        if (j + 1 < kArrays[i].size())
        {
            Node *next = new Node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

void printArray(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    vector<vector<int>> v = {{1, 5, 9}, {45, 90}, {2, 6, 78, 100, 234}, {0}};

    cout << "The merged array from k sorted arrays is: \n";
    vector<int> ans = mergeKSortedArrays(v);
    printArray(ans);

    return 0;
}