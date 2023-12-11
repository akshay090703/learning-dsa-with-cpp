#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// there is also an absolute inbuilt function
// called abs().
int modulusFn(int n)
{
    if (n < 0)
    {
        return n * (-1);
    }
    else
    {
        return n;
    }
}

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    vector<int> v;
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    vector<int> ansV; // initializing with n will give n 0 elements by default

    int left_pointer = 0, right_pointer = n - 1;
    while (left_pointer <= right_pointer)
    {
        if (modulusFn(v[left_pointer]) > modulusFn(v[right_pointer]))
        {
            ansV.push_back(v[left_pointer] * v[left_pointer]);
            left_pointer++;
        }
        else
        {
            ansV.push_back(v[right_pointer] * v[right_pointer]);
            right_pointer--;
        }
    }

    reverse(ansV.begin(), ansV.end());

    // displaying output
    cout << "The answer array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << ansV[i] << " ";
    }

    return 0;
}