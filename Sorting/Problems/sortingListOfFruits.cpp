#include <iostream>
#include <vector>
using namespace std;

// strcmp function is used to compare two char arrays lexicographically

void selectionSort(vector<string> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_fruit = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[min_fruit] > v[j])
                min_fruit = j;
        }

        if (min_fruit != i)
            swap(v[min_fruit], v[i]);
    }
}

int main()
{
    vector<string> fruits = {"papaya", "lime", "watermelon", "apple", "mango", "orange", "kiwi"};

    selectionSort(fruits);
    cout << "The sorted fruits are: ";
    for (int i = 0; i < fruits.size(); i++)
    {
        if (i == 0)
            cout << "[";
        cout << fruits[i];
        if (i != fruits.size() - 1)
            cout << ", ";
        if (i == fruits.size() - 1)
            cout << "]";
    }
    cout << endl;

    system("pause");
    return 0;
}

// Time Complexity -> O(n^2) both in best and worst cases
// Space Complexity -> O(1)