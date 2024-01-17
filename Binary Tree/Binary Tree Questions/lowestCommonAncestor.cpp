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
// Space Complexity -> O(height) {in case of skew tree, height = n}
Node *lowestCommonAncestor(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftAns = lowestCommonAncestor(root->left, n1, n2);
    Node *rightAns = lowestCommonAncestor(root->right, n1, n2);

    if (leftAns && rightAns)
        return root;
    else if (leftAns && !rightAns)
        return leftAns;
    else if (!leftAns && rightAns)
        return rightAns;

    return nullptr;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 4 2 5 7 1 2 3 -1 -1 6 -1 -1 -1 -1 -1 -1 -1
    // answer: 13

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    int n1, n2;
    cout << "\nGive the value of 2 nodes: ";
    cin >> n1 >> n2;

    cout << "The lowest common ancestor in the binary tree is: " << lowestCommonAncestor(tree.root, n1, n2)->data << endl;

    return 0;
}