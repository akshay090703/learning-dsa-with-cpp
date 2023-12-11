#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter the elements of the array in increasing order: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Give the element to search for: ";
    int x;
    cin >> x;

    int count = 0;
    int i = 0, j = n - 1;

    while (i < j)
    {
        int currentSum = v[i] + v[j];
        if (currentSum == x)
        {
            count++;
            i++;
            j--;
        }
        else if (currentSum > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout << "The number of unique pairs: " << count;

    return 0;
}