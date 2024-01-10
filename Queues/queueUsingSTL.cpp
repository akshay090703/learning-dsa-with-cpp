#include <iostream>
#include <queue>
using namespace std;

// In STL queue, enqueue is push and dequeue is pop
int main()
{
    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.pop();
    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;

    return 0;
}