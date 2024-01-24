#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    unordered_map<char, int> strMap1;
    unordered_map<char, int> strMap2;
    for (int i = 0; i < str1.size(); ++i)
    {
        strMap1[str1[i]]++;
        strMap2[str2[i]]++;
    }

    for (auto i : strMap1)
    {
        if (strMap2.find(i.first) == strMap2.end())
        {
            return false;
        }
        else
        {
            if (abs(i.second - strMap2[i.first]) != 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string str1 = "triangle";
    string str2 = "integral";
    string ans = isAnagram(str1, str2) ? "Yes" : "No";
    cout << "Are they anagram: " << ans << endl;

    return 0;
}