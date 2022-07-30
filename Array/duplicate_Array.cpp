#include <iostream>
using namespace std;

int main()
{
    int A[] = {3, 6, 8, 8, 12, 15, 15, 15, 15, 21, 21, 22, 22};
    int sz = sizeof(A) / sizeof(A[0]);
    int max = A[sz - 1];
    int *H = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < sz; i++)
    {
        H[A[i]]++;
    }
   
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1)
        {
            cout << i << "=" << H[i] << endl;
        }
    }
    delete[] H;
    return 0;
}