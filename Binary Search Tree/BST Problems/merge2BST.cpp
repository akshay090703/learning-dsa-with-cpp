#include <iostream>
#include <queue>
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

void inOrderTraversal(Node *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void inOrderVector(Node *root, vector<Node *> &v)
{
    if (!root)
        return;

    inOrderVector(root->left, v);
    v.push_back(root);
    inOrderVector(root->right, v);
}

void mergedVector(vector<Node *> &v1, vector<Node *> &v2, vector<Node *> &merged)
{
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i]->data < v2[j]->data)
        {
            merged.push_back(v1[i]);
            i++;
        }
        else
        {
            merged.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size())
    {
        merged.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        merged.push_back(v2[j]);
        j++;
    }
}

Node *buildBSTFromInOrder(vector<Node *> &v, int start, int end, int &n)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = start + ((end - start) / 2);

    v[mid]->left = buildBSTFromInOrder(v, start, mid - 1, n);
    v[mid]->right = buildBSTFromInOrder(v, mid + 1, end, n);

    return v[mid];
}

// Time COmplexity -> O(n) + O(n) + O(n+m) + O(n+m) ~ O(n+m)
// Space COmplexity -> O(n) + O(n) + O(n+m) + O(height) ~ O(n+m)
Node *mergeBSTs(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return nullptr;
    else if (!root1)
        return root2;
    else if (!root2)
        return root1;

    vector<Node *> tree1;
    inOrderVector(root1, tree1);

    vector<Node *> tree2;
    inOrderVector(root2, tree2);

    vector<Node *> mergedTree;
    mergedVector(tree1, tree2, mergedTree);

    int n = mergedTree.size();
    Node *new_root = buildBSTFromInOrder(mergedTree, 0, n - 1, n);

    return new_root;
}

// Optimized approach:
// Step 1: Convert BST into sorted LL
// Step 2: Merge 2 sorted lls
// Step 3: Sorted lls -> BST
// Time Complexity -> O(n+m)
// Space Complexity -> O(height1 + height2)

// Step 1: Converting BST to sorted LLs
// Time Complexity -> O(n + m)
// Space Complexity -> O(1)
Node *findPredecessor(Node *root)
{
    Node *pred = root;
    pred = pred->left;
    while (pred->right && pred->right != root)
    {
        pred = pred->right;
    }
    return pred;
}

Node *BSTtoSortedLL(Node *root)
{
    Node *curr = root;
    Node *head = nullptr;
    Node *prev = nullptr;

    while (curr)
    {
        if (!curr->left)
        {
            if (!head)
                head = curr;

            if (prev)
                prev->right = curr;

            prev = curr;
            curr = curr->right;
        }
        else
        {
            Node *predecessor = findPredecessor(curr);
            if (!predecessor->right)
            {
                predecessor->right = curr;
                Node *temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
            else
            {
                if (!head)
                    head = curr;

                if (prev)
                    prev->right = curr;

                prev = curr;
                curr = curr->right;
            }
        }
    }

    return head;
}

// Step 2: Merging 2 linked lists\
// Time Complexity -> O(n+m)
// Space Complexity -> O(1)
Node *mergingLLs(Node *root1, Node *root2)
{
    if (!root1 && root2)
        return root2;
    else if (root1 && !root2)
        return root1;
    else if (!root1 && !root2)
        return nullptr;

    Node *temp1 = root1, *temp2 = root2;

    Node *new_head;
    if (root1->data <= root2->data)
    {
        new_head = root1;
        temp1 = temp1->right;
    }
    else
    {
        new_head = root2;
        temp2 = temp2->right;
    }

    Node *curr = new_head;

    while (temp1 && temp2)
    {
        if (temp1->data <= temp2->data)
        {
            curr->right = temp1;
            temp1 = temp1->right;
        }
        else
        {
            curr->right = temp2;
            temp2 = temp2->right;
        }
        curr = curr->right;
    }

    if (temp1)
        curr->right = temp1;

    if (temp2)
        curr->right = temp2;

    return new_head;
}

// Step 3: Sorted LLs into BST
// Time Complexity -> O((n+m) + (n+m)) ~ O(n+m)
// Space Complexity -> O(height1 + height2)
Node *midOfLL(Node *head, Node *tail)
{
    Node *slow;
    Node *fast;
    slow = fast = head;

    while (fast && fast->right != tail && fast != tail)
    {
        fast = fast->right->right;
        slow = slow->right;
    }

    return slow;
}

Node *sortedListToBST(Node *head, Node *tail)
{
    if (!head || head == tail)
        return NULL;

    Node *new_root = midOfLL(head, tail);

    new_root->left = sortedListToBST(head, new_root);
    new_root->right = sortedListToBST(new_root->right, tail);

    return new_root;
}

// Driver function
// Time Complexity -> O(n+m) + O(n+m) + O(n+m) ~ O(n+m)
// Space Complexity -> O(height1 + height2)
Node *optimizedMergingBST(Node *root1, Node *root2)
{
    // Step 1
    Node *head1 = BSTtoSortedLL(root1);
    Node *head2 = BSTtoSortedLL(root2);

    // Step 2
    Node *merged_head = mergingLLs(head1, head2);

    // Step 3
    Node *merged_root = sortedListToBST(merged_head, nullptr);

    return merged_root;
}

// extra - convert BST into Doubly LL
// void convertIntoSortedDLL(Node *root, Node *&head)
// {
//     if (!root)
//         return;

//     convertIntoSortedDLL(root->right, head);

//     root->right = head;
//     if (!head)
//         head->left = root;
//
//     head = root;
//
//     convertIntoSortedDLL(root->left, head);
// }

int main()
{
    BinarySearchTree tree1;
    BinarySearchTree tree2;
    BinarySearchTree mergedTree;

    cout << "Enter data to create BST-1:" << endl;
    takeInput(tree1.root);

    cout << "Enter data to create BST-2:" << endl;
    takeInput(tree2.root);

    // mergedTree.root = mergeBSTs(tree1.root, tree2.root);
    mergedTree.root = optimizedMergingBST(tree1.root, tree2.root);
    cout << "Level Traversal of the merged Tree is: ";
    levelOrderTraversal(mergedTree.root);

    cout << "\nInOrder Traversal of merged Tree is: ";
    inOrderTraversal(mergedTree.root);

    return 0;
}