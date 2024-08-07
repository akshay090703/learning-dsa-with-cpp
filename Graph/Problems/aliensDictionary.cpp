//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<vector<int>> adjList(K);
        for (int i = 0; i < N - 1; i++)
        {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.size(), word2.size());

            for (int j = 0; j < len; j++)
            {
                if (word1[j] != word2[j])
                {
                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';
                    adjList[u].push_back(v);
                    break;
                }
            }
        }

        vector<int> inDegree(K, 0);
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                inDegree[adjList[i][j]]++;
            }
        }

        queue<int> q;
        string order = "";
        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                order.push_back('a' + i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbour : adjList[node])
            {
                inDegree[neighbour]--;

                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    order.push_back('a' + neighbour);
                }
            }
        }

        if (order.length() != K)
            return "";

        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends