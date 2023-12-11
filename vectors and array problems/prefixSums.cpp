#include <iostream>
#include <vector>
using namespace std;

void prefixSum(vector<int> &v)
{
    int n = v.size();
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += v[i];
        v[i] = currentSum;
    }
}

// Alternative approach
void runningSum(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        v[i] += v[i - 1];
    }
}

int main()
{
    cout << "Enter length of the v: ";
    int n;
    cin >> n;

    vector<int> v(n);
    cout << "Enter numbers: \n";
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    // prefixSum(v);
    runningSum(v);

    // Displaying output
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}