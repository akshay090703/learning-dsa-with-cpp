#include <iostream>
#include <stack>
using namespace std;

// Iterative Method - uses the 0 based indexing
// Time Complexity -> O(n)
// Space Complexity -> O(n)
void deleteAtKIndex(stack<int> &input, int idx)
{
    stack<int> temp;
    int itr = 0;
    int n = input.size();
    if (n < idx)
        return;
    while (itr < (n - idx) - 1)
    {
        itr++;
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    input.pop();

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
void recursivelyDeleteAtKthIndex(stack<int> &input, int idx, int itr = 0)
{
    static int n = input.size();
    if (n < idx)
        return;

    if (itr >= (n - idx) - 1)
    {
        input.pop();
        return;
    }

    int curr = input.top();
    input.pop();
    recursivelyDeleteAtKthIndex(input, idx, itr + 1);
    input.push(curr);
}

int main()
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    // deleteAtKIndex(input, 1);
    recursivelyDeleteAtKthIndex(input, 3);
    cout
        << "The modified stack is: ";
    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }

    return 0;
}