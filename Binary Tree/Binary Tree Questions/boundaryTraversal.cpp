#include <iostream>
#include <queue>
#include <stack>
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

// Approach:
// 1. Print the left nodes except the left leaf node
// 2. Print all the leaf node
// 3. Print all the right nodes except root and right leaf node

void traverseLeft(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeafNodes(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeafNodes(root->left, ans);
    traverseLeafNodes(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // as we want reverse order
    ans.push_back(root->data);
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)
vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    ans.push_back(root->data);

    // 1. left part
    traverseLeft(root->left, ans);

    // 2. Leaf Node part
    // for left subtree
    traverseLeafNodes(root->left, ans);

    // for right subtree
    traverseLeafNodes(root->right, ans);

    // 3. Right part
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nBoundary Traversal: ";
    vector<int> res = boundaryTraversal(tree.root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}