#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    vector<int> v(n + 1, 0);

    cout << "Enter the elements for the array: \n";
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    // calculating prefix sum array
    for (int i = 2; i <= n; i++)
    {
        v[i] += v[i - 1];
    }

    cout << "No. of queries user wants: ";
    int q;
    cin >> q;

    while (q--)
    {
        cout << "Enter the values of l and r: \n";
        int l, r;
        cin >> l >> r;

        int ans = 0;
        // ans = prefixsum[r] - prefixsum[l-1]
        ans = v[r] - v[l - 1];
        cout << "The sum for this query will be: " << ans << endl;
    }

    return 0;
}