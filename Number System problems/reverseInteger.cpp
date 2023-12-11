#include <iostream>
using namespace std;

int reverseNum(int n)
{
    int ans = 0;

    while (n > 0)
    {
        int lastDig = n % 10;
        n /= 10;
        ans = (ans * 10) + lastDig;
    };

    return ans;
};

int main()
{
    cout << "Give your number: ";
    int n;
    cin >> n;

    cout << "Reversed number: " << reverseNum(n) << endl;

    return 0;
}