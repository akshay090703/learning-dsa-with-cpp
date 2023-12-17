#include <iostream>
#include <vector>
using namespace std;

int oneOfThePeaks(vector<int> &input)
{
    int size = input.size() - 1;
    int low = 0, high = size;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid == 0)
        {
            if (input[mid] > input[mid + 1])
                return 0;
            else
                return 1;
        }
        else if (mid == size)
        {
            if (input[mid] > input[mid - 1])
                return size;
            else
                return size - 1;
        }
        else if (input[mid - 1] < input[mid] && input[mid] > input[mid + 1])
            return mid;
        else if (input[mid - 1] < input[mid])
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
};

int main()
{
    cout << "Enter the size of the vector: ";
    int size;
    cin >> size;

    vector<int> v(size);
    cout << "Enter the elements for the vectors: ";
    for (int i = 0; i < size; i++)
    {
        cin >> v[i];
    }

    int ans = oneOfThePeaks(v);

    cout << "One of the peak's index in the array: " << ans << "(value: " << v[ans] << ")" << endl;

    system("pause");
    return 0;
}
