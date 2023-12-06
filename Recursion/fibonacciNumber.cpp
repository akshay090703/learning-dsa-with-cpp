#include <iostream>
using namespace std;

// Recursive function
// Fibonacci series: nth term will be equal to sum of (n-1)th and (n-2)th term
int fibonacciNum(int n)
{
    // Base Cases
    if (n == 0 || n == 1)
        return n;

    // Assumption in Selfwork
    return fibonacciNum(n - 1) + fibonacciNum(n - 2);
};

int main()
{
    int num;
    cout << "Enter the term you want: ";
    cin >> num;

    cout << "The " << num << "th term of the fibonacci series is: " << fibonacciNum(num) << "." << endl;

    return 0;
}

// Time Complexity -> O(2^n)
// Space Complexity -> O(n)