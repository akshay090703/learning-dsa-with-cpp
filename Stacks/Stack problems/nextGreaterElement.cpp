#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Time Complexity -> O(2n) ~ O(n)
// Space Complexity -> O(n)
vector<int> nextGreaterElement(int *arr, int n)
{
    vector<int> result(n, -1);
    stack<int> temp;

    for (int i = 0; i < n; i++)
    {
        while (!temp.empty() && arr[i] > arr[temp.top()])
        {
            int top = temp.top();
            result[top] = arr[i];
            temp.pop();
        }
        temp.push(i);
    }

    // when not initialized by -1.
    // while (!temp.empty())
    // {
    //     result[temp.top()] = -1;
    //     temp.pop();
    // }

    return result;
}

// Time Complexity -> O(2n) ~ O(n)
// Space Complexity -> O(n)
vector<int> nextSmallerElement(int *arr, int n)
{
    vector<int> result(n, -1);
    stack<int> temp;

    for (int i = 0; i < n; i++)
    {
        while (!temp.empty() && arr[i] < arr[temp.top()])
        {
            int top = temp.top();
            result[top] = arr[i];
            temp.pop();
        }
        temp.push(i);
    }

    // when not initialized by -1.
    // while (!temp.empty())
    // {
    //     result[temp.top()] = -1;
    //     temp.pop();
    // }

    return result;
}

// if asked about previous greater or smaller element, we can reverse the array and then find
// the next greater or smaller element and then reverse the output to get the answer
// previous greater = reverse and next smaller
// previous smaller = reverse and next greater

int main()
{
    int n = 5;
    // int arr[11] = {4, 6, 3, 1, 0, 9, 5, 6, 7, 3, 2};
    int arr[n] = {5, 4, 3, 2, 6};
    vector<int> res = nextGreaterElement(arr, n);
    cout << "Next Greater Elements are: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    res = nextSmallerElement(arr, n);
    cout << "Next Smaller Elements are: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}