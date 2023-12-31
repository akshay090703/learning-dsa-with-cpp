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

    void displayNodes()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

bool isListsEqual(LinkedList list1, LinkedList list2)
{
    bool isEqual = true;
    Node *temp1 = list1.head;
    Node *temp2 = list2.head;

    while (temp1 != nullptr || temp2 != nullptr)
    {
        if (temp1 == nullptr || temp2 == nullptr || temp1->data != temp2->data)
        {
            isEqual = false;
            break;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return isEqual;
};

int main()
{
    LinkedList list1 = LinkedList();
    for (int i = 1; i <= 8; i++)
    {
        list1.insertAtTail(i);
    }
    list1.displayNodes();

    LinkedList list2 = LinkedList();
    for (int i = 1; i <= 8; i++)
    {
        list2.insertAtTail(i);
    }
    list2.displayNodes();

    string ans = isListsEqual(list1, list2) ? "Equal" : "Not Equal";
    cout << "The two linked lists are " << ans << endl;

    return 0;
}
