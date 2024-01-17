#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> topViewBT(Node *root)
{
    map<int, vector<int>> m;
    // first value will be horizontal distance and second will be the node corresponding to that

    vector<int> ans;

    if (!root)
        return ans;

    queue<pair<int, Node *>> q;
    q.push(make_pair(0, root));

    while (!q.empty())
    {
        pair<int, Node *> temp = q.front();
        q.pop();

        Node *frontNode = temp.second;
        int hd = temp.first;

        if (m[hd].empty())
        {
            m[hd].push_back(frontNode->data);
        }

        // another way if we don't want to use vectors
        // when we can't find a value to any key then it is equal to the map.end() value
        // if (m.find(hd) == m.end())
        //     m[hd] = frontNode->data;

        // maintain only one value for each hd
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
        ans.push_back(i.second[0]);
    }

    return ans;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nTop View of the Binary Tree: ";
    vector<int> res = topViewBT(tree.root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}