#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // All operations take O(1) complexity for unordered map
    // All operations take O(log(n)) complexity for ordered map

    // creation
    // unordered_map<string, int> m;
    map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("Akshay", 3);
    m.insert(p);

    pair<string, int> q("Kumar", 2);
    m.insert(q);

    m["Pandey"] = 1;

    // Updating
    m["Kumar"] = 4;

    // Searching
    cout << m["Kumar"] << endl;
    cout << m.at("Akshay") << endl;

    // cout << m.at("unknownKey") << endl;
    cout << m["unknownKey"] << endl;

    // size
    cout << m.size() << endl;

    // to check presence
    cout << m.count("bro") << endl; // returns 0 or 1
    cout << m.count("Akshay") << endl;

    // erase
    m.erase("Kumar");
    cout << m.size() << endl;

    // using forEach loop
    // for (auto i : m)
    // {
    //     cout << i.first << " : " << i.second << "\n";
    // }

    // iterator
    // unordered_map<string, int>::iterator it = m.begin(); // random order
    map<string, int>::iterator it = m.begin(); // preserved order
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}