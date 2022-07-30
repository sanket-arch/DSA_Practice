/* Find min and max in an array in an unsorted array in one go */

#include <iostream>
using namespace std;

int main()
{
    int A[] = {5, 8, 3, -9, 6, 2, 10, 7, -1, 4};
    int min = A[0];
    int max = A[0];
    int sz = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < sz; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
        else if (A[i] < min)
        {
            min = A[i];
        }
    }
    cout << min << " " << max << endl;
    return 0;
}