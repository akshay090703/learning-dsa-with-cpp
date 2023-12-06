#include <iostream>
using namespace std;

// Recursive function
int sumOfDigits(int n)
{
    // Base case
    if (n >= 0 && n <= 9)
        return n;

    // Selfwork with Assumption
    return n % 10 + sumOfDigits(n / 10);
};

int main()
{
    int num;
    cout << "Enter your number: ";
    cin >> num;

    cout << "The sum of the digits: " << sumOfDigits(num) << endl;

    return 0;
}

// Time Complexity -> O(d)
// Space Complexity -> O(d)
// where d is the number of digits in the number