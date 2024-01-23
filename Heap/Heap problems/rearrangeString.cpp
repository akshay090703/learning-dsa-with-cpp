#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string reArrangeString(string &s)
{
    priority_queue<pair<int, char>> maxHeap;
    unordered_map<char, int> charFrequencyMap;

    for (char ch : s)
    {
        charFrequencyMap[ch]++;
    }

    for (auto entry : charFrequencyMap)
    {
        maxHeap.push({entry.second, entry.first});
    }

    pair<int, char> previousEntry = {-1, '#'};
    string result = "";

    while (!maxHeap.empty())
    {
        pair<int, char> currentEntry = maxHeap.top();
        maxHeap.pop();

        result += currentEntry.second;
        currentEntry.first--;

        if (previousEntry.first > 0)
        {
            maxHeap.push(previousEntry);
        }

        previousEntry = currentEntry;
    }

    return result.length() == s.length() ? result : "not possible";
}

int main()
{
    string str = "baaba";
    // string str = "qaacde";
    // string str = "bbbbbb";
    // string str = "coding";
    string res = reArrangeString(str);
    cout << "Re-arranged String: " << res << endl;

    return 0;
}

// Yes
// Yes
// Yes
// Yes
// Yes
// Yes
// Yes
// Yes

// No
// Yes
// Yes
// Yes
// Yes
// Yes
// Yes
// Yes

// 8
// baaba
// huijahsj
// opiijakdf
// vvvio
// aaaaaaaaaa
// codechefvscodeforces
// internship
// zooo