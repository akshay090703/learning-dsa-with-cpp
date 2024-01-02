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

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void printNodes()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// Time Complexity -> O(n)
// Space Complexity -> O(1)
void groupOddAndEvenIndices(LinkedList &list)
{
    if (!list.head || !list.head->next)
    {
        return;
    }

    Node *odd = list.head;
    Node *even = list.head->next;
    Node *evenHead = even;

    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
}

int main()
{
    LinkedList list;
    for (int i = 1; i <= 7; i++)
    {
        list.insertAtTail(i);
    }
    cout << "Before grouping: \n";
    list.printNodes();

    cout << "After grouping odd and even indices: \n";
    groupOddAndEvenIndices(list);
    list.printNodes();

    return 0;
}
