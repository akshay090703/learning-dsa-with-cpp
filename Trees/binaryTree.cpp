#include <iostream>
#include <queue>
#include <stack>
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

Node *buildTree(Node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr) // means old level has been traversed completely
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr); // means that there are still nodes remaining from the old level
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraverse(Node *root)
{
    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        st.push(current);

        if (current == nullptr)
        {
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (current->right)
            {
                q.push(current->right);
            }

            if (current->left)
            {
                q.push(current->left);
            }
        }
    }

    while (!st.empty())
    {
        if (!st.top())
        {
            cout << endl;
        }
        else
        {
            cout << st.top()->data << " ";
        }
        st.pop();
    }
}

// Using Recursion
// void inOrderTraversal(Node *root)
// {
//     if (!root)
//     {
//         return;
//     }

//     inOrderTraversal(root->left);
//     cout << root->data << " ";
//     inOrderTraversal(root->right);
// }

// void preOrderTraversal(Node *root)
// {
//     if (!root)
//         return;

//     cout << root->data << " ";
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// }

// void postOrderTraversal(Node *root)
// {
//     if (!root)
//         return;

//     postOrderTraversal(root->left);
//     postOrderTraversal(root->right);
//     cout << root->data << " ";
// }

// Using Iteration
void inOrderTraversal(Node *root)
{
    stack<Node *> st;
    Node *current = root;

    while (current || !st.empty())
    {
        while (current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

void preOrderTraversal(Node *root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();

        cout << current->data << " ";

        if (current->right)
        {
            st.push(current->right);
        }

        if (current->left)
        {
            st.push(current->left);
        }
    }
}

void postOrderTraversal(Node *root)
{
    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left)
        {
            st1.push(current->left);
        }

        if (current->right)
        {
            st1.push(current->right);
        }
    }

    while (!st2.empty())
    {
        Node *node = st2.top();
        st2.pop();
        cout << node->data << " ";
    }
}

int main()
{
    BinaryTree tree;

    // creating a tree
    tree.root = buildTree(tree.root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Level order traversal: \n";
    levelOrderTraversal(tree.root);

    cout << "Reverse Lever Order Traversal: ";
    reverseLevelOrderTraverse(tree.root);

    cout << "\nInorder Traversal: ";
    inOrderTraversal(tree.root);

    cout << "\nPreorder Traversal: ";
    preOrderTraversal(tree.root);

    cout << "\nPostorder traversal: ";
    postOrderTraversal(tree.root);

    return 0;
}