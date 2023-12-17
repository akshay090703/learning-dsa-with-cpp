#include <iostream>
#include <vector>
using namespace std;

int sumOfElInArray(vector<int> &arr, int start, int end)
{
    if (start > end)
        return 0;
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool canDistributeChoco(vector<int> &arr, int &mid, int &students)
{
    int n = arr.size();
    int studentsReqd = 1;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (currSum + arr[i] > mid)
        {
            studentsReqd++;
            currSum = arr[i];
            if (studentsReqd > students)
                return false;
        }
        else
        {
            currSum += arr[i];
        }
    }
    return true;
}

int chocolateDistribution(vector<int> &boxes, int &students)
{
    int n = boxes.size();

    int low = boxes[0], high = sumOfElInArray(boxes, 0, n - 1);

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canDistributeChoco(boxes, mid, students))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cout << "Enter the number of chocolate boxes: ";
    int n;
    cin >> n;

    vector<int> boxes(n);
    cout << "Enter the number of chocolates in each box: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> boxes[i];
    }

    cout << "Enter the number of students: ";
    int students;
    cin >> students;

    cout << "The minimum possible number of chocolates to student with the maximum chocolates is: " << chocolateDistribution(boxes, students) << endl;

    system("pause");
    return 0;
}
