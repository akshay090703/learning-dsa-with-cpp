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

LinkedList mergingTwoSortedLLs(LinkedList list1, LinkedList list2)
{
    Node *temp1 = list1.head;
    Node *temp2 = list2.head;
    LinkedList result = LinkedList();

    Node *ansNode = nullptr;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        Node *newNode;
        if (temp1->data < temp2->data)
        {
            newNode = new Node(temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            newNode = new Node(temp2->data);
            temp2 = temp2->next;
        }

        if (ansNode == nullptr)
        {
            ansNode = newNode;
            result.head = ansNode;
        }
        else
        {
            ansNode->next = newNode;
            ansNode = newNode;
        }
    }

    while (temp1 != nullptr)
    {
        Node *newNode = new Node(temp1->data);
        ansNode->next = newNode;
        ansNode = newNode;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr)
    {
        Node *newNode = new Node(temp2->data);
        ansNode->next = newNode;
        ansNode = newNode;
        temp2 = temp2->next;
    }

    return result;
}

int main()
{
    LinkedList list1 = LinkedList();
    LinkedList list2 = LinkedList();

    for (int i = 0; i <= 10; i += 2)
    {
        list1.insertAtTail(i);
    }
    list1.printNodes();

    for (int i = 1; i <= 10; i += 2)
    {
        list2.insertAtTail(i);
    }
    list2.printNodes();

    LinkedList resultLL = mergingTwoSortedLLs(list1, list2);
    resultLL.printNodes();

    return 0;
}
