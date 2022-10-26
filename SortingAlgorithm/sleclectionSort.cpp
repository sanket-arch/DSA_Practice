#include <bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;
        for (int j = i + 1; i < n; i++)
        {
            if (A[j] < A[imin])
            {
                imin = j;
            }
        }
        int temp = A[i];
        A[i] = A[imin];
        A[imin] = temp;
    }
}
int main()
{
    int A[] = {1, 6, 4, 3, 8, 2};
    int n = sizeof(A) / sizeof(A[0]);
    selectionSort(A, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}