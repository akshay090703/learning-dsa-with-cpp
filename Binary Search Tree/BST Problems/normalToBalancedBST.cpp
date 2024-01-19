#include <iostream>
#include <queue>
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

struct BinarySearchTree
{
    Node *root;

    BinarySearchTree()
    {
        root = nullptr;
    }
};

void levelOrderTraversal(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
}

Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
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

void inOrderVector(Node *root, vector<Node *> &v)
{
    if (!root)
        return;

    inOrderVector(root->left, v);
    v.push_back(root);
    inOrderVector(root->right, v);
}

Node *solve(vector<Node *> &v, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + ((end - start) / 2);

    v[mid]->left = solve(v, start, mid - 1);
    v[mid]->right = solve(v, mid + 1, end);

    return v[mid];
}

// Time Complexity -> O(n + n) ~ O(n)
// Space Complexity -> O(n + height) ~ O(n)
Node *normalToBalancedBST(Node *root)
{
    vector<Node *> in;
    inOrderVector(root, in);
    int n = in.size();
    Node *new_root = solve(in, 0, n - 1);

    return new_root;
}

int main()
{
    BinarySearchTree tree;
    // 10 8 12 4 16 2 20 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "\nThe inOrder traversal of BST: ";
    inOrderTraversal(tree.root);

    tree.root = normalToBalancedBST(tree.root);
    cout << "\nThe converted Balanced BST looks like: \n";
    levelOrderTraversal(tree.root);

    return 0;
}