#include <iostream>
using namespace std;

bool palindromeOrNot(int n, int *temp)
{
    if (n == 0)
        return true;

    bool result = palindromeOrNot(n / 10, temp) && n % 10 == *temp % 10;
    *temp /= 10;
    return result;
};

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int num2 = num;
    int *temp = &num2;

    cout << "The given number is palindrome: " << palindromeOrNot(num, temp) << endl;

    return 0;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)
// Where n is the number of digits in the number