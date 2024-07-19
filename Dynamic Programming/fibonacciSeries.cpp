// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// using recursion
// int fibo(int n) {
//     if(n == 0 or n == 1) return n;

//     return fibo(n - 1) + fibo(n - 2);
// }

// using memoization
// Time Complexity-> O(n)
// Space Complexity -> O(N) + O(N)
// int fibo(int n, vector<int> &dp) {
//     if(n == 0 or n == 1) {
//         dp[n] = n;
//         return dp[n];
//     }

//     if(dp[n] != -1) {
//         return dp[n];
//     }

//     dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
//     return dp[n];
// }

// Using Tabulation
// Time Complexity -> O(n)
// Space Complexity -> O(n)
// int fibo(int n, vector<int> &dp) {
//     for(int i = 2; i<=n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// Using Space Optimization
// Time Complexity -> O(n)
// Space Complexity -> O(1)
int fibo(int n)
{
    int prevPrev = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int next = prev + prevPrev;

        prevPrev = prev;
        prev = next;
    }

    return prev;
}

int main()
{
    vector<int> dp(5 + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    // cout << fibo(5, dp);

    cout << fibo(5);

    return 0;
}