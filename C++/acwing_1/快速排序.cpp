#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int f[N];
void quick_sort(int f[], int l, int r)
{
    if(l >= r) return ;

    int x = f[(l+r) >> 1];
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(f[i] < x);
        do j--; while(f[j] > x);
        if(i < j) swap(f[i], f[j]);
    }

    quick_sort(f, l, j);
    quick_sort(f, j+1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i ++){
        scanf("%d", &f[i]);
    }

    quick_sort(f, 0, n-1);

    for(int i = 0; i < n; i ++){
        printf("%d ", f[i]);
    }
}

