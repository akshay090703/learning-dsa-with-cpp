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

// Time Complexity -> O(1)
void insertAtHead(Node *&head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

// Time Complexity -> O(n)
void insertAtTail(Node *&head, int data)
{
    Node *new_node = new Node(data);
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // temp has reached last node
    temp->next = new_node;
}

// Time Complexity -> O(n)
void insertAtkthIndex(Node *&head, int data, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
        return;
    }

    // it follows a 0 based indexing
    Node *new_node = new Node(data);
    Node *temp = head;
    int curr_position = 0;

    while (curr_position < pos - 1)
    {
        temp = temp->next;
        curr_position++;
    }

    // temp is pointing to node at pos - 1
    new_node->next = temp->next;
    temp->next = new_node;
}

// Time Complexity -> O(n)
void updateKthIndex(Node *&head, int data, int pos)
{
    Node *temp = head;
    int curr_pos = 0;

    while (curr_pos < pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }

    temp->next->data = data;
}

// Time Complexity -> O(1)
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp); // frees the space occupied by temp pointer
}

// Time Complexity -> O(n)
void deleteAtTail(Node *&head)
{
    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node *dummy = temp->next;
    free(dummy); // freeing the last element which is now deleted

    // now temp is the second last node
    temp->next = nullptr;
}

// Time Complexity -> O(n)
// follows 0 based positioning
void deleteAtKthIdx(Node *&head, int pos)
{
    if (pos == 0)
    {
        deleteAtHead(head);
        return;
    }

    Node *temp = head;
    int idx = 0;

    while (idx < pos - 1)
    {
        temp = temp->next;
        idx++;
    }

    // temp is pointing to node at pos - 1
    Node *dummy = temp->next; // node to be deleted
    temp->next = temp->next->next;
    free(dummy);
}

void display(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr;
    insertAtHead(head, 1);
    display(head);
    insertAtHead(head, 2);
    display(head);
    insertAtTail(head, 3);
    display(head);
    insertAtTail(head, 4);
    display(head);
    insertAtkthIndex(head, 5, 2);
    display(head);
    insertAtkthIndex(head, 8, 4);
    display(head);
    updateKthIndex(head, 6, 4);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtKthIdx(head, 1);
    display(head);

    return 0;
}