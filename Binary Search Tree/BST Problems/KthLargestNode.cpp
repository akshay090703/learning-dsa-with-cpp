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
void solve(Node *root, int &k, int &ans)
{
    if (!root)
        return;

    solve(root->right, k, ans);
    k--;
    if (!k)
        ans = root->data;
    solve(root->left, k, ans);
}

int kThLargestElement(Node *root, int k)
{
    int ans = -1;
    solve(root, k, ans);
    return ans;
}

int lengthOfBST(Node *root)
{
    if (!root)
        return 0;

    return lengthOfBST(root->left) + lengthOfBST(root->right) + 1;
}

// Using Morris Traversal
// Time Complexity -> O(n)
// Space Complexity -> O(1)
Node *findPredecessor(Node *root)
{
    Node *temp = root;
    temp = temp->right;
    while (temp->left && temp->left != root)
    {
        temp = temp->left;
    }
    return temp;
}

// Here we are doing the reverse morris traversal and traversing the BST
// in decreasing order
int KthLargestMorrisTraversal(Node *root, int k)
{
    Node *curr = root;
    int size = 0;
    int kthLargest = -1;

    while (curr)
    {
        if (!curr->right)
        {
            k--;
            if (!k)
            {
                kthLargest = curr->data;
                break;
            }
            curr = curr->left;
        }
        else
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->left)
            {
                predecessor->left = curr;
                curr = curr->right;
            }
            else
            {
                predecessor->left = nullptr;
                k--;
                if (!k)
                {
                    kthLargest = curr->data;
                    break;
                }
                curr = curr->left;
            }
        }
    }
    return kthLargest;
}

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

    cout << "The Kth largest element in the BST is: ";
    // cout << kThLargestElement(tree.root, k) << endl;
    cout << KthLargestMorrisTraversal(tree.root, k) << endl;

    return 0;
}