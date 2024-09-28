#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, m;
int a[N];

int erfen(int l, int r, int x){
    while(l < r){
        int mid = l + r >> 1;

        if(a[mid] >= x) r = mid;
        else l = mid+1;
    }
    return l;
}

signed main(void)
{
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    while(m--){
        int x;
        cin >> x;
        int ans = erfen(0, n-1, x);
        if(a[ans] == x)
            cout << ans+1 << " ";
        else
            cout << -1 << " ";
    }

	return 0;
}
