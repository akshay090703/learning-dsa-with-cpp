#include <iostream>
using namespace std;

void kMultiplesOfNum(int n, int k)
{
    if (k < 1)
        return;

    kMultiplesOfNum(n, k - 1);
    cout << n * k << " ";
};

int main()
{
    int num, k;
    cout << "Give the values of number and k: ";
    cin >> num >> k;

    cout << "The k multiples of number are: " << endl;
    kMultiplesOfNum(num, k);

    return 0;
}

// Time Complexity: O(k)
// Space Complexity: O(k)