#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(8);
    dq.push_front(4);
    dq.push_front(0);
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << endl;

    // while (!dq.empty())
    // {
    //     cout << dq.front() << " ";
    //     dq.pop_front();
    // }
    // cout << endl;

    return 0;
}