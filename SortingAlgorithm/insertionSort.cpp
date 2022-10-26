//In insertion sort we insert the element at sorted position.
//This algorithm is more compatible with linked list,because in linked we dont have to shift the element we just need to 
//find the position where it need to inserted.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int size)
{
    int j, x;

    //This loop will start from 1 because we assume that first element is already sorted.
    for (int i = 1; i < size; i++)  //This loop will be used for passes.
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)  //j=-1, comndition will check when x need to be inserted at 0th positon.
        {
            A[j + 1] = A[j]; //shifting the element if it is greater than the current x.
            j--;
        }
        A[j + 1] = x; // we have to inwseted the value in front of the position where th j is pointing.
    }
}
int main()
{
    int A[] = {6, 3, 4, 6, 8, 2, 1, 5};
    int size = sizeof(A) / sizeof(A[0]);
    insertionSort(A, size);
    for (int i = 0; i < size; i++)
    {
        cout << A[i]<<" ";
    }
    return 0;
}

// TIME COMPLEXITY:= O(N*N)