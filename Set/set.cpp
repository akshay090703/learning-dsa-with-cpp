#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> mySet; // increasing order
    // set<int, greater<int>> mySet; // decreasing order

    // Time Complexity -> O(log(n))
    mySet.insert(4);
    mySet.insert(2);
    mySet.insert(1);
    mySet.insert(6);

    cout << "Size: " << mySet.size() << endl;
    mySet.insert(2); // duplicate, would not be added
    cout << "Size: " << mySet.size() << endl;

    // Iteration using iterator
    set<int>::iterator it;
    // for (it = mySet.begin(); it != mySet.end(); it++)
    // {
    //     cout << *it << " "; // the iterator will point(hold position) of the values in set
    // }
    // cout << endl;

    // Iteration using for each loop
    for (auto value : mySet)
    {
        cout << value << " ";
    }
    cout << endl;

    // Time Complexity: O(log(n))
    // in case of range deletion , complexity is O(n)
    // mySet.erase(2);
    auto itr = mySet.begin();
    advance(itr, 1);
    mySet.erase(itr);

    cout << "After deleting 2: " << endl;
    for (auto value : mySet)
    {
        cout << value << " ";
    }
    cout << endl;

    // search operation
    if (mySet.find(4) != mySet.end())
    {
        cout << "Value is present" << endl;
    }
    else
    {
        cout << "Value not present" << endl;
    }

    return 0;
}