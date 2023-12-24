#include <iostream>
#include <vector>
using namespace std;

void movingAllNonZeros(vector<int> &v)
{
    int n = v.size();
    int numOf0s = 0;

    // using bubble sort technique
    for (int i = 0; i < n - numOf0s; i++)
    {

        if (v[i] == 0)
        {
            for (int j = i; j + 1 < n; j++)
                swap(v[j], v[j + 1]);

            numOf0s++;
        }
    }
}

void optimizedApproach(vector<int> &v)
{
    int n = v.size();
    int non_zero = 0, zero = 0;

    while (non_zero < n && zero < n)
    {
        if (v[non_zero] != 0)
        {
            swap(v[non_zero], v[zero]);
            zero++;
        }
        non_zero++;
    }
}

int main()
{
    vector<int> v = {3, 0, 2, 0, 1, 5};

    // movingAllNonZeros(v);
    optimizedApproach(v);
    cout << "Modified Array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)