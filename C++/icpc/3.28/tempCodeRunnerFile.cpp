#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int N = 110;

int g[N][N];
int st[N][N] = {0};
PII ma = {1, 1};
int r, c;
int ans = 1;
void dfs(int x, int y, int u){
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};

    //cout << u << endl;
    ans = max(ans, u);
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 1 || xx > r || yy < 1 || xx > c || g[xx][yy] >= g[x][y] || st[xx][yy] == 1)continue;
        st[xx][yy] = 1;
        dfs(xx, yy, u+1);
        st[xx][yy] = 0;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> r >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> g[i][j];
            //if(g[i][j] > g[ma.first][ma.second]) ma = {i, j};
        }
    }
    //cout << g[ma.first][ma.second] << " <<< " << endl;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            dfs(i, j, 1);
        }
    }

    cout << ans << endl;

	return 0;
}
