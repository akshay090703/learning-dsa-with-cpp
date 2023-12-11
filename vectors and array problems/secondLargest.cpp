#include <iostream>
#include <vector>
using namespace std;

int largestElIdx(vector<int> v)
{
    int largest = INT16_MIN, index = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
            index = i;
        }
    }
    return index;
}

// Alternate and better way
int secondLargestEl(vector<int> v)
{
    int maxEl = INT16_MIN, secondMax = INT16_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > maxEl)
        {
            maxEl = v[i];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > secondMax && secondMax != maxEl)
        {
            secondMax = v[i];
        }
    }
    return secondMax;
}

int main()
{
    vector<int> v = {2, 3, 5, 7, 4, 6, 1, 7};

    int largestidx = largestElIdx(v);
    int largestEl = v[largestidx];

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == largestEl)
        {
            v.erase(v.begin() + i);
        }
    }

    // cout << "The second largest number is: " << v[largestElIdx(v)];
    cout << "The second largest number is: " << secondLargestEl(v);

    return 0;
}