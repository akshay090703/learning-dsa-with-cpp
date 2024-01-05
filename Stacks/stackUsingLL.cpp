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
        if (!head)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void deleteAtHead()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};

// all operations have time complexity -> O(1)
class Stack
{
    Node *top;
    int capacity;
    int length;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        length = 0;
        top = nullptr;
    }

    void push(int data)
    {
        if (length == capacity)
        {
            cout << "Overflow!" << endl;
            return;
        }
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        length++;
    }

    int pop()
    {
        if (!top)
        {
            cout << "Underflow" << endl;
            return INT_MIN;
        }
        Node *dummy = top;
        int poppedData = top->data;

        top = top->next;
        length--;

        delete dummy;
        return poppedData;
    }

    int getTop()
    {
        return top->data;
    }

    bool isFull()
    {
        return (length == capacity);
    }

    bool isEmpty()
    {
        return (!top);
    }

    int size()
    {
        return this->length;
    }
};

int main()
{
    Stack myStack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout << myStack.getTop() << endl;
    myStack.push(4);
    myStack.push(5);
    cout << myStack.getTop() << endl;
    myStack.push(8);
    cout << myStack.pop() << endl;
    myStack.push(8);
    cout << myStack.getTop() << endl;
    string message = myStack.isFull() ? "True" : "False";
    cout << message << endl;
    cout << myStack.size() << endl;

    return 0;
}