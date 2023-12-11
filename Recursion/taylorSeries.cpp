#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num == 0)
        return 1;

    return num * factorial(num - 1);
};

int powerOfNum(int n, int i)
{
    if (i == 0)
        return 1;

    return n * powerOfNum(n, i - 1);
};

int taylorSeries(double x, double i)
{
    if (i == 0)
        return 1;

    return (powerOfNum(x, i) / factorial(i)) + taylorSeries(x, i - 1);
};

int alternativeApproach(double x, int n)
{
    static double s = 1;

    if (n == 0)
        return s;

    s = (1 + (x / n)) * s;

    return alternativeApproach(x, n - 1);
};

int main()
{
    cout << "Give the number of term you want: ";
    int n;
    cin >> n;

    cout << "e^" << n << ": " << taylorSeries(n, n);
    // cout << "e^" << n << ": " << alternativeApproach(n, n);

    return 0;
}