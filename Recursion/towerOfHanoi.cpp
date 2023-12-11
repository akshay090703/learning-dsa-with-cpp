#include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if (n == 0)
        return;

    TOH(n - 1, A, C, B);
    cout << "Move disk 1 from source " << A << " to destination " << C << endl;
    TOH(n - 1, B, A, C);

    return;
};

int main()
{
    cout << "Give the number of disks: ";
    int disks;
    cin >> disks;

    cout << "The steps for Tower Of Hanoi problem of " << disks << " disks are: " << endl;
    TOH(disks, 1, 2, 3);

    return 0;
}