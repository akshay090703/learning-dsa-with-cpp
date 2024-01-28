#include <set>
#include <iostream>
using namespace std;

int main()
{
    // multiset<int> ms;
    multiset<int, greater<int>> ms;

    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(4);
    ms.insert(2);

    for (int val : ms)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}