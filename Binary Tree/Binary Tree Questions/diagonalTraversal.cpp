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

// Time Complexity -> O(n)
// Space Complexity -> O(n)
// map takes O(width) space same as queue which in worst case will be O(n)
// Iterative approach
vector<int> diagonalView(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, vector<int>> m;
    // first value is the diagonal number and second is the vector with diagonal nodes

    queue<pair<int, Node *>> q;
    // first value is the diagonal number and second is the current node

    q.push(make_pair(1, root));

    while (!q.empty())
    {
        pair<int, Node *> temp = q.front();
        q.pop();

        int diagonal = temp.first;
        Node *frontNode = temp.second;

        m[diagonal].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(diagonal + 1, frontNode->left));
        }

        if (frontNode->right)
        {
            q.push(make_pair(diagonal, frontNode->right));
        }
    }

    for (auto i : m)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }

    return ans;
}

// Recursive approach
// Space and Time Complexity -> O(n)
void solve(Node *root, int diagonal, map<int, vector<int>> &m)
{
    if (!root)
        return;

    m[diagonal].push_back(root->data);

    solve(root->left, diagonal + 1, m);
    solve(root->right, diagonal, m);
}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int, vector<int>> m;
    solve(root, 1, m);

    for (auto i : m)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    // answer: 8 10 14 3 6 7 13 1 4

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nDiagonal Traversal of the Binary Tree: ";
    // vector<int> res = diagonalView(tree.root);
    vector<int> res = diagonal(tree.root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}