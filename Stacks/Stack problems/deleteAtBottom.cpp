#include <iostream>
#include <stack>
using namespace std;

// Iterative method
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void deleteAtBottom(stack<int> &input)
{
    if (input.empty())
    {
        std::cout << "Stack is empty. Cannot delete from an empty stack." << std::endl;
        return;
    }

    stack<int> temp;
    while (input.size() != 1)
    {
        int popped_element = input.top();
        input.pop();
        temp.push(popped_element);
    }

    input.pop();

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
void recursivedeleteAtBottom(stack<int> &input)
{
    if (input.size() == 1)
    {
        input.pop();
        return;
    }
    int element = input.top();
    input.pop();
    recursivedeleteAtBottom(input);
    input.push(element);
}

int main()
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    // deleteAtBottom(input);
    recursivedeleteAtBottom(input);
    cout << "The modified stack is: ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}