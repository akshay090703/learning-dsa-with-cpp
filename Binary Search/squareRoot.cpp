#include <iostream>
using namespace std;

int squareRoot(int n)
{
    int start = 1, end = n;
    int ans;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (mid * mid == n)
        {
            ans = mid;
            return ans;
        }
        else if (mid * mid < n)
        {
            start = mid + 1;
            ans = mid; // will return floor value for non perfect squares
        }
        else
        {
            end = mid - 1;
        }
    };
    return ans;
};

int main()
{
    cout << "Enter the number: ";
    int num;
    cin >> num;

    cout << "Square root of given number is: " << squareRoot(num) << endl;

    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)