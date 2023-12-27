#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag Problem
void sorting012s(vector<int> &v)
{
    int n = v.size();
    int left = 0, mid = 0, right = n - 1;

    while (mid <= right)
    {
        if (v[mid] == 0)
        {
            swap(v[mid], v[left]);
            left++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else if (v[mid] == 2)
        {
            swap(v[mid], v[right]);
            right--;
        }
    }
}

int main()
{
    vector<int> v = {2, 1, 1, 2, 2, 0, 0, 1, 1, 2, 2, 0, 1};

    sorting012s(v);
    cout << "Sorted array: ";
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