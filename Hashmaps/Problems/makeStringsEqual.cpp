#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity -> O(n*m)
// Space Complexity -> O(n*m)
string isMakeStringsEqual(vector<string> &input)
{
    unordered_map<char, int> charOccurance;
    for (auto str : input)
    {
        for (auto alphabet : str)
        {
            charOccurance[alphabet]++;
        }
    }

    for (auto pair : charOccurance)
    {
        if (pair.second % input.size() != 0)
            return "No";
    }

    return "Yes";
}

int main()
{
    // vector<string> input = {"collegeee", "coll", "collegge"};
    vector<string> input = {"wall", "ah", "wallahah"};
    cout << "Is making these strings equal possible: " << isMakeStringsEqual(input) << endl;

    return 0;
}