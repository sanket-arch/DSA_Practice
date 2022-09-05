#include <iostream>

using namespace std;

void rearrange(int A[], int n)
{
    int pos=0, neg=0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
            pos++;
        else
            neg++;
    }
    int *posArr = new int[pos];
    int *negArr = new int[neg];
    int k = 0, i = 0, j = 0;
    while (k < n)
    {
        if (A[k] >= 0)

            posArr[i++] = A[k++];
        else
            negArr[j++] = A[k++];
    }
    k = 0, i = 0, j = 0;
    while(i < pos && j < neg)
    {
        if (k % 2 == 0)
            A[k++] = posArr[i++];
        else
            A[k++] = negArr[j++];
    }
    if(i>pos)
    {
        while(j<neg)
        {
            A[k++]=negArr[j++];
        }
    }
    else{
        while(i<pos)
        {
            A[k++]=negArr[i++];
        }
    }
}
int main()
{
    int A[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int size = sizeof(A) / sizeof(A[0]);

    rearrange(A, size);
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}