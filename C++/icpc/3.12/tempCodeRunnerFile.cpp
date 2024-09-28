#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
 
void perm(int a[], int begin, int n)
{
	if (begin == n)
	{
		for (int i = 1; i <= n; i++)
		{
			printf("%5d", a[i]);
		}
		printf("\n");
	}
	else
	{
		for (int k = begin; k <= n; k++)
		{
			swap(a, begin, k);
			perm(a, begin + 1, n);
			swap(a, begin, k);
		}
	}
}
 

int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1] = {0};
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	perm(a, 1, n);
    return 0;
}