#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int array[] = {3, 4, 6, 7, 1};
    int targetSum = 7;

    int length = sizeof(array) / sizeof(array[0]);

    int count = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if ((array[i] + array[j] == targetSum))
            {
                count++;
            }
        }
    }

    cout << "The output of target sum is: " << count;

    return 0;
}