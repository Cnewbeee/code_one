#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 5e4 + 10;
int dp[N];
void solve()
{
    int n, x;
    cin >> n >> x;
    PII arr[n];
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        s += arr[i].second;
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int a = arr[i].first, b = arr[i].second;

        for(int j = s; j >= 0; j--){
            if(dp[j] >= a){
                dp[j+b] = max(dp[j+b], dp[j]-a);
            }
        }
        for(int j = 0; j <= s; j++){
            if(dp[j] >= 0)dp[j] += x;
        }
    }
    int ans = 0;
    for(int i= 0; i <= s; i++){
        if(dp[i] >= 0){
            ans = i;
        }
    }
    cout << ans << endl;
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
