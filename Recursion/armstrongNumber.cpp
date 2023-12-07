#include <iostream>
using namespace std;

int powFn(int n, int i)
{
    if (i == 0)
        return 1;

    int result = powFn(n, i / 2);
    return i % 2 == 0 ? result * result : n * result * result;

    // return n * powFn(n, i - 1); // more time complexity
};

int digitsInANum(int n)
{
    if (n < 10)
        return 1;
    return 1 + digitsInANum(n / 10);
};

int armstrongNum(int n, int i)
{
    if (n == 0)
        return 0;

    return powFn(n % 10, i) + armstrongNum(n / 10, i);
};

int main()
{
    cout << "Give a number: ";
    int num;
    cin >> num;

    string message = armstrongNum(num, digitsInANum(num)) == num ? "This is a Armstrong Number." : "This is not a Armstrong Number.";

    cout << message;

    return 0;
}

// Time complexity -> O(d^2)
// Space complexity -> O(d^2)
// d -> number of digits in the number