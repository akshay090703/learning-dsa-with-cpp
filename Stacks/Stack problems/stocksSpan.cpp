#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

// we basically have to find the previous smaller (reverse and next greater) or equal to count
// Time Complexity -> O(n)
// Space Complexity -> O(n)
vector<int> stockSpan(vector<int> &stockPrices)
{
    int n = stockPrices.size();
    stack<int> stockSpan;
    vector<int> result(n, 1);
    reverse(stockPrices.begin(), stockPrices.end());

    for (int i = 0; i < n; i++)
    {
        while (!stockSpan.empty() && stockPrices[i] > stockPrices[stockSpan.top()])
        {
            int top = stockSpan.top();
            result[top] = i - top;
            stockSpan.pop();
        }
        stockSpan.push(i);
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(stocks);
    cout << "The Stock Span values are: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}