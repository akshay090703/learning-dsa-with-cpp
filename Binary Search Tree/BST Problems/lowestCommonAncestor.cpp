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

int lowestCommonAncestor(Node *root, int node1, int node2)
{
    if (!root)
    {
        return -1;
    }

    if ((root->data > node1 && root->data > node2))
    {
        return lowestCommonAncestor(root->left, node1, node2);
    }
    else if (root->data < node1 && root->data < node2)
    {
        return lowestCommonAncestor(root->right, node1, node2);
    }

    return root->data;
}

// if we do the same procedure iteratively, we can also save the space

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

    int element1, element2;
    cout << "\nEnter the elements to find the lowest common ancestor: ";
    cin >> element1 >> element2;

    cout << "The Lowest Common Ancestor for the two nodes is: ";
    cout << lowestCommonAncestor(tree.root, element1, element2) << endl;

    return 0;
}