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

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' or ch == '/')
        return 2;
    else if (ch == '+' or ch == '-')
        return 1;
    else
        return -1;
}

int infixEvaluation(string &expression)
{
    int n = expression.size();
    stack<int> nums;
    stack<char> ops;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(expression[i]))
        {
            int x = expression[i] - '0';
            nums.push(x);
        }
        else if (expression[i] == '(')
        {
            ops.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                char c = ops.top();
                ops.pop();
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(eval(num1, num2, c));
            }
            if (!ops.empty())
                ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i]))
            {
                char c = ops.top();
                ops.pop();

                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(eval(num1, num2, c));
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty())
    {
        char c = ops.top();
        ops.pop();

        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        nums.push(eval(num1, num2, c));
    }
    return nums.top();
}

int main()
{
    string str = "1+(2*(3-1))+2";
    cout << infixEvaluation(str) << endl;

    return 0;
}