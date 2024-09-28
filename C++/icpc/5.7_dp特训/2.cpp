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
    int n, k;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = 1e9;
    }
    dp[1] = 0;
    dp[2] = cost(2, 1);

    for(int i = 3; i <= n; i++){
        if(i - k <= 0)for(int j = 1; j < i; j++){
            dp[i] = min(cost(i, j)+dp[j], dp[i]);
            //cout << dp[i] << endl;
        }else for(int j = i-k; j < i; j++){
            dp[i] = min(cost(i, j)+dp[j], dp[i]);
        }
        //cout << dp[i] << " ";
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
