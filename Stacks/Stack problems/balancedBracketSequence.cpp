#include <iostream>
#include <stack>
using namespace std;

// Time Complexity -> O(n)
// Space Complexity -> O(n) // of stack in worst case
bool isBalancedBracketSequence(string &bracketStr)
{
    stack<char> brackets;
    for (int i = 0; i < bracketStr.length(); i++)
    {
        if (!brackets.empty())
        {
            char top = brackets.top();
            if (bracketStr[i] == '(' || bracketStr[i] == '{' || bracketStr[i] == '[')
            {
                brackets.push(bracketStr[i]);
            }
            else if (!brackets.empty() && bracketStr[i] == ')' && top == '(')
            {
                brackets.pop();
            }
            else if (!brackets.empty() && bracketStr[i] == '}' && top == '{')
            {
                brackets.pop();
            }
            else if (!brackets.empty() && bracketStr[i] == ']' && top == '[')
            {
                brackets.pop();
            }
            else
                continue;
        }
        else
        {
            brackets.push(bracketStr[i]);
        }
    }
    return brackets.empty();
}

int main()
{
    string brackets = "({{Akshay}[Kumar]}()(Pandey))";
    string answer = isBalancedBracketSequence(brackets) ? "Balanced." : "Not Balanced.";
    cout << answer << endl;

    return 0;
}