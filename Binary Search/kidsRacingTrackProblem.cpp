#include <iostream>
#include <vector>
using namespace std;

bool largestMinimumDist(vector<int> &v, int &children, int &mid)
{
    int n = v.size();
    int lastChild = v[0];
    int childrenReq = 1;

    for (int i = 1; i < n; i++)
    {
        int dist = v[i] - lastChild;
        if (dist >= mid)
        {
            childrenReq++;
            lastChild = v[i];
            if (childrenReq > children)
                return false;
            else if (childrenReq == children)
                return true;
        }
        // else
        // {
        //     continue;
        // }
    }
    return false;
}

int kidsRacingTrackProblem(vector<int> &v, int &children)
{
    int n = v.size();

    int low = v[0], high = v[n - 1];
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (largestMinimumDist(v, children, mid))
        {
            low = mid + 1;
            result = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    cout << "Enter the number of starting points: ";
    int n;
    cin >> n;

    vector<int> spots(n);
    cout << "Enter the number that denotes location of each spot: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> spots[i];
    }

    cout << "Enter the number of children: ";
    int children;
    cin >> children;

    cout << "The minimum distance between any two of children which is as large as possible: " << kidsRacingTrackProblem(spots, children) << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(nlog(xn-x1))
// Space Complexity -> O(1)