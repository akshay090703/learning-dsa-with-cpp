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
        head = nullptr;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        if (head == NULL)
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
        cout << "NULL" << endl;
    }
};

Node *reversingKNodes(Node *&head, int k)
{
    Node *prevNode = nullptr;
    Node *current = head;
    int count = 0;

    while (current != nullptr && count < k) // reversing first k nodes
    {
        Node *nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
        count++;
    }

    // current will give us (k+1)th node
    if (current != nullptr)
    {
        Node *new_head = reversingKNodes(current, k); // recursive call to return new head
        head->next = new_head;                        // connecting 2 linked lists
    };

    // prevNode will give the new_head of connected linked lists
    return prevNode;
}

int main()
{
    LinkedList list = LinkedList();
    for (int i = 1; i <= 6; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();
    list.head = reversingKNodes(list.head, 4);
    list.printNodes();

    return 0;
}