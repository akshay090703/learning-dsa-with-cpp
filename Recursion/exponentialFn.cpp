#include <iostream>
using namespace std;

// Recursive Function
int exponentialFn(int p, int q)
{
    // Base condition
    if (q == 0)
        return 1;

    // Assumption that the q-1 condition is right in the selfwork
    return p * exponentialFn(p, q - 1);
};

// Alternative Resursive Function
int alternativeExponentialFn(int p, int q)
{
    // Base condition
    if (q == 0)
        return 1;

    // Assumption with selfwork
    int ans = alternativeExponentialFn(p, q / 2);
    if (q % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return p * ans * ans;
    }
};

int main()
{
    int n, m;
    cout << "Enter the value of n and m: ";
    cin >> n >> m;

    // cout << "The answer of n^m is: " << exponentialFn(n, m) << endl;
    cout << "The answer of n^m is: " << alternativeExponentialFn(n, m) << endl;

    return 0;
}

// First approach
// Time complexity: O(q)
// Space complexity: O(q)
// where q is the exponential value

// Alternative approach (extremely optimized)
// Time complexity: O(log q)
// Space complexity: O(log q)
// where q is the exponential value