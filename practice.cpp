#include <bits/stdc++.h>
using namespace std;
int maximizeSum(int a[], int n)
{
	int MaxEle = -INFINITY;
	for (int i = 0; i < n; i++)
	{
		MaxEle = max(MaxEle, a[i]);
	}
	int *freq=new int[MaxEle + 1];

	memset(freq, 0, sizeof(freq));

	for (int i = 0; i < n; i++)
	{
		freq[a[i]]++;
	}

	int x = MaxEle;
	int sum = 0;
	while (x > 0)
	{
		if (freq[x] > 0)
		{
			sum += x;
			freq[x - 1]--;
			freq[x]--;
		}
		else
			x--;
	}
	return sum;
}

int main()
{
	int A[]={1,2,2,2,3,4};
	int n=sizeof(A)/sizeof(A[0]);
	cout<<maximizeSum(A,n);
	return 0;
}