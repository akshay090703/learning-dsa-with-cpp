#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &num)
{
    vector<int> res;
    vector<int> frequencyArr(num.size(), 0);

    for (auto i : num)
    {
        frequencyArr[i]++;
    }

    for (int i = 0; i < frequencyArr.size(); i++)
    {
        if (frequencyArr[i] == 2)
            res.push_back(i);
    }

    return res;
};

vector<int> optimisedApproach(vector<int> &nums)
{
    vector<int> res;

    for (size_t i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]) - 1;

        nums[index] *= -1;

        if (nums[index] > 0)
            res.push_back(index + 1);
    }

    return res;
};

int main()
{
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    cout << "Enter elements of the array: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };

    cout << "Elements that are duplicates are: ";
    // for (auto i : findDuplicates(arr))
    // {
    //     cout << i << " ";
    // }

    for (auto i : optimisedApproach(arr))
    {
        cout << i << " ";
    }

    return 0;
}