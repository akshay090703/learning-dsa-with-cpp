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

    void reversingKNodes(Node *currNode, int k, Node *prevNode = nullptr)
    {
        static int idx = 0;
        if (k == idx)
        {
        }
    }
};

int main()
{
    LinkedList list = LinkedList();
    for (int i = 1; i <= 6; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();

    return 0;
}