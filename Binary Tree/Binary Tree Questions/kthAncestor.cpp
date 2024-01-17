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
void findPathUntil(Node *root, int node, vector<int> &path)
{
    if (!root)
        return;

    if (root->data == node)
    {
        path.push_back(root->data);
        return;
    }
    else
    {
        path.push_back(root->data);
        findPathUntil(root->left, node, path);
        if (!path.empty() && path.back() == node)
            return;

        findPathUntil(root->right, node, path);
        if (!path.empty() && path.back() == node)
            return;
    }

    path.pop_back();
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    findPathUntil(root, node, path);

    if (path.size() < k)
    {
        return -1;
    }

    return path[path.size() - (k + 1)];
}

// youtube approach
Node *solve(Node *root, int &k, int node)
{
    if (!root)
        return nullptr;

    if (root->data == node)
        return root;

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns && !rightAns)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root; // answer locked as by decrementing k will not get 0
        }
        return leftAns;
    }

    if (!leftAns && rightAns)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root; // answer locked as by decrementing k will not get 0
        }
        return rightAns;
    }

    return nullptr;
}

int kAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (!ans || ans->data == node)
        return -1;
    else
        return ans->data;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1
    // answer: 1

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    int node;
    cout << "\nEnter the node from which you want to find: ";
    cin >> node;

    int k;
    cout << "Enter the number of ancestor you want to find: ";
    cin >> k;

    // cout << "The kth ancestor from the given node is: ";
    // cout << kthAncestor(tree.root, k, node) << endl;

    cout << "The kth ancestor from the given node is: ";
    cout << kAncestor(tree.root, k, node) << endl;

    return 0;
}