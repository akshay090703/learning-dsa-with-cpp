#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
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

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayNodes()
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

// using recursion
// Time Complexity -> O(k*n)
// Space Complexity -> O(k)
void rotateKNodesInLL(LinkedList &list, int k, int i = 0)
{
    if (i == k)
    {
        return;
    }

    Node *temp = list.head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    Node *secondLast = temp;
    Node *last = temp->next;
    last->next = list.head;
    secondLast->next = NULL;
    list.head = last;

    return rotateKNodesInLL(list, k, i + 1);
}

// Youtube approach
// Time Complexity -> O(n)
// Space Complexity -> O(1)
void rotateKNodesLL(LinkedList &list, int k)
{
    if (k <= 0)
        return;

    // getting the last node
    Node *lastNode = list.head;

    // getting the length of the linked list
    int length = 0;
    while (lastNode->next)
    {
        lastNode = lastNode->next;
        ++length;
    }
    length++;

    // if k is greater than length, then k % length will give the optimized value
    k %= length;

    // iteratoring till the n-k node
    Node *temp = list.head;
    int iterator = 1;
    while (iterator < length - k)
    {
        temp = temp->next;
        iterator++;
    }

    // assigning the (n-k+1)th node as the new head
    Node *new_head = temp->next;

    // pointing the (n-k)th node to null
    temp->next = nullptr;

    // joining and assigning the new head
    lastNode->next = list.head;
    list.head = new_head;
}

int main()
{
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.displayNodes();

    // rotateKNodesInLL(list, 2);
    rotateKNodesLL(list, 8);
    list.displayNodes();

    return 0;
}
