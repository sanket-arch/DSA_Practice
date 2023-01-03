// Print the sub sequence of the Array and printed element should have index number greater than the before one
// let's assume array=[3,1,2] then sub sequence genrated will
//[],[3],[1],[2].[3,1],[3,2],[1,2],[3,1,2]

// In this problem we have applied take and non-take  technique
#include <bits/stdc++.h>
using namespace std;

void squence(int idx, vector<int> &ds, int arr[], int n)
{
    if (idx == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // current element will be taken
    ds.push_back(arr[idx]);

    // take condition
    squence(idx + 1, ds, arr, n);

    // current element will not be taken
    ds.pop_back();

    // Not take condition
    squence(idx + 1, ds, arr, n);
}

int main()
{
    int A[] = {3, 1, 2, 5, 6};
    int size = 5;
    vector<int> ds;

    squence(0, ds, A, size);

    return 0;
}

// Time complexity

// so for every element we have 2 option i.e. whether to take and not-take, so it is 2^n and also
// we are printing eelement in n using loop which goes for n time. so, the final time complexity will be
// O(n*2^n)

// Space Complexity

// At ant given moment there will be at max 3 function waiting in the stack therefore the auxilary spece
// complexity will be O(n);