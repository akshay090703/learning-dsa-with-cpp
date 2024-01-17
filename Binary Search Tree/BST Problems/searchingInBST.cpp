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

// Time Complexity -> O(log(n)) or O(height)
// Space Complexity -> O(height) ~ O(n)
// Using Binary Search and recursion
bool searchInBST(Node *root, int key)
{
    if (!root)
        return false;

    if (root->data == key)
        return true;

    if (root->data < key)
    {
        return searchInBST(root->right, key);
    }
    else
    {
        return searchInBST(root->left, key);
    }
}

// To optimize it further, we can do this iteratively, in that case our
// space complexity can be constant
// Iterative method (optimized)
// Time Complexity -> O(log(n)) or O(height)
// Space Complexity -> O(1)
bool searchInBSTIteratively(Node *root, int key)
{
    Node *temp = root;

    while (temp)
    {
        if (temp->data == key)
            return true;

        if (temp->data < key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return false;
}

int main()
{
    BinarySearchTree tree;
    // 21 10 50 5 15 40 60 35 70 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "Enter the node to be searched: ";
    int key;
    cin >> key;

    // string ans = searchInBST(tree.root, key) ? "Present." : "Not Present!";
    string ans = searchInBSTIteratively(tree.root, key) ? "Present." : "Not Present!";
    cout << "Given node is " << ans << endl;

    return 0;
}