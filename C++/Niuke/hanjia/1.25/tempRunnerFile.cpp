#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 3e3 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    int g[N][N];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= m; i++){
        int gg[N][N], cnt[N] = {0}, cnt1 = 0;
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                if(g[j][i] == 0) gg[j][k] = 1 - g[j][k];
                else gg[j][k] = g[j][k];
                if(gg[j][k] == 0) cnt[k]++;
            }
        }

        for(int j = 1; j <= m; j++){
            if(!cnt[j])cnt1++;
            cout << cnt[j] << " ";
        }
        cout << endl;
        ans = max(ans, cnt1);
    }
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    // cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
