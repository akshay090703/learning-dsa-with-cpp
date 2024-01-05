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

Node *findingMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2)
{
    Node *new_head;
    if (head1->data < head2->data)
    {
        new_head = head1;
        head1 = head1->next;
    }
    else
    {
        new_head = head2;
        head2 = head2->next;
    }

    Node *temp = new_head;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1)
    {
        temp->next = head1;
    }

    if (head2)
    {
        temp->next = head2;
    }

    return new_head;
}

void mergeSort(Node *&head)
{
    if (!head || !head->next)
        return;

    Node *mid = findingMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;

    mergeSort(left);
    mergeSort(right);

    head = merge(left, right);
}

int main()
{
    LinkedList list;
    for (int i = 5; i >= 1; i--)
    {
        list.insertAtTail(i);
    }
    list.printNodes();

    mergeSort(list.head);
    cout << "Linked List after sorting: ";
    list.printNodes();

    return 0;
}