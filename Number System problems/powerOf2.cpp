#include <iostream>
using namespace std;

bool isPowerOf2(int num)
{
    if (num == 1)
        return true;

    else if (num == 0)
        return false;

    while (num > 1)
    {
        if (num % 2 != 0)
            return false;
        num /= 2;
    }
    return true;
};

int main()
{
    cout << "Give your number: ";
    int n;
    cin >> n;

    string answer = isPowerOf2(n) ? "Yes" : "No";

    cout << "Is the given number a power of 2? " << answer << endl;

    return 0;
}