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

// Using Recursion
// Time Complexity -> O(n)
// Space Complexity -> O(h) ~ O(n)
void inOrderTraversal(Node *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node *findPredecessor(Node *curr)
{
    Node *temp = curr->left;

    // temp->right != curr to prevent a infinite cycle
    while (temp->right && temp->right != curr)
    {
        temp = temp->right;
    }
    return temp;
}

// Using Morris Traversal
// Time Complexity -> O(n)
// Space Complexity -> O(1)
void morrisInOrderTraversal(Node *root)
{
    Node *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->right)
            {
                // temp link added
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                // temp link removed
                predecessor->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 5 -1 6 -1 7 -1 -1 -1 -1 -1 -1
    // answer: 4 7 2 5 1 3 6

    cout << "\nIn Order Traversal using Recursion: ";
    inOrderTraversal(tree.root);

    cout << "\nInOrder Traversal using Morris Traversal: ";
    morrisInOrderTraversal(tree.root);

    return 0;
}