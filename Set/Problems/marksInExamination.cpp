#include <unordered_set>
#include <iostream>
using namespace std;

int numOfAttemptedQuesCombinations(int n, int p, int q)
{
    unordered_set<int> combinations;

    // for correct answers
    for (int i = 0; i <= n; i++)
    {
        // for incorrect answers
        for (int j = 0; j <= n; j++)
        {
            int correct = i;
            int incorrect = j;
            int unattended = n - (i + j);

            if (unattended >= 0)
            {
                int score = correct * p + incorrect * q;
                combinations.insert(score);
            }
            else
                break;
        }
    }

    return combinations.size();
}

int main()
{
    int n = 2;
    int p = 1;
    int q = -1;
    cout << "Total num of combinations are: " << numOfAttemptedQuesCombinations(n, p, q) << endl;

    return 0;
}