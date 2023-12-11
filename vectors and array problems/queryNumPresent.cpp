#include <iostream>
#include <vector>
using namespace std;

// First method is by traversing the array
// Here we are going to use the frequency array so that
// we don't have to traverse the array again and again
int main()
{
    int n;
    cout << "Enter length of the array: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> freqVec(10 * 10 * 10 * 10 * 10, 0);

    for (int i = 0; i < v.size(); i++)
    {
        freqVec[v[i]]++;
    }

    // Taking queries from user and showing output
    cout << "Enter number of queries, then enter queries: ";
    int q;
    cin >> q;

    while (q--)
    {
        int queryElement;
        cin >> queryElement;
        cout << freqVec[queryElement] << endl;
    }

    return 0;
}