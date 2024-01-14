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
// Space Complexity -> O(n^2)
int maxDiameter(Node *root)
{
    if (!root)
        return 0;

    int leftDiameter = maxDiameter(root->left);
    int rightDiameter = maxDiameter(root->right);
    int combination = heightOfBT(root->left) + 1 + heightOfBT(root->right);

    return max(combination, max(leftDiameter, rightDiameter));
}

// optimized version
// here we are calculating both the diameter and height at the same time and storing it in pair
// Time Complexity -> O(n)
// Space Complexity -> O(n)
pair<int, int> diameterFast(Node *root)
{
    if (!root)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int diameter(Node *root)
{
    return diameterFast(root).first;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "\nPre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nThe maximum diameter is: ";
    cout << maxDiameter(tree.root) << endl;

    return 0;
}