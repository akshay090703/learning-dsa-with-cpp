#include <set>
#include <vector>
#include <iostream>
using namespace std;

// n is the size of vector 1 and m of vector 2
// t is the unique elements in vector
// Time Complexity -> (n+m)*log(t)
int sumOfCommonElements(vector<int> &v1, vector<int> &v2)
{
    set<int> s1;

    // Time Complexity -> n*log(t)
    for (auto i : v1)
    {
        s1.insert(i);
    }

    int sum = 0;
    // Time Complexity -> m*log(t)
    for (auto i : v2)
    {
        if (s1.find(i) != s1.end())
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 3, 3};
    vector<int> v2 = {5, 6, 7, 5, 2, 3, 6};
    cout << "Sum of common elements: " << sumOfCommonElements(v1, v2) << endl;

    return 0;
}