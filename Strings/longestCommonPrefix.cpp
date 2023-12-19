#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> v)
{
    string ans = "";
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    // sort(v.begin(), v.end()); // inbuilt function for sorting vector
    // Time complexity -> O(nlogn)

    int i = 0;
    while (v[0][i] && v[n - 1][i])
    {
        if (v[0][i] == v[n - 1][i])
            ans += v[0][i];
        else
            break;

        i++;
    }
    return ans;
}

string alternativeApproach(vector<string> &v)
{
    string prevStr = v[0];
    int count = prevStr.size();

    for (int i = 1; i < v.size(); i++)
    {
        int j = 0;
        while (j < prevStr.size() && j < v[i].size() && prevStr[j] == v[i][j])
            j++;

        count = min(count, j); // updating length of answer string
    }

    string ans = prevStr.substr(0, count);
    return ans;
}

int main()
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    vector<string> v(size);
    cout << "Enter the strings in the array: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    // cout << "The longest common prefix string amongst the array of strings is: " << longestCommonPrefix(v) << endl;
    cout << "The longest common prefix string amongst the array of strings is: " << alternativeApproach(v) << endl;

    system("pause");
    return 0;
}

// n -> number of strings in an array
// Time complexity -> O(n*n)
// Space complexity -> O(1)

// Alternative approach
// Time complexity -> O(n*m)
// Space complexity -> O(1)
// n -> number of strings
// m -> length of string