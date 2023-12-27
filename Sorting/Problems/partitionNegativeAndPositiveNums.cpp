#include <iostream>
#include <vector>
using namespace std;

void partitionNegativeAndPositiveNums(vector<int> &v)
{
    int n = v.size();
    int partition = 0;

    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (v[j] < partition)
            swap(v[++i], v[j]);
    }
}

int main()
{
    vector<int> v = {19, -20, 7, -4, -13, 11, -5, 3};

    partitionNegativeAndPositiveNums(v);
    cout << "Sorted Array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n)
// Space Complexity -> O(1)