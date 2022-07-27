#include <iostream>
using namespace std;

int main()
{
    int A[] = {1, 2};
    int size = sizeof(A) / sizeof(A[0]);
    if(size<2)
    {
        cout<<"array must have atlesast 2 element";
    }
    if (size == 2)
    {
        if (A[0] > A[1])
        {
            cout << "not sorted";
            return 0;
        }
    }
    else
    {
        for (int i = 0; i < size - 2; i++)
        {
            if (A[i] > A[i + 1])
            {
                cout << "not sorted";
                return 0;
            }
        }
    }

    cout << "sorted";
    return 0;
}