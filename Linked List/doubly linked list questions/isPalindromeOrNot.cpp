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
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
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

bool isPalindromeOrNot(DoublyLinkedList &list)
{
    if (!list.head or !list.head->next)
    {
        return true;
    }
    Node *first_half = list.head;
    Node *second_half = list.tail;

    while (first_half != second_half && second_half != first_half->prev)
    {
        if (second_half->data != first_half->data)
        {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->prev;
    }
    return true;
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    // dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.printNodes();

    string ans = isPalindromeOrNot(dll) ? "Palindrome." : "Not a Palindrome.";
    cout << ans << endl;

    return 0;
}