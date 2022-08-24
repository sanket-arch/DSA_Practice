#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int minSwaps(vector<int> &nums)
{
    vector<int> A=nums;
    int count = 0;
    sort(A.begin(), A.end());
   
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != nums[i])
            count++;
    }
    return count/2;
}

int main()
{
    vector<int> nums = {2, 8, 5, 4};

    cout<<minSwaps(nums);
    return 0;
}
