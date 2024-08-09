//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> listWord(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (listWord.find(endWord) == listWord.end())
            return result;

        queue<vector<string>> q;
        q.push({beginWord});
        listWord.erase(beginWord);

        bool found = false;
        vector<string> visitedInLevel;
        while (!q.empty() and !found)
        {
            int size = q.size();
            visitedInLevel.clear();

            while (size--)
            {
                vector<string> seq = q.front();
                string curr = seq.back();
                q.pop();

                for (int i = 0; i < beginWord.length(); i++)
                {
                    char currChar = curr[i];

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (currChar == ch)
                            continue;
                        curr[i] = ch;

                        if (listWord.find(curr) != listWord.end())
                        {
                            seq.push_back(curr);

                            if (curr == endWord)
                            {
                                result.push_back(seq);
                                found = true;
                            }
                            else
                            {
                                visitedInLevel.push_back(curr);
                                q.push({seq});
                            }

                            seq.pop_back();
                        }
                    }

                    curr[i] = currChar;
                }
            }

            for (const string &visited : visitedInLevel)
            {
                listWord.erase(visited);
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends