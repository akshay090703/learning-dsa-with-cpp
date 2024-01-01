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

// using slow fast approach
// Space Complexity -> O(1)
// Time Complexity -> O(n/2) ~ O(n)
Node *findingMidNode(LinkedList list)
{
    Node *slow = list.head, *fast = list.head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    LinkedList list = LinkedList();
    for (int i = 0; i <= 5; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();

    Node *answer = findingMidNode(list);
    cout << "The middle node is: " << answer->data << "\n";

    return 0;
}
