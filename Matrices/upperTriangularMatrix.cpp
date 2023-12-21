#include <iostream>
using namespace std;

class UpperTriMatrix
{
private:
    int n;
    int *A;

public:
    UpperTriMatrix()
    {
        n = 2;
        A = new int[(2 * (2 + 1)) / 2];
    }

    UpperTriMatrix(int n)
    {
        this->n = n;
        this->A = new int[((1 + 2 * n) * n) / 2];
    };

    ~UpperTriMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getDimensions() { return n; };
};

void UpperTriMatrix::Set(int i, int j, int x)
{
    if (i <= j)
        A[((i - 1) * n) - (((i - 2) * (i - 1)) / 2) + (j - i + 1)] = x;
};

int UpperTriMatrix::Get(int i, int j)
{
    if (i <= j)
        return A[((i - 1) * n) - (((i - 2) * (i - 1)) / 2) + (j - i + 1)];

    return 0;
};

void UpperTriMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << A[((i - 1) * n) - (((i - 2) * (i - 1)) / 2) + (j - i + 1)] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    UpperTriMatrix upperTri(d);

    int x;
    cout << "Enter all the elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            upperTri.Set(i, j, x);
        }
    }

    upperTri.Display();
    cout << "Element at (2,3): " << upperTri.Get(2, 3) << endl;

    system("pause");
    return 0;
}
