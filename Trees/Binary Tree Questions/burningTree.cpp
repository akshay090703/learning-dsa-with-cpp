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

// Time Complexity of this section -> O(n)
// not needed
Node *findNode(Node *root, int target)
{
    if (!root)
        return nullptr;

    if (root->data == target)
    {
        return root;
    }

    Node *leftAns = findNode(root->left, target);
    Node *rightAns = findNode(root->right, target);

    if (leftAns && !rightAns)
        return leftAns;
    else if (!leftAns && rightAns)
        return rightAns;
    return nullptr;
}

// Time Complexity of whole function -> O(nlogn + n) ~ O(nlogn)
// Space Complexity -> O(n) + O(n) + O(height) ~ O(n)
// 1st and 2nd for 2 maps, 3rd for the queue in minBurningTime function
int minBurningTime(Node *root, int target)
{
    map<Node *, Node *> parentMap;
    // 1st is the node and 2nd is the parent of the node
    parentMap[root] = nullptr;

    queue<Node *> q;
    q.push(root);

    Node *targetNode = nullptr;

    int time = 0;

    // 1st step: create nodeToParent mapping
    // we can also do the step 1 and 2 in this loop itself to optimize further
    // Time Complexity -> O(nlogn)
    // Space Complexity -> O(n) and O(height)
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->data == target)
        {
            targetNode = curr;
        }

        if (curr->left)
        {
            q.push(curr->left);
            parentMap[curr->left] = curr;
        }

        if (curr->right)
        {
            q.push(curr->right);
            parentMap[curr->right] = curr;
        }
    }

    // 2nd step: find the target node
    q.push(targetNode);

    map<Node *, bool> isVisited;
    isVisited[targetNode] = true;

    // 3rd step: burn the tree in min time
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    while (!q.empty())
    {
        int size = q.size();
        bool change = false;
        for (int i = 0; i < size; ++i)
        {
            Node *curr = q.front();
            q.pop();

            if (parentMap[curr] && !isVisited[parentMap[curr]])
            {
                isVisited[parentMap[curr]] = true;
                q.push(parentMap[curr]);
                change = true;
            }
            if (curr->left && !isVisited[curr->left])
            {
                isVisited[curr->left] = true;
                q.push(curr->left);
                change = true;
            }
            if (curr->right && !isVisited[curr->right])
            {
                isVisited[curr->right] = true;
                q.push(curr->right);
                change = true;
            }
        }
        if (change)
        {
            time++;
        }
    }

    return time;
}

int main()
{
    BinaryTree tree;
    buildingBTLevelOrderTraversal(tree.root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    // 8
    // answer: 7

    // 1 2 3 4 5 -1 7 8 -1 10 -1 -1 -1 -1 -1 -1 -1
    // 10
    // answer: 5

    cout << "Pre Order Traversal: ";
    preOrderTraversal(tree.root);

    int node;
    cout << "\nEnter the burning node: ";
    cin >> node;

    cout << "The time taken to burn the whole tree in seconds is: ";
    cout << minBurningTime(tree.root, node) << endl;

    return 0;
}