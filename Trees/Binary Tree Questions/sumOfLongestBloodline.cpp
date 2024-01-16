#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

struct BinaryTree
{
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }
};

void buildingBTLevelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the data for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << "Enter the data for the left of " << current->data << ": ";
        cin >> data;
        if (data != -1)
        {
            current->left = new Node(data);
            q.push(current->left);
        }

        cout << "Enter the data for the right of " << current->data << ": ";
        cin >> data;
        if (data != -1)
        {
            current->right = new Node(data);
            q.push(current->right);
        }
    }
}

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Iterative Method
// Time and Space Complexity -> O(n) and O(width) respectively
// My approach
int sumOfLongestBloodline(Node *root)
{
    queue<pair<Node *, pair<int, int>>> q;
    // first is the node and second is the number of ancestor nodes by now and sum of the ancestors by now

    int maxSum = 0;
    if (!root)
        return maxSum;

    q.push({root, {1, root->data}});

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int numberOfAncestorsByNow = temp.second.first;
        int sumAncestorsNow = temp.second.second;

        maxSum = max(maxSum, sumAncestorsNow);

        if (frontNode->left)
        {
            q.push({frontNode->left, {numberOfAncestorsByNow + 1, sumAncestorsNow + frontNode->left->data}});
        }

        if (frontNode->right)
        {
            q.push({frontNode->right, {numberOfAncestorsByNow + 1, sumAncestorsNow + frontNode->right->data}});
        }
    }

    return maxSum;
}

// Recursive Approach
// Time Complexity -> O(n)
// Space Complexity -> O(height)
void solve(Node *root, pair<int, int> &ans, pair<int, int> curr = {0, 0})
{
    if (!root)
    {
        if (curr.first >= ans.first)
        {
            ans.first = curr.first;
            if (curr.second >= ans.second)
                ans.second = curr.second;
        }
        return;
    }

    curr.first += root->data;
    curr.second++;

    solve(root->left, ans, curr);
    solve(root->right, ans, curr);
}

int longestBloodlineSum(Node *root)
{
    pair<int, int> ans = {0, 0};
    // first -> maxSum & second -> number od ancestors
    solve(root, ans);
    return ans.first;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1
    // answer: 13

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    // cout << "\nMaximum sum of the longest bloodline is: " << sumOfLongestBloodline(tree.root) << endl;
    cout << "\nMaximum sum of the longest bloodline is: " << longestBloodlineSum(tree.root) << endl;

    return 0;
}