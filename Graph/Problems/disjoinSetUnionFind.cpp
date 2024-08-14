//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int find(int a[], int x);
void unionSet(int a[], int x, int z);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            string s;
            cin >> s;
            if (s == "UNION")
            {
                int z, x;
                cin >> x >> z;
                unionSet(a, x, z);
            }
            else
            {
                int x;
                cin >> x;
                int parent = find(a, x);
                cout << parent << " ";
            }
        }
        cout << endl;
    }
}
// } Driver Code Ends

/*Complete the functions below*/

// Using Union by Size
int find(int A[], int X)
{
    if (A[X] == X)
        return X;

    // Path Compression
    return A[X] = find(A, A[X]);
}
void unionSet(int A[], int X, int Z)
{
    int ulParentU = find(A, X);
    int ulParentV = find(A, Z);

    if (ulParentU == ulParentV)
        return;
    else
        A[ulParentU] = ulParentV;
}

// Using Union by rank
// int find(int A[],int X)
// {
//     if(X == A[X]) return X;

//     return A[X] = find(A, A[X]);
// }
// void unionSet(int A[],int X,int Z)
// {
// 	int ultimateParU = find(A, X);
// 	int ultimateParV = find(A, Z);

// 	if(ultimateParU == ultimateParV) return;
// 	else A[ultimateParU] = ultimateParV;
// }
