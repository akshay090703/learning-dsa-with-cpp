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
    if (!root)
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

Node *insertIntoBST(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void sortedBST(Node *root, vector<int> &v)
{
    if (!root)
        return;

    sortedBST(root->left, v);
    v.push_back(root->data);
    sortedBST(root->right, v);
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)
bool twoSumInBST(Node *root, int target)
{
    vector<int> ans;
    sortedBST(root, ans);

    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        int sum = ans[i] + ans[j];
        if (sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
        else
            return true;
    }

    return false;
}

int main()
{
    BinarySearchTree tree;
    // 10 6 12 2 8 11 15 -1

    cout << "Enter data to create BST:" << endl;
    takeInput(tree.root);

    cout << "The created BST looks like: \n";
    levelOrderTraversal(tree.root);

    cout << "Enter the sum that you want to find: ";
    int target;
    cin >> target;

    string ans = twoSumInBST(tree.root, target) ? "Two Sum exists." : "Two Sum doesn't exists!";
    cout << ans << endl;

    return 0;
}