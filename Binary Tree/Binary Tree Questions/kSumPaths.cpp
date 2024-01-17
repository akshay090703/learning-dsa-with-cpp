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
// Time Complexity -> O(n)
// Space Complexity -> O(height)
void solve(Node *root, int k, int &count, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}

int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    //
    // answer:

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    int k;
    cout << "\nEnter the sum that you want you find: ";
    cin >> k;

    cout << "The number of times the sum of nodes is k: ";
    cout << sumK(tree.root, k) << endl;

    return 0;
}