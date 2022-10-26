// This algo is called buble shor because after each pass heaviest element get setteled down at the base or say the greatest
// element get sorted after each pass.

#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int A[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0; //This will take care of the case when given array is already sorted.
        // Here, we subtracted i because after each pass there will be one less swap
        for (int j = 0; j < n - 1 - i; j++)        
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) //if there were no swapped happend in last comparison then it mean that array sorted
                        // so, there will be no compariosn will  required and we can break out of the loop, Hence saving lot of time in comnpriosn.
            break;
    }
}
int main()
{
    int A[] = {8, 5, 7, 3, 2};
    int size = sizeof(A) / sizeof(A[0]);
    bubbleSort(A, size);

    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}

// Time complexit =>
                // best case ->O(N),this will happen when array is given is already sorted.
                // worst case-> O(N*N),It is genral scanerio.



// criteria analysis
//  No. of comaprison:-(N-1)
// No. of Swaps(N-1)
// Adaptive: YES
// Stable: YES
// Extra space: NO