#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 110;
char g[N][N];
bool b[N][N];
int n, m;
bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y){
    int d[3] = {-1, 0, 1};
    b[x][y] = true;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(d[i] == 0 && d[j] == 0) 
                continue;
            int dx = x + d[i];
            int dy = y + d[j];
            if(check(dx, dy) && !b[dx][dy] && g[dx][dy] == 'W') {
                b[dx][dy] = true;
                dfs(dx, dy);
            }

        }
    }
}

signed main(void)
{
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'W' && !b[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

	return 0;
}
