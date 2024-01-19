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

void inOrder(Node *root, vector<Node *> &in)
{
    if (!root)
        return;

    inOrder(root->left, in);
    in.push_back(root);
    inOrder(root->right, in);
}

// Not so optimized approach using vector
// Time Complexity -> O(n)
// Space Complexity -> O(n)
Node *flattenBST(Node *root)
{
    vector<Node *> in;
    inOrder(root, in);
    int n = in.size();

    for (int i = 0; i < n - 2; i++)
    {
        in[i]->right = in[i + 1];
        in[i]->left = nullptr;
    }
    in[n - 1]->right = nullptr;
    in[n - 1]->left = nullptr;

    return in[0];
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

// Using Morris Traversal
// Time Complexity -> O(n)
// Space Complexity -> O(1) (Optimized)
Node *flattenBSTtoSortedLL(Node *root)
{
    Node *curr = root;
    Node *head = nullptr;
    Node *prev = nullptr;

    while (curr)
    {
        if (curr->left)
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->right)
            {
                predecessor->right = curr;
                Node *temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
            else
            {
                if (!head)
                    head = curr;

                if (prev)
                    prev->right = curr;

                prev = curr;
                curr = curr->right;
            }
        }
        else
        {
            if (!head)
                head = curr;

            if (prev)
                prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
    }

    return head;
}

void printList(Node *root)
{
    Node *current = root;
    while (current)
    {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main()
{
    BinarySearchTree tree;
    // 4 2 6 1 3 5 7 -1
    // answer: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL
    // left wale all null

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "\nThe inOrder traversal of BST: ";
    inOrderTraversal(tree.root);

    // tree.root = flattenBSTtoSortedLL(tree.root);
    // cout << "\nFlattened BST in sorted LL format(Optimized) is : ";
    // printList(tree.root);

    tree.root = flattenBST(tree.root);
    cout << "\nFlattened BST in sorted LL format(Not Optimized) is : ";
    printList(tree.root);

    return 0;
}