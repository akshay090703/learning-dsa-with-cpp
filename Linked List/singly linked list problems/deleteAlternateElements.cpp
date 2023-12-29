#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList
{
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void addElementsAtHead(int data);
    void addElementsAtLast(int data);
    void printLinkedList();
    void deletingFirstElement();
    void deletingKthElement(int pos);
    void alternateDeletingElements();
};

void LinkedList::addElementsAtHead(int data)
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

void LinkedList::addElementsAtLast(int data)
{
    if (head == nullptr)
    {
        addElementsAtHead(data);
        return;
    }
    Node *newNode = new Node(data);
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = nullptr;
}

void LinkedList::printLinkedList()
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void LinkedList::alternateDeletingElements()
{
    if (!head || !head->next)
    {
        return;
    }

    Node *current = head;
    Node *nextNode = head->next;

    while (current != nullptr && nextNode != nullptr)
    {
        current->next = nextNode->next;
        delete nextNode;

        current = current->next;

        if (current != nullptr)
        {
            nextNode = current->next;
        }
    }
}

void LinkedList::deletingFirstElement()
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deletingKthElement(int pos)
{
    Node *temp = head;
    int idx = 0;

    while (idx < pos - 1)
    {
        idx++;
        temp = temp->next;
    }

    Node *dummy = temp->next;
    temp->next = dummy->next;
    delete dummy;
}

int main()
{
    LinkedList ll = LinkedList();

    // Adding elements to the list.
    for (int i = 1; i <= 6; i++)
    {
        ll.addElementsAtLast(i);
    };
    ll.printLinkedList();

    cout << "Alternate Deletion of Elements: \n";
    ll.alternateDeletingElements();
    ll.printLinkedList();

    return 0;
}