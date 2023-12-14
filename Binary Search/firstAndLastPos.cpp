#include <iostream>
#include <vector>
using namespace std;

vector<int> firstAndLastPos(vector<int> &v, int &target)
{
    int start = 0, end = v.size() - 1;
    vector<int> res;
    int first_pos = -1, last_pos = -1;

    while (start <= end)
    {
        int mid = start + ((end - start) / 2);

        if (v[mid] == target)
        {
            while (v[--mid] == target)
            {
                first_pos = mid;
            };
            while (v[++mid] == target)
            {
                last_pos = mid;
            };
            break;
        }
        else if (v[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    if (first_pos == -1 && last_pos > -1)
        first_pos = last_pos;

    res.push_back(first_pos);
    res.push_back(last_pos);

    return res;
};

int main()
{
    cout << "Enter the size of vector: ";
    int n;
    cin >> n;

    vector<int> input(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    };

    cout << "Element to be searched: ";
    int target;
    cin >> target;

    cout << "The first and last position of the target: ";
    vector<int> res = firstAndLastPos(input, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}

// n => length of array
// time complexity -> O(logn)
// space complexity -> O(1)
// The O(log n) time complexity suggests that the algorithm can handle large datasets effectively.
// However, the O(1) space complexity does mean that the algorithm has limited ability to scale up the number of queries it can handle.