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

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// Time Complexity -> O(height) ~ O(n)
// Space Complexity -> O(1)
int minValBST(Node *root)
{
    Node *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}

// Time Complexity -> O(height) ~ O(n)
// Space Complexity -> O(1)
int maxValBST(Node *root)
{
    Node *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Time Complexity -> O(n)
// in avg case -> O(height)
// Space Complexity -> O(height) ~ O(n) {worst}
Node *deletingNodeInBST(Node *root, int key)
{
    if (!root)
        return root;

    if (root->data == key)
    {
        // deleting the leaf node (0 child)
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        // i) Left Child
        if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // ii) Right Child
        if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 Childs
        if (root->left && root->right)
        {
            int mini = minValBST(root->right); // minimum value from right subtree -> inOrder Successor
            // we can also achieve the same with maximum value from left subtree -> inOrder Predecessor
            root->data = mini;
            root->right = deletingNodeInBST(root->right, mini);
            return root;
        }
    }

    else if (root->data > key)
    {
        root->left = deletingNodeInBST(root->left, key);
    }
    else
    {
        root->right = deletingNodeInBST(root->right, key);
    }
    return root;
}

int main()
{
    BinarySearchTree tree;
    // 21 10 50 5 15 40 60 35 70 -1
    // 70 60 90 50 65 40 64 67 -1
    // 50 20 70 10 30 90 110 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "\nInOrder Traversal in BST: ";
    inOrderTraversal(tree.root);

    cout << "\nPreOrder Traversal in BST: ";
    preOrderTraversal(tree.root);

    cout << "\nPostOrder Traversal in BST: ";
    postOrderTraversal(tree.root);

    cout << "\nThe maximum and minimum values in the BST is: ";
    cout << minValBST(tree.root) << " " << maxValBST(tree.root) << endl;

    cout << "Enter the node value to be deleted: ";
    int delKey;
    cin >> delKey;
    tree.root = deletingNodeInBST(tree.root, delKey);
    cout << "The BST after deleting node: \n";
    levelOrderTraversal(tree.root);

    cout << "\nInOrder Traversal in BST after deleting: ";
    inOrderTraversal(tree.root);

    return 0;
}