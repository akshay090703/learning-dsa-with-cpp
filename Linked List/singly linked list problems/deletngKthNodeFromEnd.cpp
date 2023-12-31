#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

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
        head = nullptr;
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
        if (head == nullptr)
        {
            insertAtHead(data);
            return;
        }

        Node *newNode = new Node(data);
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
        cout << "null" << endl;
    }
};

// assuming k is always less than length of linked list
void removeKthNodeFromEnd(Node *&head, int k)
{
    Node *ptr1 = head;
    Node *ptr2 = head;

    // move ptr2 by k steps ahead
    int count = k;
    while (count--)
    {
        ptr2 = ptr2->next;
    }

    if (ptr2 == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while (ptr2->next != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    Node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;
}

int main()
{
    LinkedList list = LinkedList();
    for (int i = 1; i <= 5; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();

    removeKthNodeFromEnd(list.head, 5);
    list.printNodes();

    return 0;
}
