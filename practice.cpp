#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int firstRepeated(int A[], int n)
{
    if (n == 1)
    {
        return -1;
    }
    if (n == 2)
    {
        if (A[0] == A[1])
            return 1;
        else 
            return -1;
    }
    long long max = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    long long *H = new long long[max];
    long long *k = new long long[max];
    long long index = n + 1;

    for (int i = 0; i < n; i++)
    {
        H[A[i]] = 0;
        k[A[i]] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
        if (k[A[i]] == 0)
        {
            k[A[i]] = i + 1;
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if (H[i] > 1 && k[i] != 0)
        {
            if (k[i] < index)
                index = k[i];
        }
    }

    if (index == n + 1)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

int main()
{
    int nums[] = {1,2,3,4,4};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << firstRepeated(nums, size);
    return 0;
}
