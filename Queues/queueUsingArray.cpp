#include <iostream>
using namespace std;

// All operations take O(1) time and space complexity
// we could have used vectors here but instead we made the queue from scratch
// using traditional dynamic memory using array
// with vectors, we would've written less lines of code
class Queue
{
    int *arr;
    int size;
    int capacity;
    int front;
    int back;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
        front = -1;
        back = -1;
    }

    void enqueue(int data)
    {
        if (front == -1)
        {
            front = back = 0;
            arr[front] = data;
            size++;
            return;
        }
        if (size == capacity)
        {
            cout << "Overflow!" << endl;
            return;
        }
        back++;
        arr[back] = data;
        size++;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Underflow!" << endl;
            return;
        }

        if (front == back)
        {
            front = back = -1;
        }
        else
        {
            front++;
        }

        size--;
    }

    int getFront()
    {
        if (front == -1)
        {
            // cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    int getSize()
    {
        return this->size;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    cout << "Size: " << q.getSize() << endl;
    cout << "Front: " << q.getFront() << endl;
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    q.enqueue(4);

    cout << "Front: " << q.getFront() << endl;

    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << endl;

    q.enqueue(3);
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;

    return 0;
}