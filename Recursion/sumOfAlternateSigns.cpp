#include <iostream>
using namespace std;

int alternateSignsSum(int n)
{
    if (n < 1)
        return 0;

    if (n % 2 == 0)
        return (-1) + alternateSignsSum(n - 2);
    else
        return (1) + alternateSignsSum(n - 2);
};

int main()
{
    cout << "Enter a number: ";
    int num;
    cin >> num;

    cout << "The sum of the numbers from 1 to " << num << " with alternating signs is: " << alternateSignsSum(num);

    return 0;
}
// n = num
// Time Complexity: O(n)
// Space Complexity: O(n)