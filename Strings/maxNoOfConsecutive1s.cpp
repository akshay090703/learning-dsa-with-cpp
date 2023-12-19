#include <iostream>
#include <vector>
using namespace std;

// brute force
int maxNoOf1s(string &str, int &k)
{
    int numOf1s = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int numOf0s = 0;
        int temp1s = 0;

        int j = i;
        while (numOf0s <= k && j < str.length())
        {
            if (str[j] == '0')
                numOf0s++;
            else
                temp1s++;

            if (j == str.length() - 1)
                break;
            j++;
        }
        if (numOf1s <= temp1s)
            numOf1s = temp1s;
    }
    return numOf1s + k;
}

// Sliding window approach
int slidingWindowApproach(string &str, int &k)
{
    int zero_count = 0;
    int max_length = 0;
    int starting_point = 0, ending_point = 0;

    for (; ending_point < str.length(); ending_point++)
    {
        if (str[ending_point] == '0')
            zero_count++;

        while (zero_count > k)
        {
            if (str[starting_point] == '0')
                zero_count--;

            starting_point++; // contracting our window}
        }
        max_length = max(max_length, ending_point - starting_point + 1);
    };
    return max_length;
}

int main()
{
    cout << "Enter a string of 0s and 1s: ";
    string str;
    cin >> str;

    cout << "Enter the value of k: ";
    int k;
    cin >> k;

    // cout << "The maximum number of consecutive 1s if we flip k 0s: " << maxNoOf1s(str, k) << endl;
    cout << "The maximum number of consecutive 1s if we flip k 0s: " << slidingWindowApproach(str, k) << endl;

    system("pause");
    return 0;
}

// brute force approach
// time complexity -> O(n^2)
// space complexity -> O(1)

// Sliding Window Technique
// time complexity -> O(n)
// space complexity -> O(1)

// n -> length of binary string