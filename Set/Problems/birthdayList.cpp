#include <set>
#include <iostream>
using namespace std;

int main()
{
    // automatically sorted lexicographically
    set<string> inviteList;

    int n;
    cout << "Number of friends invited: ";
    cin >> n;

    while (n--)
    {
        string name;
        cout << "Enter friend's name: ";
        cin >> name;

        inviteList.insert(name);
    }

    cout << "Invite list:" << endl;
    for (auto name : inviteList)
    {
        cout << name << endl;
    }

    return 0;
}