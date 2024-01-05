#include <iostream>
#include <stack>
using namespace std;

// Time Complexity -> O(n)
// Space Complexity -> O(n)
stack<int> copyStack(stack<int> &input)
{
    stack<int> temp;
    while (!input.empty())
    {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> output;
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        output.push(curr);
    }

    return output;
}

// using recursion (here we will use call stack instead of temp stack)
// Time Complexity -> O(n)
// Space Complexity -> O(n) {~ O(2n) = call stack + result stack}
stack<int> recursiveCopyStack(stack<int> &input)
{
    static stack<int> result;
    if (input.empty())
    {
        return result;
    }
    int popped_element = input.top();
    input.pop();
    recursiveCopyStack(input);
    result.push(popped_element);
    return result;
}

int main()
{
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    // stack<int> copy = copyStack(myStack);
    stack<int> copy = recursiveCopyStack(myStack);
    while (!copy.empty())
    {
        int curr = copy.top();
        copy.pop();
        cout << curr << " ";
    }

    return 0;
}