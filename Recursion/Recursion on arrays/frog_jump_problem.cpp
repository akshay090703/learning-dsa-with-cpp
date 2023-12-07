#include <iostream>
using namespace std;

int frog_jump_sol(int *arr, int i, int n)
{
    if (i >= n - 1)
        return 0;

    int next_step{};
    int smallJumpDist = 0;
    int bigJumpDist = 0;

    if (i <= n - 2)
        smallJumpDist = abs(arr[i] - arr[i + 1]);
    if (i <= n - 3)
        bigJumpDist = abs(arr[i] - arr[i + 2]);

    if (smallJumpDist >= bigJumpDist)
    {
        next_step = i + 2;
        return bigJumpDist + frog_jump_sol(arr, next_step, n);
    }
    else
    {
        next_step = i + 1;
        return smallJumpDist + frog_jump_sol(arr, next_step, n);
    };
};

int main()
{
    int n;
    cout << "Give the size of array: ";
    cin >> n;
    int arr[n];

    cout << "Give the elements for the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    };

    cout << "The smallest cost of the frog journey from starting to end is: " << frog_jump_sol(arr, 0, n) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// n -> Number of stones in the array