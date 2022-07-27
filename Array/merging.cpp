#include <iostream>

using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    int B[] = {8, 9, 10, 11, 12, 14, 15, 16};
    int c[14];
    int Asize = sizeof(A) / sizeof(A[0]);
    int Bsize = sizeof(B) / sizeof(B[0]);
    int i = 0, j = 0, k = 0;
    while (i != Asize && j != Bsize)
    {
        if (A[i] < B[j])
        {
            c[k] = A[i];
            k++;
            i++;
        }
        else
        {
            c[k] = B[j];
            k++;
            j++;
        }
    }
    if (j == Bsize)
    {
        for (; i < Asize; i++)
        {
            c[k] = A[i];
            k++;
        }
    }
    else
    {
        for (; j < Bsize; j++)
        {
            c[k] = B[j];
            k++;
        }
    }

    for (int x = 0; x < 14; x++)
    {
        cout << c[x] << "  ";
    }
    return 0;
}