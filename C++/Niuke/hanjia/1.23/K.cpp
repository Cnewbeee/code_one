#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 500 + 10;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int st[N][N] = {0};
char g[N][N];
vector<PII> v, p;

bool check(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

int dfs(int x, int y){
    //cout << x << " " << y << endl;
    st[x][y] = 1;
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx, ny) && g[nx][ny] == '0' && st[nx][ny] == 0){
            st[nx][ny] = 1;
            p.push_back({nx, ny});
            // cout << nx << " " << ny << endl;
            cnt++;
        }else if(check(nx, ny) && g[nx][ny] == '1' && st[nx][ny] == 0){
            st[nx][ny] = 1;
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

void solve()
{
    cin >> n >> m;
    int r = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            if(g[i][j] == '0')r = 1;
            else v.push_back({i, j});
        }
    }
    if(!r){
        cout << 0 << endl;
        return;
    }
    int ans = 1e9;
    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        if(st[x][y] == 0){
            // memset(st, 0, sizeof(st));
            ans = min(ans, dfs(x, y));
            for(int j = 0; j < p.size(); j++){
                st[p[j].first][p[j].second] = 0;
            }
            p.clear();
        }
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
