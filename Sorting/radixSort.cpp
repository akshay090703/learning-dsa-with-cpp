#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &v, int digit, int n);

void radixSort(vector<int> &v)
{
    int n = v.size();

    int max_number = v[0];
    for (auto i : v)
    {
        if (max_number < i)
            max_number = i;
    }

    for (int digit = 1; max_number / digit > 0; digit *= 10)
    {
        countSort(v, digit, n);
    }
}

void countSort(vector<int> &v, int digit, int n)
{
    // finding max digit
    int max_digit = (v[0] / digit) % 10;
    for (int i = 0; i < n; i++)
    {
        if (max_digit < (v[i] / digit) % 10)
        {
            max_digit = (v[i] / digit) % 10;
        }
    }

    // frequency array
    vector<int> cumulativeFreqArr(max_digit + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cumulativeFreqArr[(v[i] / digit) % 10]++;
    }

    // cumulative frequency array
    for (int i = 1; i <= max_digit; i++)
    {
        cumulativeFreqArr[i] += cumulativeFreqArr[i - 1];
    }

    // making an answer array
    vector<int> resultArr(n);
    for (int i = n - 1; i >= 0; i--)
    {
        resultArr[--cumulativeFreqArr[(v[i] / digit) % 10]] = v[i];
    }

    // copying elements to main array
    for (int i = 0; i < n; i++)
    {
        v[i] = resultArr[i];
    }
}

int main()
{
    vector<int> v = {170, 45, 75, 90, 802, 2};

    radixSort(v);
    cout << "Sorted Array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

// d is the number of digits in the max element of the array
// Time Complexity -> O(d * (n+max)) ~ O(d*n)
// Space Complexity -> O(n + max) [same as count sort] ~ O(n)