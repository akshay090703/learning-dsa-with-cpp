#include <iostream>
#include <stack>
using namespace std;

// Iterative Method - uses the 0 based indexing
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void insertAtKIndex(stack<int> &input, int data, int idx)
{
    stack<int> temp;
    int itr = 0;
    int n = input.size();
    if (n < idx)
        return;
    while (itr < (n - idx))
    {
        itr++;
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    input.push(data);

    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        input.push(curr);
    }
}

// recursively (call stack)
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void recursivelyInsertAtKthIndex(stack<int> &input, int data, int idx, int itr = 0)
{
    static int n = input.size();
    if (n < idx)
        return;

    if (itr >= (n - idx))
    {
        input.push(data);
        return;
    }

    int curr = input.top();
    input.pop();
    recursivelyInsertAtKthIndex(input, data, idx, itr + 1);
    input.push(curr);
}

int main()
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    // insertAtKIndex(input, 100, 0);
    recursivelyInsertAtKthIndex(input, 100, 0);
    cout
        << "The modified stack is: ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}