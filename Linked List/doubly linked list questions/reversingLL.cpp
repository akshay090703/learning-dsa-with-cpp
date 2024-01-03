#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

struct DoublyLinkedList
{
    Node *head, *tail;

    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        if (!head)
        {
            insertAtHead(data);
            return;
        }
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printNodes()
    {
        Node *temp = head;
        cout << "null <-> ";
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << " null" << endl;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)
void reversingDll(DoublyLinkedList &list)
{
    // if there are no nodes or only 1 node, then simply return
    if (!list.head && !list.head->next)
    {
        return;
    }

    Node *curr = list.head;
    Node *temp = nullptr;

    // will run until the curr node is null
    while (curr)
    {
        // storing the prev node as we need to swap the next and prev pointer
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // moving to the next node as we previously curr->prev = curr->next
        curr = curr->prev;
    }

    // setting the temp pointer at head so we can swap the head and tail pointer
    temp = list.head;
    list.head = list.tail;
    list.tail = temp;
}

int main()
{
    DoublyLinkedList dll;
    for (int i = 1; i <= 5; i++)
    {
        dll.insertAtTail(i);
    }
    dll.printNodes();

    reversingDll(dll);
    cout << "After reversing: \n";
    dll.printNodes();

    return 0;
}
