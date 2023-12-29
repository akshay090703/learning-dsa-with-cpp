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

    void displayNodes()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deletingRepeatingNodes()
    {
        Node *temp = head;
        if (temp->next == nullptr)
            return;

        while (temp)
        {
            if (temp->data == temp->next->data)
            {
                while (temp->next && temp->data == temp->next->data)
                {
                    Node *dummy = temp->next; // to be deleted
                    temp->next = temp->next->next;
                    delete dummy;
                }
            }

            // the loop will end when all the same value elements will be deleted or the temp pointer points at last node
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList ll = LinkedList();

    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(4);
    ll.insertAtTail(7);
    ll.insertAtTail(7);
    ll.displayNodes();

    cout << "After deleting repeating elements: \n";
    ll.deletingRepeatingNodes();
    ll.displayNodes();

    return 0;
}

// Time Complexity -> O(n)
// Space Complexity -> O(1)