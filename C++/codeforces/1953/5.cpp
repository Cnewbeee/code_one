#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int n, k, q;
ll a[N], b[N];
void solve()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
    }for(int i = 1; i <= k; i++){
        cin >> b[i];
    }
    while(q--){
        ll x;
        cin >> x;
        int p = lower_bound(a, a+k, x) - a;
        ll ans;
        if(a[p] == x){
            ans = b[p];
        }else{
            ans = b[p-1] + ((x-a[p-1])*(b[p]-b[p-1])/(a[p]-a[p-1]));
        }
        printf("%lld ", ans);
    }
    printf("\n");
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
