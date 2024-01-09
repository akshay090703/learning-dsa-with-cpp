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

// all the operations take O(1) time and space complexity
class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // like the push function
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    // like the pop function
    void dequeue()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (!head)
        {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    int front()
    {
        if (!head)
            return -1;
        return head->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    // we can also make a isFull function by giving a capacity to the queue and initializing it in the constructor
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);

    cout << "Front: " << q.front() << endl;

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;

    cout << "Front: " << q.front() << endl;

    return 0;
}