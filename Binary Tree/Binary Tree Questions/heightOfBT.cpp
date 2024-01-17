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

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// My approach
// Time and Space Complexity -> O(n)
int heightOfBT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    int h = 0;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        if (current == nullptr)
        {
            h++;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (current->left)
            {
                q.push(current->left);
            }

            if (current->right)
            {
                q.push(current->right);
            }
        }
    }
    return h;
}

// Youtube's approach: Recursion
// Time Complexity -> O(n)
// Space Complexity -> O(height), in worst O(n) when skew tree (only left or only right)
int height(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nThe height of the binary tree is: " << heightOfBT(tree.root) << endl;
    cout << "The height of the binary tree is: " << height(tree.root) << endl;

    return 0;
}