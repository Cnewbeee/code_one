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
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]), dp[i-2] + abs(v[i] - v[i-2]));
    }
    cout << dp[n] << endl;
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
