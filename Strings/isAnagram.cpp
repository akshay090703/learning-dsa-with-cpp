#include <iostream>
#include <vector>
using namespace std;

bool isAnagramOrNot(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;

    int n = s1.length();
    vector<int> freqArr(26, 0);

    for (int i = 0; i < n; i++)
    {
        freqArr[s1[i] - 'a']++;
        freqArr[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freqArr[i])
            return false;
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

    string ans = isAnagramOrNot(s1, s2) ? "Anagram." : "Not Anagram.";

    cout << ans << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(length of string)
// Space complexity -> O(1)