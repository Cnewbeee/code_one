#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
char g[101][101]; 
int vis[101][101];
int n = 1, m;


bool check(int x, int y){
    return x >= 0 && x < n && y < m && y >= 0;
}

void dfs(int x, int y){
    int dx[8]={-1,1,0,0,-1,-1,1,1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};

    vis[x][y] = 1;
    for(int i = 0; i < 8; i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        //cout << nx << " " << ny << " " << vis[nx][ny] << " " << g[nx][ny] << endl;
        if(check(nx, ny) && !vis[nx][ny] && g[nx][ny] == '@'){
            //cout << nx << " " << ny << endl;
            dfs(nx, ny);
        }
    }
}
void solve(){
     while(n){
        memset(vis, 0, sizeof vis);
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) return ;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> g[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == '@' && !vis[i][j]){
                    ans++;
                    //cout << i << " " << j << "<<<<" << vis[i][j] << endl;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
}

signed main(void)
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    solve();
	return 0;
}
