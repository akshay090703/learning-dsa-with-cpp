#include <iostream>
using namespace std;

void increasingSequence(int n)
{
    // Base case
    if (n < 1)
        return;

    // Assumption
    increasingSequence(n - 1);

    // Self work
    cout << n << " ";
};

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Increasing Sequence: ";
    increasingSequence(num);
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// where n is the number provided by the user