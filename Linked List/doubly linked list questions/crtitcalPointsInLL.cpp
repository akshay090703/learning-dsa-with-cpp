#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
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

vector<int> maxMinCriticalPointsInLL(DoublyLinkedList &list)
{
    if (!list.head || !list.head->next || !list.head->next->next)
    {
        return {-1, -1};
    }

    vector<Node *> critical_points;
    Node *currNode = list.tail->prev;

    while (currNode != list.head)
    {
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;

        if ((prevNode->data < currNode->data && currNode->data > nextNode->data) || (prevNode->data > currNode->data && currNode->data < nextNode->data))
        {
            critical_points.insert(critical_points.begin(), currNode);
        }

        currNode = prevNode;
    }

    if (critical_points.size() < 2)
    {
        return {-1, -1};
    }

    Node *firstCriticalPoint = critical_points[0];
    Node *lastCriticalPoint = critical_points[critical_points.size() - 1];

    int maxDist = 0;
    Node *temp = lastCriticalPoint;
    while (temp != firstCriticalPoint)
    {
        temp = temp->prev;
        maxDist++;
    }

    int minDist = 0;
    temp = lastCriticalPoint;
    while (temp != critical_points[critical_points.size() - 2])
    {
        temp = temp->prev;
        minDist++;
    }

    return {minDist, maxDist};
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(5);
    dll.insertAtTail(2);
    dll.insertAtTail(6);
    dll.insertAtTail(3);
    dll.printNodes();

    vector<int> result = maxMinCriticalPointsInLL(dll);
    cout << "The minimum distance between critical points: " << result[0] << endl;
    cout << "The maximum distance between critical points: " << result[1] << endl;

    return 0;
}