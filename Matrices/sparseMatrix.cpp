#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class SparseMatrix
{
private:
    int n;
    int m;
    int num;
    Element *el;

public:
    SparseMatrix(int n, int m, int num)
    {
        this->n = n;
        this->m = m;
        this->num = num;
        el = new Element[this->num];
    }
    ~SparseMatrix()
    {
        delete[] el;
    }

    // operator overloading
    // we are making it a friend function so that they can access all the members
    friend istream &operator>>(istream &is, SparseMatrix &s);
    friend ostream &operator<<(ostream &os, SparseMatrix &s);
    SparseMatrix operator+(SparseMatrix &s);
};

istream &operator>>(istream &is, SparseMatrix &s)
{
    cout << "Enter non-zero elements: \n";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.el[i].i >> s.el[i].j >> s.el[i].x;
    }
    return is;
};

ostream &operator<<(ostream &os, SparseMatrix &s)
{
    int k = 0;
    for (int i = 0; i < s.n; i++)
    {
        for (int j = 0; j < s.m; j++)
        {
            if (k < s.num && s.el[k].i == i && s.el[k].j == j)
                cout << s.el[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return os;
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s)
{
    int i, j, k;
    if (n != s.n && m != s.m)
    {
        cout << "Matrices have different dimensions. Addition not possible." << endl;
        return SparseMatrix(0, 0, 0);
    }

    SparseMatrix *sum = new SparseMatrix(n, m, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (el[i].i < s.el[j].i)
            sum->el[k++] = el[i++];
        else if (el[i].i > s.el[j].i)
            sum->el[k++] = s.el[j++];
        else
        {
            if (el[i].j < s.el[j].j)
                sum->el[k++] = el[i++];
            else if (el[i].j > s.el[j].j)
                sum->el[k++] = s.el[j++];
            else
            {
                sum->el[k] = el[i];
                sum->el[k++].x = el[i++].x + s.el[j++].x;
            }
        }
    }

    // for remaining elements
    for (; i < num; i++)
    {
        sum->el[k++] = el[i];
    }
    for (; j < s.num; j++)
    {
        sum->el[k++] = s.el[j];
        sum->num = k;
    }

    return *sum;
};

int main()
{
    SparseMatrix s1(5, 5, 5);
    SparseMatrix s2(5, 5, 5);
    cin >> s1;
    cin >> s2;

    SparseMatrix sum = s1 + s2;

    cout << "First Matrix: " << endl
         << s1;
    cout << "Second Matrix: " << endl
         << s2;
    cout << "Sum Matrix: " << endl
         << sum;

    system("pause");
    return 0;
}
