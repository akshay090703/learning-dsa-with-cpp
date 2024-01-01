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

// Slow-fast pointer approach
// Time Complexity -> O(n)
// Space Complexity -> O(1)
void isCyclicAndRemovingLL(LinkedList list)
{
    Node *slow = list.head, *fast = list.head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        // if we want to remove the cycle, we can point the node to null
        if (slow == fast)
        {
            // Floyd's Algorithm
            Node *ptr = list.head;
            while (ptr->next != slow->next)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            cout << "Cyclic. Removing the cycle." << endl;
            slow->next = nullptr;
            return;

            // return true;
        }
    }
    cout << "Not Cyclic." << endl;

    // return false;
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
    list.insertAtTail(7);
    list.insertAtTail(8);

    list.head->next->next->next->next->next->next->next->next = list.head->next->next;
    isCyclicAndRemovingLL(list);
    list.printNodes();

    // string answer = isCyclicLL(list) ? "Cyclic." : "Not Cyclic.";
    // cout << answer << endl;

    return 0;
}
