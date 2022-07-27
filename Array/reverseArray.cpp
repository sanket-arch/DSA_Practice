#include <iostream>
using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 5,7,8,9};
    int temp;
    int size = sizeof(A) / sizeof(A[0]) - 1;
    int mid = size / 2;
    
    for (int i = 0; i <=mid; i++)
    {
        temp = A[i];
        A[i] = A[size - i];
        A[size - i] = temp;
    }
    // if (size % 2 != 0)
    // {
    //     temp = A[mid];
    //     A[mid] = A[mid + 1];
    //     A[mid + 1] = temp;
    // }
    for (int i = 0; i <= size; i++)
    {
        cout << A[i] << "  ";
    }
    return 0;
}