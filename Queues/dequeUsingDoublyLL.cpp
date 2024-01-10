#include <iostream>
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

class Deque
{
    Node *head;
    Node *tail;
    int length;
    int capacity;

public:
    Deque(int capacity)
    {
        head = tail = nullptr;
        this->capacity = capacity;
        this->length = 0;
    };

    void push_front(int data)
    {
        if (length >= capacity)
        {
            cout << "Overflow!" << endl;
            return;
        }
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            length++;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }

    void push_back(int data)
    {
        if (length >= capacity)
        {
            cout << "Overflow!" << endl;
            return;
        }
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
            length++;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }

    void pop_front()
    {
        if (length <= 0)
        {
            cout << "Underflow!"
                 << " " << endl;
            return;
        }

        if (head == tail)
        {
            Node *temp = head;
            head = tail = nullptr;
            delete temp;
            length--;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        length--;
    }

    void pop_back()
    {
        if (length <= 0)
        {
            cout << "Underflow!"
                 << " " << endl;
            return;
        }

        if (head == tail)
        {
            Node *temp = head;
            head = tail = nullptr;
            delete temp;
            length--;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    bool isFull()
    {
        return (length == capacity);
    }

    int front()
    {
        if (!isEmpty())
        {
            return head->data;
        }
        else
        {
            return -1;
        }
    }

    int back()
    {
        if (!isEmpty())
        {
            return tail->data;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    Deque dq(6);
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(8);
    dq.push_front(4);
    dq.push_front(0);
    dq.pop_back();
    dq.pop_front();
    cout << dq.size() << endl;
    while (!dq.isEmpty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;

    return 0;
}