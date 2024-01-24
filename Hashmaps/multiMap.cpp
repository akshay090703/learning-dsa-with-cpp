#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // multimap<string, int> directory; // ordered
    unordered_multimap<string, int> directory; // unordered

    directory.insert(make_pair("Vidushi", 6312421421));
    directory.insert(make_pair("Akshay", 1324234234));
    directory.insert(make_pair("Vidushi", 1324234234));
    directory.insert(make_pair("Kanishk", 7657234234));
    directory.insert(make_pair("Ayush", 898767643));

    for (auto pair : directory)
    {
        cout << "Name - " << pair.first << endl;          // key
        cout << "Phone number - " << pair.second << endl; // value
        cout << endl;
    }

    cout << directory.count("Vidushi") << endl;

    return 0;
}