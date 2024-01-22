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

// Not needed
int countNodes(Node *root, int i = 0)
{
    if (!root)
    {
        return 0;
    }

    int leftAns = countNodes(root->left, i);
    int rightAns = countNodes(root->right, i);

    return leftAns + rightAns + 1;
}

pair<bool, int> solveCBT(Node *root, pair<bool, int> p)
{
    if (!root)
        return {true, 0};

    bool isCBT = p.first;
    int height = p.second;

    pair<bool, int> leftAns = solveCBT(root->left, p);
    pair<bool, int> rightAns = solveCBT(root->right, p);

    isCBT = abs(leftAns.second - rightAns.second) <= 1;
    height = leftAns.second + rightAns.second + 1;
    return {isCBT, height};
}

bool isValidCBT(Node *root)
{
    pair<bool, int> ans = solveCBT(root, {true, 0});
    return ans.first;
}

bool isMaxOrder(Node *root)
{
    if (!root)
        return true;

    if (!root->left && !root->right)
    {
        return true;
    }
    else if (root->left && !root->right)
    {
        return (root->data >= root->left->data);
    }

    bool leftAns = isMaxOrder(root->left);
    bool leftSubTreeCheck = (root->data >= root->left->data);
    bool rightAns = isMaxOrder(root->right);
    bool rightSubTreeCheck = (root->data >= root->right->data);

    return leftSubTreeCheck && rightSubTreeCheck && leftAns && rightAns;
}

// Time Complexity -> O(n)
// Space Complexity -> O(height) ~ O(n)
bool isMaxHeap(Node *root)
{
    if (isValidCBT(root) && isMaxOrder(root))
        return true;

    return false;
}

// Youtube Approach
bool isCBTYoutube(Node *root, int i, int totalCount)
{
    if (!root)
        return true;

    if (i >= totalCount)
        return false;
    else
    {
        bool left = isCBTYoutube(root->left, (2 * i) + 1, totalCount);
        bool right = isCBTYoutube(root->right, (2 * i) + 2, totalCount);
        return left && right;
    }
}

bool isMaxOrderYoutube(Node *root)
{
    if (!root->left && !root->right)
        return true;

    if (!root->right)
    {
        return root->data > root->left->data;
    }
    else
    {
        bool left = isMaxOrderYoutube(root->left);
        bool right = isMaxOrderYoutube(root->right);

        return left && right && (root->data > root->left->data && root->data > root->right->data);
    }
}

// Time Complexity -> O(n+n+n) ~ O(n)
// Space Complexity -> O(height + height) ~ O(height)
bool isHeapYoutube(Node *root)
{
    int index = 0;
    int totalCount = countNodes(root);
    if (isCBTYoutube(root, index, totalCount) && isMaxOrderYoutube(root))
    {
        return true;
    }
    return false;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "Total Number of nodes: ";
    cout << countNodes(tree.root) << endl;

    // string ans = isMaxHeap(tree.root) ? "Max Heap." : "Not a Max Heap!";
    string ans = isHeapYoutube(tree.root) ? "Max Heap." : "Not a Max Heap!";
    cout << ans << endl;

    return 0;
}