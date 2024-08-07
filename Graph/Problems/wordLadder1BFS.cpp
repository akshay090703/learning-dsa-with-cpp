//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        unordered_set<string> listWord(wordList.begin(), wordList.end());

        // word, level of the bfs
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_map<string, bool> isVisited;
        isVisited[startWord] = true;

        int len = startWord.length();
        while (!q.empty())
        {
            string curr = q.front().first;
            int lvl = q.front().second;
            q.pop();

            for (int i = 0; i < len; i++)
            {
                char currChar = curr[i];
                string temp = curr;

                for (int j = 0; j < 26; j++)
                {
                    char newChar = 'a' + j;
                    temp[i] = newChar;

                    if (currChar == newChar)
                        continue;

                    if (listWord.find(temp) != listWord.end() and !isVisited[temp])
                    {
                        q.push({temp, lvl + 1});
                        isVisited[temp] = true;

                        if (targetWord == temp)
                        {
                            return lvl + 1;
                        }
                    }
                }
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
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
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends