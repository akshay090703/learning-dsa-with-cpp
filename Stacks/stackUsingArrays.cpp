#include <iostream>
using namespace std;

// all the methods in stack takes only O(1) time and space complexity
class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        this->top = -1;
    }

    void push(int data)
    {
        if (top == capacity - 1)
        {
            cout << "Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Underflow!" << endl;
            return INT_MIN;
        }
        top--;
        return arr[top + 1];
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Underflow!" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    int size()
    {
        return top + 1;
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