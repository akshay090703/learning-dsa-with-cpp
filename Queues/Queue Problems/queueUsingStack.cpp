#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> st;

public:
    Queue() {}

    // push - time and space complexity -> O(1)
    void push(int x)
    {
        st.push(x);
    }

    // pop - time and space complexity -> O(n)
    void pop()
    {
        if (st.empty())
            return;
        stack<int> temp;
        while (st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }

        st.pop();

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    bool isEmpty()
    {
        return st.empty();
    }

    // front - time and space complexity -> O(n)
    int front()
    {
        if (st.empty())
            return -1;
        stack<int> temp;
        while (st.size() > 1)
        {
            temp.push(st.top());
            st.pop();
        }

        int result = st.top();

        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return result;
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