#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int r;
    cin >> r;
    ll ans = 0;
    for(int i = 0; i < r + 1; i++){
        ans += (ll)sqrt(1ll * (r+1) * (r+1) - 1ll * i * i - 1);
        if(i < r)
            ans -= (ll)sqrt(1ll * r * r - 1ll * i * i - 1);
    }
    cout << ans * 4 << endl;
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
