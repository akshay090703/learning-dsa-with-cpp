#include <iostream>
using namespace std;

struct TrieNode
{
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

struct Trie
{
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption: word will be in CAPS
        int index = word[0] - 'A';
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
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    // Time Complexity -> O(length)
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    // Time Complexity -> O(length)
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return;

        int index = word[0] - 'A';
        TrieNode *child = root->children[index];

        // word not found
        if (!child)
            return;

        if (word.length() == 1 && child->isTerminal)
        {
            child->isTerminal = false;
            root->children[index] = NULL;
        }

        deleteUtil(child, word.substr(1));
    }

    // Time Complexity -> O(length)
    void deletion(string word)
    {
        deleteUtil(root, word);
    }

    // Time COmplexity -> O(length)
    bool prefixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index])
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCD");
    cout << "Present or Not: " << t->searchWord("ABCD") << endl;
    cout << "Prefix or Not: " << t->startsWith("ABC") << endl;

    t->deletion("ABCD");
    cout << "Present or Not: " << t->searchWord("ABCD") << endl;
    cout << "Prefix or Not: " << t->startsWith("ABC") << endl;

    return 0;
}