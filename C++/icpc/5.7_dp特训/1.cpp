#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int a[N];
int dp[N];
int cost(int x, int y){
    return abs(a[x] - a[y]);
}

void solve()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    dp[1] = cost(0, 1);

    for(int i = 2; i < n; i++){
        dp[i] = min(cost(i, i-1)+dp[i-1], cost(i, i-2)+dp[i-2]);
    }
    
    cout << dp[n-1] << endl;
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
