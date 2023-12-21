#include <iostream>
using namespace std;

class ToeplitzMatrix
{
private:
    int n;
    int *A;

public:
    ToeplitzMatrix()
    {
        n = 2;
        A = new int[(2 * 2) - 1];
    }

    ToeplitzMatrix(int n)
    {
        this->n = n;
        A = new int[(2 * n) - 1];
    }

    ~ToeplitzMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimensions() { return n; };
};

void ToeplitzMatrix::Set(int i, int j, int x)
{
    if (i <= j)
        A[j - i] = x; // Upper and Main Diagonal
    else
        A[n + (i - j - 1)] = x; // Lower Diagonal
}

int ToeplitzMatrix::Get(int i, int j)
{
    if (i <= j)
        return A[j - i];
    else
        return A[n + (i - j - 1)];
}

void ToeplitzMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << A[j - i] << " ";
            else
                cout << A[n + (i - j - 1)] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    ToeplitzMatrix toeplitzM(d);

    int x;
    cout << "Enter all the elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            toeplitzM.Set(i, j, x);
        }
    }

    toeplitzM.Display();
    cout << "Element at (2,3): " << toeplitzM.Get(2, 3) << endl;

    system("pause");
    return 0;
}
