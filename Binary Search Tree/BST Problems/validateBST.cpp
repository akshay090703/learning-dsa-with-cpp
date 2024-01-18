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

Node *buildingTreeLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    cout << "Enter the value for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << "Data at left of " << current->data << ": ";
        int temp;
        cin >> temp;
        if (temp != -1)
        {
            current->left = new Node(temp);
            q.push(current->left);
        }

        cout << "Data at right of " << current->data << ": ";
        cin >> temp;
        if (temp != -1)
        {
            current->right = new Node(temp);
            q.push(current->right);
        }
    }

    return root;
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

// Time Complexity -> O(n)
// Space Complexity -> O(height) ~ O(n) (in case of skew tree)
bool isBST(Node *root, int min, int max)
{
    if (!root)
        return true;

    if (min > root->data || root->data > max)
        return false;
    else
    {
        bool leftAns = isBST(root->left, min, root->data);
        bool rightAns = isBST(root->right, root->data, max);
        return leftAns && rightAns;
    }
}

bool validateBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
    BinarySearchTree tree;
    // 4 2 5 1 4 -1 -1 -1 -1 -1 -1

    tree.root = buildingTreeLevelOrderTraversal(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    string ans = validateBST(tree.root) ? "Valid BST." : "Non valid BST!";
    cout << "The given tree is: " << ans << endl;

    return 0;
}