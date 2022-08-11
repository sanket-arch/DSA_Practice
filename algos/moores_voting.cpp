#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> A)
{
    int ansIndex = 0;
    int count = 1;
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        if (A[i] == A[ansIndex])
            count++;
        else
            count--;
        if (count == 0)
        {
            ansIndex = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[ansIndex] == A[i])
        {
            count++;
        }
    }

    if (count > n / 2)
        return A[ansIndex];
    else
        return 0;
}

int main()
{   vector<int> A={3,1,3,1,3,3,5,3,7};

    cout<<majorityElement(A);
    return 0;
}