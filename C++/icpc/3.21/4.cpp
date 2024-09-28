#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;


signed main(void)
{
	ll n, q;
	cin >> n >> q;

	ll a[n+1] = {0};
	ll d[n+1] = {0};
	for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
    {
        d[i] = a[i] + d[i-1];
    }
    for(int i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        if(x < d[1]){
            cout << 0 << endl;
            continue;
        }
        int l = 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(d[mid] <= x) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }

	return 0;
}
