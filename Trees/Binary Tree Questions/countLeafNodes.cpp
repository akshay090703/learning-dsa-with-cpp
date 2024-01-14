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

Node *buildingTreeLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    cout << "Enter the value for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << "Data at left of " << current->data << ": ";
        int temp;
        cin >> temp;
        if (temp != -1)
        {
            current->left = new Node(temp);
            q.push(current->left);
        }

        cout << "Data at right of " << current->data << ": ";
        cin >> temp;
        if (temp != -1)
        {
            current->right = new Node(temp);
            q.push(current->right);
        }
    }

    return root;
}

// Using InOrder Traversal
// Time And Space Complexity -> O(n)
void countLeafNodes(Node *root, int &count)
{
    if (!root)
        return;

    countLeafNodes(root->left, count);

    if (!root->left && !root->right)
    {
        count++;
    }

    countLeafNodes(root->right, count);
}

int main()
{
    BinaryTree tree;

    tree.root = buildingTreeLevelOrderTraversal(tree.root);

    int count = 0;
    countLeafNodes(tree.root, count);
    cout << "Number of leaf nodes in the tree: " << count << endl;

    return 0;
}