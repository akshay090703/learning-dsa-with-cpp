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
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int data)
    {
        Node *new_node = new Node(data);
        if (!head)
        {
            head = tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertAtTail(int data)
    {
        Node *new_node = new Node(data);
        if (!tail)
        {
            tail = head = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertAtKthPos(int data, int k)
    {
        Node *temp = head;
        int count = 1;

        // using the 1 based indexing, can also be used 0 based indexing
        while (count < (k - 1))
        {
            temp = temp->next;
            count++;
        }

        // now the temp pointer is pointing at (k-1)th node
        Node *new_node = new Node(data);

        new_node->next = temp->next;
        temp->next = new_node;

        new_node->prev = temp;
        new_node->next->prev = new_node;
    }

    void deleteAtHead()
    {
        if (!head)
            return;

        Node *temp = head;
        head = head->next;
        if (!head) // if there was only one node
        {
            tail = nullptr;
        }
        else
        {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtTail()
    {
        if (!tail)
        {
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        if (!tail)
        {
            head = nullptr;
        }
        else
        {
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteAtKthPos(int k)
    {
        if (!head)
        {
            return;
        }

        if (k == 1)
        {
            deleteAtHead();
            return;
        }

        int i = 1;
        Node *temp = head;
        while (i < k - 1 && temp)
        {
            temp = temp->next;
            i++;
        }
        if (!temp && !temp->next)
        {
            return;
        }
        Node *dummy = temp->next;
        temp->next = temp->next->next;

        if (dummy->next)
        {
            dummy->next->prev = temp;
        }
        else
        {
            temp->next = nullptr;
        }

        delete dummy;
    }

    void printNodes()
    {
        Node *temp = head;
        cout << "null"
             << "<->";
        while (temp)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    for (int i = 1; i <= 5; i++)
    {
        list.insertAtTail(i);
    }
    // list.insertAtHead(2);
    // list.insertAtHead(3);
    list.printNodes();

    cout << "After deleting: \n";
    list.deleteAtKthPos(4);
    list.printNodes();

    return 0;
}