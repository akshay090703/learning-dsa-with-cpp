#include <iostream>
#include <math.h>
#include <stack>
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

int postfixExpression(string expression)
{
    stack<int> st;
    int n = expression.size();
    for (int i = 0; i < n; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            st.push(expression[i] - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int calculation = eval(op1, op2, expression[i]);
            st.push(calculation);
        }
    }
    return st.top();
}

int main()
{
    string exp = "231*+9-";
    cout << postfixExpression(exp) << endl;

    return 0;
}