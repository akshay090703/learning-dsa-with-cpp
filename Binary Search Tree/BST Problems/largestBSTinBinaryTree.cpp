#include <iostream>
#include <queue>
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

void inOrderTraversal(Node *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

struct info
{
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node *root, int &maxSize)
{
    if (!root)
        return {INT_MIN, INT_MAX, true, 0};

    info leftAns = solve(root->left, maxSize);
    info rightAns = solve(root->right, maxSize);

    info currNode;

    currNode.size = leftAns.size + rightAns.size + 1;
    currNode.maxi = max(root->data, rightAns.maxi);
    currNode.mini = min(root->data, leftAns.mini);

    if (leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxi && root->data < rightAns.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if (currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }

    return currNode;
}

// Time Complexity -> O(n)
// Space Complexity -> O(height) ~ O(n)
int maxBSTinBinaryTree(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 5 2 4 1 3 -1 -1 -1 -1 -1 -1
    // answer: 3

    cout << "\nIn Order Traversal: ";
    inOrderTraversal(tree.root);

    cout << "\nThe largest BST in the Binary tree is: ";
    cout << maxBSTinBinaryTree(tree.root) << endl;

    return 0;
}