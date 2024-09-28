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
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n, q;
    cin >> n >> q;
    ll a[n+1] = {0}, b[n+1] = {0};
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(ll i = 1; i <= n; i++){
        b[i] = a[i] + b[i-1];
    }
    while(q--){
        ll l, r;
        cin >> l >> r;

        cout << b[n-l+r] - b[n-l] << endl;
    }

	return 0;
}
