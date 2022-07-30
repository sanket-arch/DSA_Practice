#include <iostream>
using namespace std;

int main()
{
    int A[] = {3,7,12,6,1,9,6,2,10};
    int high, low;
    int *H;
    int sz=sizeof(A)/sizeof(A[0]);

    // we will find the high and low here
    high = 12;
    low = 1;

    H = new int[high + 1];
    for (int i = 0; i <= high; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < sz; i++)
    {
        H[A[i]]++;
    }
    for (int i = 1; i <= high; i++)
    {
        if (H[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}