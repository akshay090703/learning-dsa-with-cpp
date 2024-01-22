#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

// Here the BST is a complete BT
// here i think the inOrder traversal of complete BST is equal to preorder traversal of minHeap
// We have a CBT in input so we don't have to change the structure of the tree
// we only have to change the values
void convertBSTVector(Node *root, vector<int> &inOrder)
{
    if (!root)
        return;

    convertBSTVector(root->left, inOrder);
    inOrder.push_back(root->data);
    convertBSTVector(root->right, inOrder);
}

void vectorToMinheap(Node *&root, vector<int> &inOrder, int &index)
{
    if (!root)
        return;

    root->data = inOrder[index++];
    vectorToMinheap(root->left, inOrder, index);
    vectorToMinheap(root->right, inOrder, index);
}

// Time Complexity -> O(n + n) ~ O(n)
// Space Complexity -> O(n)
void convertBSTtoMinheap(Node *&root)
{
    vector<int> inOrder;
    convertBSTVector(root, inOrder);
    int n = inOrder.size();
    int i = 0;
    vectorToMinheap(root, inOrder, i);
}

int main()
{
    BinarySearchTree tree;
    cout << "Give input to construct BST: ";
    takeInput(tree.root);
    // 4 2 6 1 3 5 7 -1

    cout << "The BST looks like: \n";
    levelOrderTraversal(tree.root);

    convertBSTtoMinheap(tree.root);
    cout << "\nAfter converting it to MinHeap: \n";
    levelOrderTraversal(tree.root);

    return 0;
}