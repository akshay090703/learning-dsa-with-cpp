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

Node *findPredecessor(Node *curr)
{
    Node *temp = curr;
    temp = temp->left;
    while (temp->right && temp->right != curr)
    {
        temp = temp->right;
    }
    return temp;
}

// basically here the output here is that we need to convert the tree into
// a linked list in constant space, means we have to use Morris traversal
// traversal and we need the LL in pre order traversal order

// Time Complexity -> O(n)
// Space Complexity -> O(1)
Node *flattenTreeIntoLL(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            Node *predecessor = findPredecessor(curr);

            predecessor->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
    return root;
}

void printLL(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void morrisPreOrderTraversal(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        cout << curr->data << " ";

        if (!curr->left)
        {
            curr = curr->right;
        }
        else
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->right)
            {
                predecessor->right = curr->right; // to get preorder output
                curr = curr->left;
            }
            else
            {
                predecessor->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 5 3 4 -1 6 -1 -1 -1 -1 -1 -1
    // answer: 1 2 3 4 5 6

    cout << "\nPre Order Traversal: ";
    preOrderTraversal(tree.root);

    // cout << "\nPre Order Traversal using Morris Traversal: ";
    // morrisPreOrderTraversal(tree.root);

    Node *headOfLL = flattenTreeIntoLL(tree.root);
    cout << "\nThe flattened tree into Linked List: ";
    printLL(headOfLL);

    return 0;
}