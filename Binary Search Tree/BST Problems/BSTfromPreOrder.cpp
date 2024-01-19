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

Node *solve(vector<int> &input, int &i, int &n, int min = INT_MIN, int max = INT_MAX)
{
    if (i >= n || input[i] < min || input[i] > max)
    {
        return nullptr;
    }

    Node *newNode = new Node(input[i]);
    i++;

    newNode->left = solve(input, i, n, min, newNode->data);
    newNode->right = solve(input, i, n, newNode->data, max);

    return newNode;
}

// Time Complexity -> O(n)
// Space Complexity -> O(height) ~ O(n)
Node *BSTfromPreOrder(vector<int> &input)
{
    int n = input.size();
    Node *root = nullptr;
    int i = 0;
    root = solve(input, i, n);
    return root;
}

int main()
{
    BinarySearchTree tree;
    // 10 8 12 4 16 2 20 -1

    vector<int> input = {20, 10, 5, 15, 13, 35, 30, 42};
    tree.root = BSTfromPreOrder(input);

    cout << "The formed BST from preOrder traversal is: \n";
    levelOrderTraversal(tree.root);

    cout << "\ninOrder Traversal: ";
    inOrderTraversal(tree.root);

    return 0;
}