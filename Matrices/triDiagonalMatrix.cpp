#include <iostream>
using namespace std;

class TriDiagonalMatrix
{
private:
    int n;
    int *A;

public:
    TriDiagonalMatrix()
    {
        n = 2;
        A = new int[(3 * 2) - 2];
    }

    TriDiagonalMatrix(int n)
    {
        this->n = n;
        A = new int[(3 * n) - 2];
    }

    ~TriDiagonalMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimensions() { return n; };
};

void TriDiagonalMatrix::Set(int i, int j, int x)
{
    // first lower diagonal, then main diagonal and then upper diagonal
    if (i - j == 1)
        A[i - 1] = x;
    else if (i - j == 0)
        A[(n - 1) + (i - 1)] = x;
    else if (i - j == -1)
        A[((2 * n) - 1) + (i - 1)] = x;
};

int TriDiagonalMatrix::Get(int i, int j)
{
    if (i - j == 1)
        return A[i - j];
    else if (i - j == 0)
        return A[(n - 1) + (i - 1)];
    else if (i - j == -1)
        return A[((2 * n) - 1) + (i - 1)];
    else
        return 0;
};

void TriDiagonalMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1)
                cout << A[i - j] << " ";
            else if (i - j == 0)
                cout << A[(n - 1) + (i - 1)] << " ";
            else if (i - j == -1)
                cout << A[((2 * n) - 1) + (i - 1)] << " ";
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

    TriDiagonalMatrix triDiagonal(d);

    int x;
    cout << "Enter all the elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            triDiagonal.Set(i, j, x);
        }
    }

    triDiagonal.Display();
    cout << "Element at (2,3): " << triDiagonal.Get(2, 3) << endl;

    system("pause");
    return 0;
}
