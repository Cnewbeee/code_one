#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int, int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int t;cin >> t;
        sum += t;
    }
    if(n == 1){
        cout << sum << endl;
        return ;
    }
    if(sum == 0){
        cout << 0 << endl;
        return ;
    }
    int k = ceil(double(sum) / n);
    //cout << k << endl;
    int ans = sum;
    for(ll i = k; i <= sum; i++){
        ll s = sum % i;
        ans = min(ans, (s|i));
        if((s|i) == i)break;
    }
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
