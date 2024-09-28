#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int N = 110;

int g[N][N];
int d[N][N] = {0};
int r, c;
int ans = 1;
int dfs(int x, int y){
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};

    if(d[x][y] && x != 1 && y != 1){
        return d[x][y];
    }
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx > 0 && xx <= r && yy > 0 && xx <= c && g[xx][yy] > g[x][y]){
            d[x][y] = max(dfs(xx, yy)+1, d[x][y]);
        }
    }
    if(!d[x][y])d[x][y]= 1;
    return d[x][y];
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
    d[1][1] = 1;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            ans = max(dfs(i, j), ans);
        }
    }

    cout << ans << endl;

	return 0;
}
