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
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        if (head == NULL)
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
        cout << "NULL" << endl;
    }

    // My approach
    // Time complexity -> O(n)
    // Space complexity -> O(n)
    // void printingReverseOrder()
    // {
    //     Node *temp = head;
    //     LinkedList *reverse = new LinkedList();
    //     while (temp != nullptr)
    //     {
    //         reverse->insertAtHead(temp->data);
    //         temp = temp->next;
    //     }

    //     reverse->printNodes();
    // }

    // Alternative approach -> Recursion
    // Time complexity -> O(n)
    // Space complexity -> O(n) but less iterations
    void printingReverseOrder(Node *temp)
    {
        if (temp == nullptr)
            return;

        printingReverseOrder(temp->next);
        cout << temp->data << " ";
    }
};

int main()
{
    LinkedList list = LinkedList();
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.printNodes();
    list.printingReverseOrder(list.head);

    system("pause");
    return 0;
}
