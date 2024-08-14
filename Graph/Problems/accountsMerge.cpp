//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUlParent(int u)
    {
        if (u == parent[u])
            return u;

        return parent[u] = findUlParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int ulParentU = findUlParent(u);
        int ulParentV = findUlParent(v);

        if (ulParentU == ulParentV)
            return;

        int sizeU = size[ulParentU];
        int sizeV = size[ulParentV];

        if (sizeU >= sizeV)
        {
            size[ulParentU] += size[ulParentV];
            parent[ulParentV] = ulParentU;
        }
        else
        {
            size[ulParentV] += size[ulParentU];
            parent[ulParentU] = ulParentV;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string str = accounts[i][j];

                if (m.find(str) == m.end())
                {
                    m[str] = i;
                }
                else
                {
                    ds.unionBySize(i, m[str]);
                }
            }
        }

        vector<vector<string>> temp(n);
        for (auto p : m)
        {
            string str = p.first;
            int ulParent = ds.findUlParent(p.second);

            temp[ulParent].push_back(str);
        }

        vector<vector<string>> result;
        for (int i = 0; i < n; i++)
        {
            if (!temp[i].empty())
            {
                vector<string> account;

                account.push_back(accounts[i][0]);
                account.insert(account.end(), temp[i].begin(), temp[i].end());
                sort(account.begin() + 1, account.end());

                result.push_back(account);
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends