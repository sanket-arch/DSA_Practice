//we have to print all the sub sequnce of the array whose sum is equal to the the key given
//for example:- if arr is [1,2,1] and key given is 2 then we have to print [1,1],[2]

#include <bits/stdc++.h>
using namespace std;

void sumK(int idx, int arr[], vector<int> ds, int n, int sum, int key)
{
    if (idx == n)
    {
        if (sum == key)
        {
            for (auto itr : ds)
                cout << itr << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[idx]);
    sumK(idx + 1, arr, ds, n, sum + arr[idx], key); // pick
    ds.pop_back();
    sumK(idx + 1, arr, ds, n, sum, key); // not pick
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