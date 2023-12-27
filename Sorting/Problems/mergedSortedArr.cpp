#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int> &num1, vector<int> &num2)
{
    int n = num1.size(), m = num2.size();
    int i = 0, j = 0;
    vector<int> v;

    while (i < n && j < m)
    {
        if (num1[i] <= num2[j])
        {
            v.push_back(num1[i]);
            i++;
        }
        else
        {
            v.push_back(num2[j]);
            j++;
        }
    }

    while (i < n)
    {
        v.push_back(num1[i]);
        i++;
    }

    while (j < m)
    {
        v.push_back(num2[j]);
        j++;
    }

    return v;
}

int main()
{
    vector<int> num1 = {5, 8, 10, 11, 15};
    vector<int> num2 = {2, 7, 8};

    vector<int> ans = mergeSortedArrays(num1, num2);
    cout << "Sorted merged array: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// n1 -> size of 1st array and n2 -> size of 2nd array
// Time Complexity -> O(n1 + n2)
// Space Complexity -> O(n1 + n2)