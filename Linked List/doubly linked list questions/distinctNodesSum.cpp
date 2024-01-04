#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = prev = nullptr;
    }
};

struct DoublyLinkedList
{
    Node *head, *tail;

    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(int data)
    {
        if (!head)
        {
            insertAtHead(data);
            return;
        }

        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void printNodes()
    {
        Node *temp = head;
        cout << "null <-> ";
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// Using two pointers approach here, this can also be solved using brute
// force approach but it would then take O(n^2) time complexity
// Time Complexity -> O(n)
// Space Complexity -> O(1)
vector<int> sumOfNodesEqualToX(DoublyLinkedList &list, int x)
{
    if (!list.head)
        return {-1, -1};
    vector<int> result;
    Node *left = list.head;
    Node *right = list.tail;

    while (left != right && left->prev != right)
    {
        int sum = left->data + right->data;
        if (sum < x)
        {
            left = left->next;
        }
        else if (sum > x)
        {
            right = right->prev;
        }
        else
        {
            return {left->data, right->data};
        }
    }
    return {-1, -1};
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(2);
    dll.insertAtTail(4);
    dll.insertAtTail(6);
    dll.insertAtTail(8);
    dll.insertAtTail(10);
    dll.insertAtTail(12);
    dll.printNodes();

    vector<int> result = sumOfNodesEqualToX(dll, 11);
    cout << "The two numbers are: " << result[0] << " " << result[1] << endl;

    return 0;
}