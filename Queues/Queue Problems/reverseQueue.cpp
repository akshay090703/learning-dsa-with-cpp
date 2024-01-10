#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reversingQueue(queue<int> &qu)
{
    if (qu.size() <= 1)
        return;

    stack<int> st;
    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();
        st.push(x);
    }

    while (!st.empty())
    {
        int x = st.top();
        st.pop();
        qu.push(x);
    }
}

void printingQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << "Original Queue: ";
    printingQueue(q);

    reversingQueue(q);
    cout << "Reversed Queue: ";
    printingQueue(q);

    return 0;
}