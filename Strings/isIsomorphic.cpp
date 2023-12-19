#include <iostream>
#include <vector>
using namespace std;

// one to one mapping -> Isomorphic
bool isIsomorphicOrNot(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;

    int n = s1.length();

    vector<int> freqArr1(26, -1);
    vector<int> freqArr2(26, -1);
    for (int i = 0; i < n; i++)
    {
        if (freqArr1[s1[i] - 'a'] == -1 && freqArr2[s2[i] - 'a'] == -1)
        {
            freqArr1[s1[i] - 'a'] = i;
            freqArr2[s2[i] - 'a'] = i;
        }
        else
        {
            if (freqArr1[s1[i] - 'a'] != freqArr2[s2[i] - 'a'])
                return false;
        }
    }
    return true;
}

int main()
{
    cout << "Give your first string: ";
    string s1;
    cin >> s1;

    cout << "Give your second string: ";
    string s2;
    cin >> s2;

    string ans = isIsomorphicOrNot(s1, s2) ? "Isomorphic." : "Not Isomorphic.";

    cout << ans << endl;

    system("pause");
    return 0;
}

// n -> length of the string
// Time Complexity -> O(n)
// Space Complexity -> O(52) = O(1)