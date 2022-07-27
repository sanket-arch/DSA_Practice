#include <iostream>
using namespace std;

int bSearch(int A[], int x, int size)
{   int mid;
    int high = size ;
    int low = 0;
    while (high >= low)
    {
         mid = (high + low) / 2;
        if (x == A[mid])
           return mid;
        else if (x > A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    
     return -1;
}

int shiftA(int A[], int pos, int size)
{
    for (int i = pos; i < size; i++)
        A[i] = A[i + 1];
    return --size;
}
int main()
{
    int size, target;
    int A[20];
    cout << "enter how many element array have";
    cin >> size;
 
    cout << "enter the elements";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    cout << "enter the element you want to delete";
    cin >> target;
    int pos = bSearch(A, target, size);
    cout<<pos<<endl;
    if (pos == -1)
    {
        cout << "element doesnot exist" << endl;
        cout << "Array is";
        for (int i = 0; i < size; i++)
        {
            cout << A[i] << "  ";
        }
    }

    else
    {
        size = shiftA(A, pos, size);

        cout << "New Array is" << endl;
        for (int i = 0; i < size; i++)
            cout << A[i] << "  ";
    }

    return 0;
}