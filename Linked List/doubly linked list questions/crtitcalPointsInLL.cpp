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

// Time Complexity -> O(n)
// Space Complexity -> O(1)
vector<int> maxMinCriticalPointsInLL(DoublyLinkedList &list)
{
    if (!list.head || !list.head->next || !list.head->next->next)
    {
        return {-1, -1};
    }

    Node *currNode = list.tail->prev;
    int minDist = INT_MAX;
    int maxDist = INT_MIN;
    int pos = 0;
    int latest_dist = 0;
    int last_point = -1;
    int critical_points = 0;

    while (currNode != list.head)
    {
        Node *prevNode = currNode->prev;
        Node *nextNode = currNode->next;

        if ((prevNode->data < currNode->data && currNode->data > nextNode->data) || (prevNode->data > currNode->data && currNode->data < nextNode->data))
        {
            if (last_point == -1)
            {
                last_point = pos;
            }
            else
            {
                minDist = min(minDist, pos - latest_dist);
            }
            latest_dist = pos;
            maxDist = max(maxDist, pos - last_point);
            critical_points++;
        }
        pos++;

        currNode = prevNode;
    }

    if (critical_points < 2)
    {
        return {-1, -1};
    }

    return {minDist, maxDist};
}

int main()
{
    DoublyLinkedList dll;
    dll.insertAtTail(1);
    dll.insertAtTail(5); // cp
    dll.insertAtTail(4);
    dll.insertAtTail(2); // cp
    dll.insertAtTail(6); // cp
    dll.insertAtTail(3);
    dll.printNodes();

    vector<int> result = maxMinCriticalPointsInLL(dll);
    cout << "The minimum distance between critical points: " << result[0] << endl;
    cout << "The maximum distance between critical points: " << result[1] << endl;

    return 0;
}