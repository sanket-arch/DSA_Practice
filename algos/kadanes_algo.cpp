#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int maxSumSubarry(vector<int>  A)
{
    long long maxSum=-INFINITY;
    long long currSum=0;
    for(int i=0;i<A.size();i++)
    {
        currSum+=A[i];
        if(currSum>maxSum)
        {
            maxSum=currSum;
        }
        if(currSum<0)
        {
            currSum=0;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> A={-1,-2,-7,-4,-10,-1};
    cout<<maxSumSubarry(A);

 return 0;
}