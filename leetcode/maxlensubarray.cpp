#include <iostream>
using namespace std;
int lenOfLongSubarr(int A[], int N, int K)
{
    int start=0,currlen=0,maxlen=0;
    int sum=0,i=0;

    while(i<N)
    {
        sum+=A[i];
        if(sum==K)
        {
            sum-=A[start];
            currlen=(i-start)+1;
            if(currlen>maxlen)
            {
                maxlen=currlen;
            }
            start++;
        }
    }
    // Complete the function
}
int main()
{

    return 0;
}