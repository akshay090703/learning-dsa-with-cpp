#include <unordered_set>
#include <iostream>
using namespace std;

int main()
{
    unordered_set<int> s1;

    s1.insert(3);
    s1.insert(4);
    s1.insert(1);
    s1.insert(2);
    s1.insert(1);

    for (auto val : s1)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}