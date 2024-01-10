#include <iostream>
#include <vector>
using namespace std;

// Using Arrays
// All the operations takes O(1) time and space complexity
class Queue
{
    int front;
    int back;
    vector<int> v;
    int length;
    int total_length;

public:
    Queue(int size)
    {
        v.resize(size);
        back = size - 1;
        front = -1;
        length = 0;
        total_length = size;
    }

    void enqueue(int data)
    {
        if (isFull())
            return;

        if (front == -1)
        {
            front = 0;
        }

        back = (back + 1) % total_length;
        v[back] = data;
        length++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;

        this->front = (front + 1) % total_length;
        length--;
    }

    int getFront()
    {
        if (front == -1)
            return -1;
        return v[front];
    }

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == total_length;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.enqueue(4);

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << endl;

    return 0;
}