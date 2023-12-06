#include <iostream>
using namespace std;

// Using Euclid's Algorithm
int gcd(int x, int y)
{
    // Both approaches work here, '%' and '-' too

    // Approach 1: '-'
    // if (x == y)
    //     return x;

    // return x > y ? gcd(x - y, y) : gcd(x, y - x);

    // Approach 2: '%'
    if (x == 0)
        return y;
    else if (y == 0)
        return x;

    return x > y ? gcd(x % y, y) : gcd(x, y % x);
};

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "gcd: " << gcd(num1, num2) << endl;

    return 0;
}