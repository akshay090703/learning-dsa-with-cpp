#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurances(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0 || n == 1)
        return true;

    const int maxEl = *max_element(arr.begin(), arr.end());
    const int minEl = *min_element(arr.begin(), arr.end());

    const int range = maxEl - minEl + 1;

    vector<int> frequencyArr(range, 0);
    vector<bool> occuranceArr(n, false);

    for (int num : arr)
    {
        frequencyArr[num - minEl]++;
    }

    for (auto count : frequencyArr)
    {
        if (count > 0)
        {
            if (occuranceArr[count])
                return false;

            occuranceArr[count] = true;
        }
    }

    return true;
};

int main()
{
    cout << "Enter size of vector: ";
    int n;
    cin >> n;

    cout << "Enter elements of the vector: ";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int element;
        std::cin >> element;
        arr.push_back(element);
    }

    if (uniqueOccurances(arr))
    {
        std::cout << "Occurrences are unique." << std::endl;
    }
    else
    {
        std::cout << "Occurrences are not unique." << std::endl;
    }

    return 0;
}