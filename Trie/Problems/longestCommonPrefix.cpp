#include <iostream>
#include <vector>
using namespace std;

// Approach 1
// max length of word -> m
// number of words -> n
// Time Complexity -> O(n*m)
// Space Complexity -> O(m)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (!match)
            break;
        else
        {
            ans.push_back(ch);
        }
    }

    return ans;
}

// Approach 2: Using Trie
struct TrieNode
{
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

struct Trie
{
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption: word will be in CAPS
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // Time Complexity -> O(length)
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void longestCommonPrefix(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal)
                break;
        }
    }
};

// Time Complexity -> O(m*n)
// Space Complexity -> O(m*n)
string longestCommonPrefixUsingTrie(vector<string> &arr)
{
    Trie *t = new Trie('\0');

    for (int i = 0; i < arr.size(); i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->longestCommonPrefix(first, ans);
    return ans;
}

int main()
{
    vector<string> v = {"ab", "abc", "abcd", "abcde"};
    // cout << "Longest Substring is: " << longestCommonPrefix(v, v.size()) << endl;
    cout << "Longest Substring is: " << longestCommonPrefixUsingTrie(v) << endl;

    return 0;
}