#include <iostream>
using namespace std;

int bitwiseComplement(int num)
{
    if (num == 0)
        return 1;

    int res = num;
    int mask = 0;

    while (res != 0)
    {
        mask = (mask << 1) | 1;
        res = res >> 1;
    }

    int ans = (~num) & mask; // as numbers are represented as 32 bits in memory

    return ans;
};

int main()
{
    cout << "Give a number: ";
    int n;
    cin >> n;

    cout << "The bitwise complement of your number is: " << bitwiseComplement(n) << endl;

    return 0;
}