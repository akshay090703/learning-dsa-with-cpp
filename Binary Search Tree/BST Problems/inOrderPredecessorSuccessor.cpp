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
    if (root == NULL)
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
    // base case
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // we have insert into the right subtree
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // we have to insert into the left subtree
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

Node *searchInBST(Node *root, int key)
{
    Node *curr = root;

    while (curr)
    {
        if (key == curr->data)
            return curr;

        if (key > curr->data)
            curr = curr->right;

        if (key < curr->data)
            curr = curr->left;
    }

    return nullptr;
}

// It is the node with the largest value that is smaller than the
// keyNode value -> left subtree largest value
// Time Complexity -> O(height) ~ O(n)
// Space Complexity -> O(1)
Node *inOrderPredecessor(Node *root, int key)
{
    Node *keyNode = searchInBST(root, key);
    if (!keyNode)
        return nullptr;

    // if node has a left subtree
    if (keyNode->left)
    {
        Node *temp = keyNode;
        temp = temp->left;
        while (temp->right)
        {
            temp = temp->right;
        }
        return temp;
    }

    // if node does not have a left subtree
    Node *predecessor = nullptr;
    while (root)
    {
        if (root->data < key)
        {
            predecessor = root;
            root = root->right;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            break; // we have found the answer
        }
    }

    return predecessor;
}

// It is the smallest node value that is larger than the keyNode value
// -> smallest node in right subtree
// Time Complexity -> O(height) ~ O(n)
// Space Complexity -> O(1)
Node *inOrderSuccessor(Node *root, int key)
{
    Node *keyNode = searchInBST(root, key);
    if (!keyNode)
        return nullptr;

    // if node has a right subtree
    if (keyNode->right)
    {
        Node *temp = keyNode;
        temp = temp->right;
        while (temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    // if node does not have a right subtree
    Node *successor = nullptr;
    while (root)
    {
        if (root->data > key)
        {
            successor = root;
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            break; // we have found the answer
        }
    }

    return successor;
}

pair<int, int> predecessorSuccessor(Node *root, int key)
{
    Node *predecessor = inOrderPredecessor(root, key);
    Node *successor = inOrderSuccessor(root, key);
    int preValue = (predecessor) ? predecessor->data : -1;
    int sucValue = (successor) ? successor->data : -1;
    pair<int, int> result = {preValue, sucValue};
    return result;
}

int main()
{
    BinarySearchTree tree;
    // 21 10 50 5 15 40 60 35 70 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "\nInOrder Traversal in BST: ";
    inOrderTraversal(tree.root);

    int element;
    cout << "\nEnter the element to find the inOrder Predecessor and Successor: ";
    cin >> element;

    pair<int, int> ans = predecessorSuccessor(tree.root, element);
    cout << "The inOrder Predecessor and Successor are: ";
    cout << ans.first << " " << ans.second << endl;

    return 0;
}