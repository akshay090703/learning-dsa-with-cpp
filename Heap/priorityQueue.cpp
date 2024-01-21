#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout << "MaxHeap using Priority Queue: " << endl;

    // by default: maxHeap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "element at Top: " << pq.top() << endl;
    pq.pop();

    cout << "element at Top: " << pq.top() << endl;
    cout << "size of maxHeap: " << pq.size() << endl;

    if (!pq.empty())
    {
        cout << "MaxHeap not empty!" << endl;
    }

    cout << "MinHeap using Priority Queue: " << endl;
    priority_queue<int, vector<int>, greater<int>> pqmin;

    pqmin.push(4);
    pqmin.push(2);
    pqmin.push(5);
    pqmin.push(3);

    cout << "element at Top: " << pqmin.top() << endl;
    pqmin.pop();

    cout << "element at Top: " << pqmin.top() << endl;
    cout << "size of minHeap: " << pqmin.size() << endl;

    if (!pqmin.empty())
    {
        cout << "MinHeap not empty!" << endl;
    }

    return 0;
}