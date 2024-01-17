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

// Recursive Approach
// pair<a, b>
// a -> maxSum by including all nodes at current level
// b -> maxSum by excluding all nodes at current level

// Time Complexity -> O(n)
// Space Complexity -> O(height)
pair<int, int> maxSumOfNonAdjacentNodes(Node *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> leftAns = maxSumOfNonAdjacentNodes(root->left);
    pair<int, int> rightAns = maxSumOfNonAdjacentNodes(root->right);

    return {root->data + leftAns.second + rightAns.second, max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second)};
}

int getAnswer(Node *root)
{
    pair<int, int> ans = maxSumOfNonAdjacentNodes(root);
    return max(ans.first, ans.second);
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
    // answer: 16

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nThe maximum sum of nodes is: ";
    cout << getAnswer(tree.root) << endl;

    return 0;
}