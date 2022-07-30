/* Here we have to find number of  pair of elemnts whose sum is equal to given value*/

// CASES TO BE TAKEN CARE

/* 1. whether array have repated array or not
   2.array have 0 as element?
   3.arry have negative as element or not
   4.sum will be negative or not
   5.whether Array is sorted or not;
*/

// This code will take care of all the cases

#include <iostream>
using namespace std;

// When unsorted & sorted
int PairSum(int A[], int size, int sum, int high)
{

    int *H = new int[high + 1]; // Hash table array
    int count = 0;
    for (int i = 0; i <= high; i++)
    {
        H[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (H[sum - A[i]] != 0 && sum - A[i] >= 0)
        {
            count++;
        }
        H[A[i]]++;
    }
    delete[] H;
    return count;
}

// when sorted
int pairSumSorted(int A[], int size, int sum)
{
    int i = 0, j = size - 1, k;
    int count = 0;
    while (j > i & i != j)
    {
        k = A[i] + A[j];
        if (k > sum)
            j--;
        if (k < sum)
            i++;
        else
        {
            count++;
            cout << A[i++] << "+" << A[j--] << "=" << sum << endl;
        }
    }
    return count;
}

int main()
{
    int A[] = {0,3, 4, 8, 10, 11, 5, 4, 15};
    int A1[] = {-3, 0, 2, 4, 6, 9};
    int sz = sizeof(A) / sizeof(A[0]);
    int sz1 = sizeof(A1) / sizeof(A1[0]);
    int high = 15, sum = 8; // sum can't be negativw
    cout << PairSum(A, sz, sum, high) << endl;
    cout << pairSumSorted(A1, sz1, 6) << endl;
    return 0;
}
// Both function have time complexity of (n)