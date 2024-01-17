#include <iostream>
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

void nodeToIndexMapping(vector<int> inOrder, map<int, int> &m)
{
    for (int i = 0; i < inOrder.size(); i++)
    {
        m[inOrder[i]] = i;
    }
}

// as map takes logn time for insertion
// Time Complexity -> O(nlogn + n) ~ O(nlogn)
// Space Complexity -> O(n)
Node *solve(vector<int> inOrder, vector<int> postOrder, int &index, int inOrderStart, int inOrderEnd, map<int, int> nodeToIndex)
{
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return nullptr;
    }

    int element = postOrder[index--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // here we have to do the right call first as in postOrder traversal,
    // the order is (left, right, node) and we are starting from last
    // hence building right subtree first
    root->right = solve(inOrder, postOrder, index, position + 1, inOrderEnd, nodeToIndex);
    root->left = solve(inOrder, postOrder, index, inOrderStart, position - 1, nodeToIndex);

    return root;
}

Node *buildTree(vector<int> inOrder, vector<int> postOrder)
{
    if (!inOrder.size() || !postOrder.size())
        return nullptr;

    int n = inOrder.size();
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    nodeToIndexMapping(inOrder, nodeToIndex);

    Node *ans = solve(inOrder, postOrder, postOrderIndex, 0, n - 1, nodeToIndex);
    return ans;
}

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    BinaryTree tree;
    vector<int> inOrder = {7, 3, 11, 1, 17, 5};
    vector<int> postOrder = {7, 11, 3, 17, 5, 1};
    // answer: 1 3 7 11 5 17

    int n = inOrder.size();
    tree.root = buildTree(inOrder, postOrder);
    cout << "PreOrder Traversal of the constructed tree is: ";
    preOrderTraversal(tree.root);
    cout << endl;

    return 0;
}