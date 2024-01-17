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
// Space Complexity -> O(h) ~ O(n)
pair<bool, int> isSum(Node *root)
{
    if (!root)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (!root->left && !root->right)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    pair<bool, int> ans;
    if (left.first && right.first && (left.second + right.second == root->data))
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = 0;
    }
    return ans;
}

bool isCheckSumTree(Node *root)
{
    return isSum(root).first;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    string ans = isCheckSumTree(tree.root) ? "Check Sum tree." : "Not a Check Sum tree.";
    cout << "\nGiven tree is: " << ans << endl;

    return 0;
}