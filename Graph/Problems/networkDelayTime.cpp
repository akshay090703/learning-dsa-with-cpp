#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adjList[u].push_back({v, time});
        }

        // currTime : node
        // priority queue not really needed as we only go to the neighbours when the curr time is lesser than the time in timer array
        queue<pair<int, int>> q;
        vector<int> timer(n + 1, INT_MAX);

        q.push({0, k});
        timer[k] = 0;
        while (!q.empty())
        {
            int currTime = q.front().first;
            int node = q.front().second;
            q.pop();

            if (currTime > timer[node])
                continue;

            for (auto neighbour : adjList[node])
            {
                int v = neighbour.first;
                int timeNeeded = neighbour.second;

                if (timer[v] > currTime + timeNeeded)
                {
                    timer[v] = currTime + timeNeeded;
                    q.push({currTime + timeNeeded, v});
                }
            }
        }

        int totalTime = 0;
        for (int i = 1; i <= n; i++)
        {
            if (timer[i] == INT_MAX)
                return -1;
            else
                totalTime = max(totalTime, timer[i]);
        }

        return totalTime;
    }
};

int main()
{

    return 0;
}