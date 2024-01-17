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
// Space Complexity -> O(n) or O(height)
bool isIdenticalTrees(Node *root1, Node *root2)
{
    if (!root1 & !root2)
        return true;

    if ((!root1 && root2) || (root1 && !root2))
    {
        return false;
    }

    if (root1->data == root2->data)
    {
        bool left = isIdenticalTrees(root1->left, root2->left);
        bool right = isIdenticalTrees(root1->right, root2->right);
        return left && right;
    }
    return false;
}

int main()
{
    BinaryTree tree1;
    buildingBTLevelOrderTraversal(tree1.root);

    BinaryTree tree2;
    buildingBTLevelOrderTraversal(tree2.root);

    string ans = isIdenticalTrees(tree1.root, tree2.root) ? "Identical." : "Not Identical!";
    cout << "The trees are " << ans << endl;

    // cout << "\nPre Order Traversal: ";
    // preOrderTraversal(tree1.root);

    return 0;
}