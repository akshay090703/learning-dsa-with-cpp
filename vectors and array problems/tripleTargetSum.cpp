#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int array[] = {3, 1, 2, 4, 0, 6};
    int targetSum = 6;

    int length = sizeof(array) / sizeof(array[0]);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (array[i] <= targetSum)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (array[i] + array[j] <= targetSum)
                {
                    for (int k = j + 1; k < length; k++)
                    {
                        if (array[i] + array[j] + array[k] == targetSum)
                        {
                            count++;
                            cout << array[i] << " " << array[j] << " " << array[k] << endl;
                        }
                        continue;
                    }
                }
                continue;
            }
        }
        continue;
    }

    cout << "The number of triplets for target sum: " << count;

    return 0;
}