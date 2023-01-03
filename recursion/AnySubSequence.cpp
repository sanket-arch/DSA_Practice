// we have to print any one the sub sequnce of the array whose sum is equal to the the key given
// for example:- if arr is [1,2,1] and key given is 2 then we have to print [1,1]


//APPROACH:- if any function say i got the answer then return true and stop the furthur recursion


#include <bits/stdc++.h>
using namespace std;

bool sumK(int idx, int arr[], vector<int> ds, int n, int sum, int key)
{
    if (idx == n)
    {
        if (sum == key)
        {
            for (auto itr : ds)
                cout << itr << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[idx]);
    if (sumK(idx + 1, arr, ds, n, sum + arr[idx], key) == true)
        return true;
    ds.pop_back();
    if (sumK(idx + 1, arr, ds, n, sum, key) == true)
        return true;
    return false;
}
int main()
{
    int arr[] = {1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    int key = 2;
    sumK(0, arr, ds, size, 0, key);
    return 0;
}