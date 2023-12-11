#include <iostream>
#include <vector>
using namespace std;

string chars[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void letter_combinations(string &digits, vector<string> &v, int i, string current_combination)
{
    if (current_combination.length() == digits.length())
    {
        v.push_back(current_combination);
        return;
    };

    int digit = digits[i] - '0';
    if (digit <= 1)
    {
        letter_combinations(digits, v, i + 1, current_combination);
        return;
    };

    for (int j = 0; j < chars[digit].length(); j++)
    {
        letter_combinations(digits, v, i + 1, current_combination + chars[digit][j]);
    };
    return;
};

int main()
{
    string digits;
    cout << "Give the number: ";
    cin >> digits;

    vector<string> combinations;

    letter_combinations(digits, combinations, 0, "");

    cout << "The combinations are: " << endl;
    for (auto i : combinations)
    {
        cout << i << endl;
    };

    return 0;
}