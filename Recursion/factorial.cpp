#include <iostream>
using namespace std;

// Recursive Function
int factorial(int n)
{
    // Base Case
    if (n == 1)
        return 1;

    // Safework with Assumption
    return n * factorial(n - 1);
};

int main()
{
    int result = factorial(5);

    cout << "Factorial: " << result << endl;

    return 0;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)