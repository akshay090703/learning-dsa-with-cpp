#include <iostream>
#include <vector>
using namespace std;

void subsequences(string str, int n, int i, string currentSubsequence, vector<string> &v)
{
    if (i == n)
    {
        v.push_back(currentSubsequence);
        return;
    };

    // Includes the char
    subsequences(str, n, i + 1, currentSubsequence + str[i], v);

    // does not include the char
    subsequences(str, n, i + 1, currentSubsequence, v);
};

int main()
{
    string str;
    cout << "Enter your string: ";
    cin >> str;

    int length = str.length();
    string currentStr = "";
    vector<string> v;
    subsequences(str, length, 0, currentStr, v);

    cout << "All possible subsequences are: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    };

    return 0;
}