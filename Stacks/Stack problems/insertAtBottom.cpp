#include <iostream>
#include <stack>
using namespace std;

// Iterative method
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void insertAtBottom(stack<int> &input, int data)
{
    stack<int> temp;
    while (!input.empty())
    {
        int popped_element = input.top();
        input.pop();
        temp.push(popped_element);
    }

    input.push(data);

    while (!temp.empty())
    {
        int popped_element = temp.top();
        temp.pop();
        input.push(popped_element);
    }
}

// using recursion (call stack used as temp stack)
// Time complexity -> O(n)
// Space Complexity -> O(n) ~ for call stack
void recursiveInsertAtBottom(stack<int> &input, int data)
{
    if (input.empty())
    {
        input.push(data);
        return;
    }
    int element = input.top();
    input.pop();
    recursiveInsertAtBottom(input, data);
    input.push(element);
}

int main()
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    // insertAtBottom(input, 5);
    recursiveInsertAtBottom(input, 100);
    cout << "The modified stack is: ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}