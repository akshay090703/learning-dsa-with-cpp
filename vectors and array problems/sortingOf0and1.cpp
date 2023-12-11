#include <iostream>
#include <vector>
using namespace std;

void sortZeroesAndOnes(vector<int> &v)
{
    int sumOf0s = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            sumOf0s++;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (i < sumOf0s)
        {
            v[i] = 0;
        }
        else
        {
            v[i] = 1;
        }
    }
}

// Alternate Method: Two Pointers
// Uses only one loop
void sort0sAnd1s(vector<int> &v)
{
    int left_pointer = 0;
    int right_pointer = v.size() - 1;
    int temp;

    while (left_pointer < right_pointer)
    {
        if (v[left_pointer] == 1)
        {
            if (v[right_pointer] == 0)
            {
                temp = v[left_pointer];
                v[left_pointer] = v[right_pointer];
                v[right_pointer] = temp;
                left_pointer++;
            }
            else
            {
                right_pointer--;
            }
        }
        else
        {
            left_pointer++;
        }
    }
}

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;

    vector<int> v;

    cout << "Enter the elements for the array: \n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }

    // sortZeroesAndOnes(v);
    sort0sAnd1s(v);

    // Printing the final sorted array
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}