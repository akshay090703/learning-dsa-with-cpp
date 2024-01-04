#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l1 = {1, 2, 3, 4};
    // list<int>::iterator itr; // this is how iterator can be defined
    // auto itr = l1.begin(); // first element pointer
    // auto itr2 = l1.end();  // returns last +1 element position

    // advance(itr, 2); // now it points to 3rd element
    // cout << *itr << endl;
    // cout << *itr2 << endl;

    // using range_based loops
    // for (auto num : l1)
    // {
    //     cout << num << endl;
    // }

    // using iterators
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // reverse traversal
    // for (auto itr = l1.rbegin(); itr != l1.rend(); itr++)
    // {
    //     cout << *itr << " ";
    // }
    // cout << endl;

    // inserting elements
    auto itr = l1.begin();
    advance(itr, 2);
    // l1.insert(itr, 2, 5)

    auto l = l1.begin();
    auto r = l1.begin();
    advance(r, 2);
    l1.insert(itr, l, r);
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // 1 2 1 2 3 4
    auto s_itr = l1.begin();
    advance(s_itr, 2); // now s_itr pointing to 3rd element // 1
    auto e_itr = l1.begin();
    advance(e_itr, 4); // now e_itr pointing to 5th element // 3
    l1.erase(s_itr, e_itr);
    for (auto itr = l1.begin(); itr != l1.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}