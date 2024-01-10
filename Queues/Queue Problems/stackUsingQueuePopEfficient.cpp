#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    Stack() {}

    void push(int data)
    {
        queue<int> temp;

        while (!q.empty())
        {
            temp.push(q.front());
            q.pop();
        }

        q.push(data);

        while (!temp.empty())
        {
            q.push(temp.front());
            temp.pop();
        }
    }

    void pop()
    {
        if (q.empty())
            return;
        q.pop();
    }

    int front()
    {
        if (q.empty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty()
    {
        return q.empty();
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.push(5);

    while (!st.isEmpty())
    {
        cout << st.front() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}