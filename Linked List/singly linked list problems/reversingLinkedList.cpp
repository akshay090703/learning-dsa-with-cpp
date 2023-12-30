#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            insertAtHead(data);
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printNodes()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Traversing Approach
    // Time Complexity -> O(n)
    // Space Complexity -> O(1)
    // void reverseList()
    // {
    //     Node *prevNode = nullptr;
    //     Node *currNode = head;
    //     // Node *nextNode = nullptr;

    //     while (currNode != nullptr)
    //     {
    //         nextNode = currNode->next;
    //         currNode->next = prevNode;
    //         prevNode = currNode;
    //         currNode = nextNode;
    //     }

    //     head = prevNode;
    // }

    // Recursion Approach
    // Time Complexity -> O(n)
    // Space Complexity -> O(n)
    void reverseList(Node *currNode, Node *prevNode = nullptr)
    {
        if (currNode == nullptr)
        {
            head = prevNode;
            return;
        }
        Node *nextNode = currNode->next;
        currNode->next = prevNode;
        reverseList(nextNode, currNode);
    }
};

// youtube approach
Node *reverseListRecursion(Node *&head)
{
    if (head == nullptr or head->next == nullptr)
    {
        return head;
    }

    Node *new_head = reverseListRecursion(head->next);
    Node *nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;
    return new_head;
}

int main()
{
    LinkedList list = LinkedList();
    for (int i = 1; i <= 5; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();
    // list.reverseList(list.head);
    list.head = reverseListRecursion(list.head);
    list.printNodes();

    return 0;
}
