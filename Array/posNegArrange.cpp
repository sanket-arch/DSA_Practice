#include <iostream>
using namespace std;

int main()
{
    int A[11] = {-10, 8, -2, 3, 4, 7, -18, -1, 11, -14, -7};

    int i = 0, j = 10, temp;
    while (i < j)
    {
        while (A[i] < 0)
        {
            i++;
        }
        while (A[i] >= 0)
        {
            j++;
        }
        if (i < j)
        {
            temp = A[i];
            A[j] = A[i];
            A[i] = temp;
        }
    }

    for (int i = 0; i < 11; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}