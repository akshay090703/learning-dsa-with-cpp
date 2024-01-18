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

// Recursion Approach
// Time Complexity -> O(n)
// Space Complexity -> O(height) ~ O(n)
void solve(Node *root, int k, int &ans, int &i)
{
    if (!root)
        return;

    solve(root->left, k, ans, i);
    i++;
    if (i == k)
        ans = root->data;
    solve(root->right, k, ans, i);
}

int kThSmallestElement(Node *root, int k)
{
    int ans = -1;
    int i = 0;
    solve(root, k, ans, i);
    return ans;
}

// To optimize further, we can use Morris Traversal
// Time Complexity -> O(n)
// Space Complexity -> O(1) // optimized
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

int KthSmallestMorrisTraversal(Node *root, int k)
{
    Node *curr = root;

    while (curr)
    {

        if (!curr->left)
        {
            k--;
            if (!k)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->right)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = nullptr;
                k--;
                if (!k)
                    return curr->data;
                curr = curr->right;
            }
        }
    }

    return -1;
}

// To find the Kth Largest element, we can just find the (n-k+1)
// smallest element and that will be the kth largest element

int main()
{
    BinarySearchTree tree;
    // 5 4 8 2 6 10 3 7 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    int k;
    cout << "\nEnter value of k: ";
    cin >> k;

    cout << "The Kth smallest element in the BST is: ";
    // cout << kThSmallestElement(tree.root, k) << endl;
    cout << KthSmallestMorrisTraversal(tree.root, k) << endl;

    return 0;
}