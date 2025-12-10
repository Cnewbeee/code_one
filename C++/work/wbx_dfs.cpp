#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100 + 10;
int g[N][N];
int vis[N];
int dis;
int n, m;

void dfs(int u, int v)
{   if(u == n){
        dis = min(dis, v);
        return;
    }
    
    for(int i = u; i <= n; i++){
        if(g[u][i] && !vis[i]){
            vis[i] = 1;
            dfs(i, v + g[u][i]);
            vis[i] = 0;
        }
    }
}

void solve()
{
    while(1){
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        dis = INT_MAX;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            g[a][b] = c;
            g[b][a] = c;
        }
        vis[1] = 1;
        dfs(1, 0);
        if(dis == INT_MAX) cout << -1 << endl;
        else cout << dis << endl;
    }

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
