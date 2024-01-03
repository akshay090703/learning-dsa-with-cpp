#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

struct DoublyLinkedList
{
    Node *head;
    Node *tail;

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
        cout << "null" << endl;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)
void dltSameCoincidingNodes(DoublyLinkedList list)
{
    if (!list.head || !list.head->next)
        return;

    Node *temp = list.tail;
    while (temp != list.head)
    {
        if (temp->data == temp->prev->data)
        {
            Node *dummy = temp;
            temp = temp->prev;
            temp->next = dummy->next;
            if (dummy->next)
            {
                dummy->next->prev = temp;
            }
            delete dummy;
        }
        else
        {
            temp = temp->prev;
        }
    }
}

// Time Complexity -> O(n)
// Space Complexity -> O(1)
void dltNeighboringSameNodes(DoublyLinkedList &list)
{
    Node *currNode = list.tail->prev;
    while (currNode != list.head)
    {
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;
        if (prevNode->data == nextNode->data)
        {
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;
    }
}

int main()
{
    DoublyLinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(3);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(4);
    list.insertAtTail(4);
    list.printNodes();

    cout << "After deleting same neighboring nodes: \n";
    dltNeighboringSameNodes(list);
    list.printNodes();

    return 0;
}