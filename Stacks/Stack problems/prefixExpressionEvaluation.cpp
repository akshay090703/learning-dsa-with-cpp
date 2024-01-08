#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int eval(int operand1, int operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '^':
        return pow(operand1, operand2);
    default:
        return 0;
    }
}

int prefixEvaluation(string &expression)
{
    stack<int> s;
    int n = expression.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            s.push(expression[i] - '0');
        }
        else
        {
            int v2 = s.top();
            s.pop();
            int v1 = s.top();
            s.pop();
            s.push(eval(v1, v2, expression[i]));
        }
    }
    return s.top();
}

int main()
{
    string exp = "-9+*132";
    cout << prefixEvaluation(exp) << endl;

    return 0;
}