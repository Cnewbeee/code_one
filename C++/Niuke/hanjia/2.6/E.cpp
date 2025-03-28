#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e3 + 10;

void solve()
{
    int n, m;
    int g[N][N], zh[2*N] = {0}, ni[2*N] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> g[i][j];
            zh[i-j+m] += g[i][j];
            ni[i+j-1] += g[i][j];
        }
            
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans = max(ans, (zh[i-j+m] + ni[i+j-1] - g[i][j]));
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
