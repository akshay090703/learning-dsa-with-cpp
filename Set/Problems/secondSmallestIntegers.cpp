#include <set>
#include <vector>
#include <iostream>
using namespace std;

int secondSmallestInteger(vector<int> &v)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    auto secondLargestEl = s.begin();
    secondLargestEl++; // points to second smallest num now

    return *secondLargestEl;
}

int main()
{
    // vector<int> input = {1, 2, 2 - 4};
    vector<int> input = {1, 2, 3, 1, 1};

    cout << "Second smallest number is: " << secondSmallestInteger(input) << endl;

    return 0;
}