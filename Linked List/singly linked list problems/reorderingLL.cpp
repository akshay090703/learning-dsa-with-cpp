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

// Time Complexity -> O(2n) ~ O(n)
// Space Complexity -> O(1)
void reorderLL(LinkedList list)
{
    if (!list.head || !list.head->next || !list.head->next->next)
        return;

    Node *slow = list.head, *fast = list.head;

    // Finding the middle of Linked List
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;

    // Reversing the list after the middle element
    Node *prev = nullptr;
    Node *curr = mid;
    Node *next = nullptr;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Merging the two lists and getting the answer
    Node *head1 = list.head;
    Node *head2 = prev;
    while (head2->next) // or we can do this until head1!=head2
    {
        Node *temp1 = head1->next;
        Node *temp2 = head2->next;

        head1->next = head2;
        head2->next = temp1;

        head1 = temp1;
        head2 = temp2;
    }
}

int main()
{
    LinkedList list;
    for (int i = 1; i <= 2; i++)
    {
        list.insertAtTail(i);
    }
    list.printNodes();

    reorderLL(list);
    cout << "Reordered linked list: \n";
    list.printNodes();

    return 0;
}