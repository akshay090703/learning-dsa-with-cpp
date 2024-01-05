#include <iostream>
#include <stack>
using namespace std;

// iterative approach
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void reverseStack(stack<int> &input)
{
    stack<int> temp1;
    while (!input.empty())
    {
        int curr = input.top();
        input.pop();
        temp1.push(curr);
    }

    stack<int> temp2;
    while (!temp1.empty())
    {
        int curr = temp1.top();
        temp1.pop();
        temp2.push(curr);
    }

    while (!temp2.empty())
    {
        int curr = temp2.top();
        temp2.pop();
        input.push(curr);
    }
}

// this can also be done recursively using insert at bottom external function
// Time Complexity -> O(n^2) because of insertAtBottom function
// Space Complexity -> O(n)
// recursive approach
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

void reverseStackRecursively(stack<int> &input)
{
    if (input.empty())
        return;
    int curr = input.top();
    input.pop();
    reverseStackRecursively(input);
    insertAtBottom(input, curr);
}

int main()
{
    stack<int> input;
    input.push(4);
    input.push(3);
    input.push(2);
    input.push(1);
    // reverseStack(input);
    reverseStackRecursively(input);
    cout
        << "The reversed stack is: ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}