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

int heightOfBT(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Time Complexity -> O(n^2)
// Space Complexity -> O(n*h)
bool isBalancedOrNot(Node *root)
{
    if (!root)
    {
        return true;
    }

    bool left = isBalancedOrNot(root->left);
    bool right = isBalancedOrNot(root->right);

    bool diff = abs(heightOfBT(root->left) - heightOfBT(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    return false;
}

// optimized approach
// Here we are making a pair for each node where first node will tell if it is balanced or not
// and second will give the max height for that particular node
// Time Complexity -> O(n)
// Space Complexity -> O(n)
pair<bool, int> optimizedIsBalanced(Node *root)
{
    if (!root)
    {
        pair<bool, int> ans = make_pair(true, 0);
        return ans;
    }

    pair<bool, int> left = optimizedIsBalanced(root->left);
    pair<bool, int> right = optimizedIsBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isBalanced(Node *root)
{
    return optimizedIsBalanced(root).first;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "\nPre Order Traversal: ";
    preOrderTraversal(tree.root);

    // string ans = isBalancedOrNot(tree.root) ? "Balanced!" : "Not Balanced!";
    string ans = isBalanced(tree.root) ? "Balanced!" : "Not Balanced!";
    cout << "\nBinary Tree is " << ans << endl;

    return 0;
}