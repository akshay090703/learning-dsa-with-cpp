#include <iostream>
using namespace std;

string removeOccurances(string &str, int i, int n, char x)
{
    if (i == n)
        return "";

    string curr = "";
    curr += str[i];

    return (str[i] == x ? "" : curr) + removeOccurances(str, i + 1, n, x);
};

int main()
{
    string str;
    char s;
    cout << "Enter a string: ";
    cin >> str;
    int length = str.length();
    cout << "Enter the character to be removed: ";
    cin >> s;

    cout << "String after removing the occurances: " << removeOccurances(str, 0, length, s) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)