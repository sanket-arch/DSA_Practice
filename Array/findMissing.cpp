#include <iostream>
using namespace std;

int main()
{
    int k = 0, n;
    int *A, sz, diff = 0;
    cout << "enter the size of Array";
    cin >> sz;

    A = new int[sz];

    for (int i = 0; i < sz; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < sz - 1; i++)
    {
        diff = A[i + 1] - A[i];

        if (diff != 1)
        {
            n = diff - 1;
            for (int j = 1; j <= n; j++)
            {
                A[k++] = A[i] + j;
            }
        }
    }
    for (int j = 0; j < k; j++)
    {
        cout << A[j] << "  ";
    }

    return 0;
}