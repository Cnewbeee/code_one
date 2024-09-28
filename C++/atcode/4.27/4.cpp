#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1000 + 10;
int n, m;
char g[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool st[N][N] = {false};
int ans = 0;
set<PII> se;
int cnt = 0;
void dfs(int a, int b){
    if(g[a][b] == '&'){
        cnt = 1;
        return ;
    }
    st[a][b] = true;
    cnt ++;
    for(int i = 0; i < 4; i++){
        int x = a + dx[i], y = b + dy[i];
        if(x < 0 || x >= n || y < 0 || y >= m || st[x][y]) continue;
        if(g[x][y] == '&'){se.insert({x, y});}
        else if(g[x][y] != '#'){
            dfs(x, y);
            //st[a][b] = false;
        }
    }
    
}
void dfs1(int a, int b){
    for(int i = 0; i < 4; i++){
        int x = a + dx[i], y = b + dy[i];
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        if(g[x][y] == '#'){g[a][b] = '&'; break;}
    }
}

void solve()
{
    //cout << 1 << endl;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != '#'){
                //memset(st, false, sizeof st);
                dfs1(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != '#'){
                //memset(st, false, sizeof st);
                se.clear();
                cnt = 0;
                dfs(i, j);
                ans = max((int)se.size()+cnt, ans);
                //for(auto a : se)cout << a.first << " " << a.second << endl;
                //cout << endl;
            }
        }
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
