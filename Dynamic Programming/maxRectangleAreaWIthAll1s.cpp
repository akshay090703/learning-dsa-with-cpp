//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int maxHistogramRectange(vector<int> &row, int m, stack<int> &st)
    {
        int maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            while (!st.empty() and row[st.top()] > row[i])
            {
                int height = row[st.top()];
                st.pop();

                // next smaller element idx
                int nse = i;
                // previous smaller element idx
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        while (!st.empty())
        {
            int height = row[st.top()];
            st.pop();

            int nse = m;
            int pse = st.empty() ? -1 : st.top();

            int width = nse - pse - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    int solve(int M[MAX][MAX], int n, int m)
    {
        vector<int> temp(m, 0);

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                    temp[j]++;
                else
                    temp[j] = 0;
            }

            maxArea = max(maxArea, maxHistogramRectange(temp, m, st));
        }

        return maxArea;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        return solve(M, n, m);
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends