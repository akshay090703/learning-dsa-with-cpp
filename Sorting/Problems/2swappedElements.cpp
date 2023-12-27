#include <iostream>
#include <vector>
using namespace std;

void twoSwappedElements(vector<int> &v)
{
    int n = v.size();
    int firstWrongOrderIdx = -1, secondWrongOrderIdx = -1;

    if (n <= 1)
        return;

    for (int i = 1; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            if (firstWrongOrderIdx == -1)
            {
                firstWrongOrderIdx = i - 1;
                secondWrongOrderIdx = i;
            }
            else
            {
                secondWrongOrderIdx = i;
            }
        }
    }

    if (firstWrongOrderIdx != -1 && secondWrongOrderIdx != -1)
        swap(v[firstWrongOrderIdx], v[secondWrongOrderIdx]);
}

int main()
{
    vector<int> v = {10, 5, 6, 7, 8, 9, 3};

    twoSwappedElements(v);
    cout << "The sorted array is: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n)
// Space COmplexity -> O(1)