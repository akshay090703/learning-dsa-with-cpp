// Both Zig Zag traversal and Spiral traversal are same
#include <iostream>
#include <queue>
#include <deque>
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

// My Approach
// Time Complexity -> O(n)
// Space Complexity -> O(max level nodes)
void spiralTraversal(Node *root)
{
    deque<Node *> d;
    d.push_back(root);
    bool flag = true; // means left to right

    while (!d.empty())
    {
        int levelSize = d.size();
        for (int i = 0; i < levelSize; i++)
        {
            if (flag)
            {
                Node *current = d.front();
                d.pop_front();

                cout << current->data << " ";
                if (current->left)
                    d.push_back(current->left);
                if (current->right)
                    d.push_back(current->right);
            }
            else
            {
                Node *current = d.back();
                d.pop_back();

                cout << current->data << " ";
                if (current->right)
                    d.push_front(current->right);
                if (current->left)
                    d.push_front(current->left);
            }
        }

        flag = !flag;
    }
}

// Youtube approach
// Time Complexity -> O(n)
// Space Complexity -> O(n)
vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<Node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = current->data;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nSpiral Order Traversal: ";
    spiralTraversal(tree.root);

    cout << "\nSpiral Order Traversal: ";
    vector<int> ans = zigZagTraversal(tree.root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}