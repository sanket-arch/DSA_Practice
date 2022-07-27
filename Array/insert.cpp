#include <iostream>
using namespace std;

int searchPos(int A[], int size, int target)
{
    int high = size - 1;
    int low = 0;
    int mid;
    while (high >= low)
    {
        mid = (high + low) / 2;
        if (target > A[mid] && target < A[mid + 1])
            return mid + 1;
        else if (target < A[mid] && target > A[mid - 1])
            return mid;
        else if (target < A[mid])
            high = mid;
        else
            low = mid + 1;
    }
}
int main()
{
    int A[14] = {1, 2, 3, 4, 7, 8, 10, 11, 12, 13, 14, 18, 33};
    int pos, target = 9, i = 12;

    // one method
    // pos=searchPos(A,9,target);
    // for(int i=12;i>=pos;i--)
    // {
    //     A[i+1]=A[i];
    // }
    // A[pos]=target;

    // second method

    while (A[i] >= target)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i] = target;
    for (int i = 0; i < 14; i++)
    {
        cout << A[i] << "  ";
    }
    return 0;
}