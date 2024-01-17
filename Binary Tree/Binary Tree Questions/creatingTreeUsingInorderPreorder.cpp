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

// to further optimize it, we can use map to find the index which would only take O(1), whereas right now it takes O(n)
// After Optimization
// as map takes logn time for insertion
// Time Complexity -> O(nlogn + n) ~ O(nlogn)
// Space Complexity -> O(n) {map}
void createMapping(vector<int> in, map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

// int findPosition(vector<int> in, int element)
// {
//     int n = in.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (in[i] == element)
//             return i;
//     }
//     return -1;
// }

Node *solve(vector<int> in, vector<int> pre, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index >= n || inOrderStart > inOrderEnd)
        return nullptr;

    int element = pre[index++];
    Node *root = new Node(element);
    int position = nodeToIndex[element];
    // int position = findPosition(in, element);

    root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(vector<int> inOrder, vector<int> preOrder, int n)
{
    if (n == 0)
        return nullptr;
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    // create nodes to index mapping
    createMapping(inOrder, nodeToIndex, n);
    Node *ans = solve(inOrder, preOrder, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

void postOrderTraversal(Node *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    BinaryTree tree;
    vector<int> inOrder = {3, 1, 4, 0, 5, 2};
    vector<int> preOrder = {0, 1, 3, 4, 2, 5};
    // answer: 3 4 1 5 2 0

    int n = inOrder.size();
    tree.root = buildTree(inOrder, preOrder, n);
    cout << "PostOrder Traversal of the constructed tree is: ";
    postOrderTraversal(tree.root);
    cout << endl;

    return 0;
}