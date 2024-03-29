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

bool isPalindromeLL(LinkedList list)
{
    Node *slow = list.head, *fast = list.head;

    // 1. finding the middle element
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow;

    Node *prev = nullptr;
    Node *curr = mid;
    Node *next = nullptr;

    // 2 and 3. reversing and breaking linked list in 2 lls
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 4. comparing the 2 linked lists now, if equal then return true, otherwise false
    Node *head1 = list.head;
    Node *head2 = prev;
    while (head1 && head2)
    {
        if (head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main()
{
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    // list.insertAtTail(3);
    list.insertAtTail(3);
    list.insertAtTail(2);
    list.insertAtTail(1);
    // list.insertAtTail(1);

    list.printNodes();

    string answer = isPalindromeLL(list) ? "Palindrome." : "Not Palindrome.";
    cout << answer << endl;

    return 0;
}
