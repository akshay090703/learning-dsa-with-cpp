#include <iostream>
using namespace std;

class SymmetricMatrix
{
private:
    int n;
    int *A;

public:
    SymmetricMatrix()
    {
        n = 2;
        A = new int[(2 * (2 + 1)) / 2];
    }

    SymmetricMatrix(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];
    }

    ~SymmetricMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimensions() { return n; };
};

void SymmetricMatrix::Set(int i, int j, int x)
{
    if (i >= j)
        A[((n * (n - 1)) / 2) + (j - 1)] = x;
};

int SymmetricMatrix::Get(int i, int j)
{
    if (i >= j)
        return A[((n * (n - 1)) / 2) + (j - 1)];
    else
        return A[((n * (n - 1)) / 2) + (i - 1)];
};

void SymmetricMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[((n * (n - 1)) / 2) + (j - 1)] << " ";
            else
                cout << A[((n * (n - 1)) / 2) + (i - 1)] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    SymmetricMatrix symmetricTri(d);

    int x;
    cout << "Enter all the elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            symmetricTri.Set(i, j, x);
        }
    }

    symmetricTri.Display();
    cout << "Element at (2,3): " << symmetricTri.Get(2, 3) << endl;

    system("pause");
    return 0;
}
