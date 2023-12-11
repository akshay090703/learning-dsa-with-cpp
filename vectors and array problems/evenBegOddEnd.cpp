#include <iostream>
#include <vector>
using namespace std;

// Using Two Pointers

void sortingByParity(vector<int> &v)
{
    int left_pointer = 0, right_pointer = v.size() - 1;
    int temp;

    while (left_pointer < right_pointer)
    {
        if (v[left_pointer] % 2 == 1 && v[right_pointer] % 2 == 0)
        {
            swap(v[left_pointer], v[right_pointer]);

            left_pointer++;
            right_pointer--;
        }

        if (v[left_pointer] % 2 != 1)
        {
            left_pointer++;
        }

        if (v[right_pointer] % 2 != 0)
        {
            right_pointer--;
        }
    }
}

int main()
{
    cout << "Enter the length of needed array: ";
    int n;
    cin >> n;

    vector<int> v;

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    sortingByParity(v);

    // Printing the output
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}