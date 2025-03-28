#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n], cnt = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int ans = 1;
    if(n == k){
        for(int i = 1; i < k; i+=2){
            if(a[i] == ans)ans++;
            else break;
        }
        cout << ans << endl;
    }else{
        for(int i = 1; i < n; i++){
            if(a[i] == 1)cnt++;
            else break;
        }
        // cout << cnt << '<' << endl;
        if(cnt <= n-k+1)cout << 1 << endl;
        else cout << 2 << endl;
    }
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
