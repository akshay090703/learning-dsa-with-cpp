#include <iostream>
using namespace std;

class LowerTriangularMatrix
{
private:
    int n;
    int *A;

public:
    LowerTriangularMatrix()
    {
        n = 2;
        A = new int[(2 * (2 + 1)) / 2];
    }

    LowerTriangularMatrix(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];
    }

    ~LowerTriangularMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() { return n; };
};

void LowerTriangularMatrix::Set(int i, int j, int x)
{
    if (i >= j)
        A[((i * (i - 1)) / 2) + (j - 1)] = x;
}

int LowerTriangularMatrix::Get(int i, int j)
{
    if (i >= j)
        return A[(i * (i - 1) / 2) + (j - 1)];
    return 0;
}

void LowerTriangularMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[(i * (i - 1) / 2) + (j - 1)] << " ";
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

    LowerTriangularMatrix lowerTri(d);

    int x;
    cout << "Enter all the elements: ";
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            lowerTri.Set(i, j, x);
        }
    }

    lowerTri.Display();

    system("pause");
    return 0;
}
