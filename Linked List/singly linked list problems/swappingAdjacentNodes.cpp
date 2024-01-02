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
void swapAlternateNodes(LinkedList &list)
{
    if (!list.head || !list.head->next)
    {
        // if there are less than 2 nodes
        return;
    }

    Node *firstNode = list.head;
    Node *secondNode = list.head->next;
    Node *temp = nullptr;

    list.head = secondNode;
    Node *prev = nullptr;

    while (firstNode && secondNode)
    {
        temp = secondNode->next;
        secondNode->next = firstNode;

        if (!temp || !temp->next)
        {
            firstNode->next = temp;
            break;
        }
        prev = firstNode;

        firstNode = temp;
        secondNode = firstNode->next;
        prev->next = secondNode;
    }
}

int main()
{
    LinkedList list;
    for (int i = 1; i <= 6; i++)
    {
        list.insertAtTail(i);
    }
    cout << "Before Swapping Nodes: \n";
    list.printNodes();

    swapAlternateNodes(list);
    cout << "After Swapping Nodes: \n";
    list.printNodes();

    return 0;
}
