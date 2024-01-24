#include <iostream>
#include <map>
using namespace std;

// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)
bool isIsomorphicStrings(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    map<char, int> m1;
    map<char, int> m2;
    for (int i = 0; i < str1.length(); i++)
    {
        m1[str1[i]]++;
        m2[str2[i]]++;
        if (m1[str1[i]] != m2[str2[i]])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1 = "aab";
    string str2 = "xxy";
    // string str1 = "abcdec";
    // string str2 = "viouog";
    string ans = isIsomorphicStrings(str1, str2) ? "Yes" : "No";
    cout << "Are the strings are Isomorphic: " << ans << endl;

    return 0;
}