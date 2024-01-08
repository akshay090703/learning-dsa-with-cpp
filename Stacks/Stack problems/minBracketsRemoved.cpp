#include <iostream>
#include <stack>
using namespace std;

int minBracketsRemoved(string &brackets)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < brackets.size(); i++)
    {
        if (brackets[i] == '(' or brackets[i] == '[' or brackets[i] == '{')
        {
            st.push(brackets[i]);
        }
        else if (!st.empty() && brackets[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (!st.empty() && brackets[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else if (!st.empty() && brackets[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string str1 = "(())())))";
    cout << "Minimum number of brackets to be removed in expression : " << minBracketsRemoved(str1) << endl;

    return 0;
}