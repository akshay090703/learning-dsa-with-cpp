#include <iostream>
#include <vector>
using namespace std;

string countSort(string &str)
{
    int n = str.length();
    vector<int> freqArr(26, 0);

    // adding frequency of every character
    for (int i = 0; i < n; i++)
    {
        freqArr[str[i] - 'a']++;
    }

    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        while (freqArr[i]--)
        {
            ans += (i + 'a');
        }
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter a word: ";
    getline(cin, str);

    cout << "The sorted version of the word is: " << countSort(str) << endl;

    system("pause");
    return 0;
}

// Time complexity -> O(length of string)
// Space Complexity -> O(26)
// which can be assumed constant = O(1)