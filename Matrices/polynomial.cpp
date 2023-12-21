#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int n;
    class Term *terms;

public:
    ~Polynomial()
    {
        delete[] terms;
    }

    friend void create(Polynomial *p);
    friend void display(Polynomial p);
    friend Polynomial add(Polynomial *p1, Polynomial *p2);
};

void create(Polynomial *p)
{
    cout << "Enter number of terms: ";
    cin >> p->n;
    p->terms = new class Term[p->n];

    cout << "Enter your terms: \n";
    for (int i = 0; i < p->n; i++)
    {
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
};

void display(Polynomial p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i < p.n - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

Polynomial add(Polynomial *p1, Polynomial *p2)
{
    Polynomial sum;
    sum.n = p1->n + p2->n;
    sum.terms = new Term[sum.n];

    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum.terms[k++] = p1->terms[i++];
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum.terms[k++] = p2->terms[j++];
        else
        {
            sum.terms[k].exp = p1->terms[i].exp;
            sum.terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    // for remaining elements
    for (; i < p1->n; i++)
        sum.terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum.terms[k++] = p2->terms[j];

    sum.n = k;
    return sum;
}

int main()
{
    Polynomial poly1, poly2, poly3;

    create(&poly1);
    create(&poly2);

    display(poly1);
    display(poly2);

    poly3 = add(&poly1, &poly2);
    display(poly3);

    system("pause");
    return 0;
}