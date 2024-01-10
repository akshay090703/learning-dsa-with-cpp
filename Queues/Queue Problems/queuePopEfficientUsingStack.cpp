#include <iostream>
#include <stack>
using namespace std;

// Pop efficient
// here push function is like add at bottom function in stack
class Queue
{
    stack<int> st;

public:
    Queue() {}

    // push - time and space complexity -> O(n)
    void push(int data)
    {
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(data);

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    // pop - time and space complexity -> O(1)
    void pop()
    {
        if (st.empty())
        {
            cout << "Underflow!" << endl;
            return;
        }

        st.pop();
    }

    bool isEmpty()
    {
        return st.empty();
    }

    // front - time and space complexity -> O(1)
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }
        return st.top();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.push(4);

    while (!q.isEmpty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}