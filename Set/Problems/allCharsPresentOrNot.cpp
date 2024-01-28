#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

bool allAlphabetsPresentOrNot(string &str)
{
    if (str.length() < 26)
        return false;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    set<char> alphabets;
    for (auto ch : str)
    {
        alphabets.insert(ch);
    }

    return (alphabets.size() == 26);
}

int main()
{
    string str = "abcdEfGHIJKLmnopqrstuvWXYZ";
    // string str = "AkshayKumarPandey";
    // string str = "AkshayKumarPandeydffdfdsfsfdsf";
    string message = allAlphabetsPresentOrNot(str) ? "Yes" : "No";
    cout << "The given string contains all alphabets: ";
    cout << message << endl;

    return 0;
}