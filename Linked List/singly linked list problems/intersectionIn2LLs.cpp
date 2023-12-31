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
        Node *temp = head;
        Node *newNode = new Node(data);

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

int getLength(Node *head);
Node *moveHeadByK(Node *head, int k);

Node *intersectionBtwLLs(Node *head1, Node *head2)
{
    // length of both the linked lists
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    // if the first linked list is longer than the second linked list
    Node *ptr1;
    Node *ptr2;
    if (length1 > length2)
    {
        int k = length1 - length2;
        ptr1 = moveHeadByK(head1, k);
        ptr2 = head2;
    }
    else
    {
        int k = length2 - length1;
        ptr2 = moveHeadByK(head2, k);
        ptr1 = head1;
    }

    // compare ptr1 and ptr2 nodes
    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return nullptr;
}

Node *moveHeadByK(Node *head, int k)
{
    Node *ptr = head;
    while (k--)
    {
        ptr = ptr->next;
    }
    return ptr;
}

int getLength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

int main()
{
    LinkedList list1 = LinkedList();
    list1.insertAtTail(1);
    list1.insertAtTail(2);
    list1.insertAtTail(3);
    list1.insertAtTail(4);
    list1.insertAtTail(5);
    list1.printNodes();

    LinkedList list2 = LinkedList();
    list2.insertAtTail(6);
    list2.insertAtTail(7);
    list2.head->next->next = list1.head->next->next->next;
    // 6->7->4->5->null
    list2.printNodes();

    Node *intersection = intersectionBtwLLs(list1.head, list2.head);

    cout << "The intersection between the linked lists is: " << (intersection ? intersection->data : -1) << endl;

    return 0;
}

// Intersection
// Time Complexity-> O(n+m)
// Space Complexity ->O(1)
// where n is the length of first linked list and m is the length of second