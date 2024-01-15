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
vector<int> bottomViewBT(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> m;
    // sorted keys in this data structures
    queue<pair<int, Node *>> q;
    q.push(make_pair(0, root));

    while (!q.empty())
    {
        pair<int, Node *> temp = q.front();
        q.pop();

        Node *frontNode = temp.second;
        int hd = temp.first;

        m[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(hd - 1, frontNode->left));
        }

        if (frontNode->right)
        {
            q.push(make_pair(hd + 1, frontNode->right));
        }
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nBottom View of the Binary Tree: ";
    vector<int> res = bottomViewBT(tree.root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}