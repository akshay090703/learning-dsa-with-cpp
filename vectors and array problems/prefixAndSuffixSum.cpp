#include <iostream>
using namespace std;

bool isPrefixSuffixSumEqual(int array[], int n)
{
    int prefixSum = 0, suffixSum = 0;
    int left_pointer = 0, right_pointer = n - 1;
    while (left_pointer <= right_pointer)
    {
        prefixSum += array[left_pointer++];
        suffixSum += array[right_pointer--];

        if (prefixSum == suffixSum && left_pointer != right_pointer)
        {
            return true;
        }
    }

    return false;
}

// ALternate method
// if the prefix and suffix sum is equal then the total sum will always
// be even.
int sumOfArr(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}
bool alternateMethod(int array[], int n)
{
    int sum = sumOfArr(array, n);
    if (sum % 2 == 0)
    {
        sum /= 2;
        int flagSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum == flagSum)
                return true;
            flagSum += array[i];
        }
    }
    return false;
}

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // string message = isPrefixSuffixSumEqual(array, n) ? "CAN" : "CANNOT";
    string message = alternateMethod(array, n) ? "CAN" : "CANNOT";

    cout << "The array " << message
         << " be divided into two subarrays with equal sum.";

    return 0;
}