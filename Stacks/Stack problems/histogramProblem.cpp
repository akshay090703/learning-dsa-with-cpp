#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// max area = histogram * (i-j -1)
// Time Complexity -> O(n)
// Space Complexity -> O(n)
int largestRectangleHistogram(vector<int> &barHeights)
{
    int n = barHeights.size();
    stack<int> st;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && barHeights[i] < barHeights[st.top()])
        {
            int element = barHeights[st.top()]; // current bar to be removed
            int nsi = i;
            st.pop();
            int psi = (st.empty()) ? (-1) : st.top();
            ans = max(ans, element * (nsi - psi - 1));
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int element = barHeights[st.top()];
        int nsi = n;
        st.pop();
        int psi = (st.empty()) ? (-1) : st.top();
        ans = max(ans, element * (nsi - psi - 1));
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 0, 2, 1, 5, 6, 2, 3};
    cout << largestRectangleHistogram(heights);

    return 0;
}