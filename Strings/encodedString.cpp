#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string encodedPatternStr(string &str)
{
    int n = str.length();
    string ans = "", num = "";
    int int_num = 0;

    for (int i = 0; i < n; i++)
    {
        // until ']', add the elements in the ans string
        if (str[i] != ']')
            ans += str[i];
        else
        {
            string substr = "";

            // extract substr from ans
            while (!ans.empty() && ans.back() != '[')
            {
                substr.push_back(ans.back());
                ans.pop_back();
            }

            // reversing the substr
            reverse(substr.begin(), substr.end());

            // remove last char from result which is '['
            ans.pop_back();

            // extract num from ans
            while (!ans.empty() && (ans.back() >= '0' && ans.back() <= '9'))
            {
                num.push_back(ans.back());
                ans.pop_back();
            }

            // reversing the num string
            reverse(num.begin(), num.end());

            // converting string to integer
            int_num = stoi(num);

            // inserting str in ans int_num times
            while (int_num)
            {
                ans += substr;
                int_num--;
            }

            // clear the num string for the next iteration
            num = "";
        }
    }
    return ans;
}

int main()
{
    cout << "Enter the encoded string: ";
    string str;
    getline(cin, str);

    cout << "The pattern of the encoded string is: \n";
    cout << encodedPatternStr(str) << endl;

    return 0;
}

// Space complexity -> O(n)
// Time complexity -> O(n)
// where n is hte length of decoded string