#include <unordered_set>
#include <iostream>
using namespace std;

int main()
{
    unordered_multiset<int> ums;

    ums.insert(4);
    ums.insert(8);
    ums.insert(3);
    ums.insert(1);
    ums.insert(4);

    for (auto val : ums)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}