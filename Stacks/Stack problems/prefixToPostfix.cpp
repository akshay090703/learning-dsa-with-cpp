#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Time Complexity -> O(n)
// Space Complexity -> O(n)
string prefixToPostfix(string &prefixEx)
{
    stack<string> st;
    reverse(prefixEx.begin(), prefixEx.end());
    for (int i = 0; i < prefixEx.size(); i++)
    {
        if (isdigit(prefixEx[i]))
        {
            st.push(to_string(prefixEx[i] - '0'));
        }
        else
        {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            string newExp = v1 + v2 + prefixEx[i];
            st.push(newExp);
        }
    }
    return st.top();
}

int main()
{
    string str = "*+31-15";
    cout << "Postfix Expression: " << prefixToPostfix(str) << endl;

    return 0;
}