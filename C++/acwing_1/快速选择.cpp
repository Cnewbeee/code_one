#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n, k;
int f[N];
int quick_sort(int l, int r, int k)
{
    int i = l-1, j = r+1;
    if(l == r) return f[l];

    int x = f[(l+r) >> 1];
    while(i < j){
        while(f[++i] < x);
        while(f[--j] > x);
        if(i < j) swap(f[i], f[j]);
    }

    int s1 = j - l + 1;
    if(s1 >= k) return quick_sort(l, j, k);

    return quick_sort(j+1, r, k-s1);
}

int main ()
{
    cin >> n >> k;

    for(int i = 0 ; i < n; i++){
        cin >> f[i];
    }

    cout << quick_sort(0, n-1, k) << endl;
}