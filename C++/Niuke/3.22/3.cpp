#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e3 + 10;
int cntb = 0, cnt = 0;
char a[N][N];
int bel[N][N];
set<int> bu[N*N];
int n, m;
int px[4] = {-1, 0, 1, 0}, py[4] = {0, -1, 0, 1};
void dfs(int x, int y, int id){
    a[x][y] = '@';
    bel[x][y] = id;
    for(int i = 0; i < 4; i++){
        int xx = x + px[i], yy = y + py[i];
        if(xx < 1 || yy < 1 || xx > n || yy > m || a[xx][yy] != '#'){
            continue;
        }
        dfs(xx, yy, id);
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] == '.') cntb++;
        }
    }
    if(cntb == n * m) {
        cout << "Blue" << endl;
        return ;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '#'){
                dfs(i, j, ++cnt);
            }
        }
    }
    for(int i = 1; i <= cnt; i++){
        bu[i].clear();
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '.'){
                for(int k = 0; k < 4; k++){
                    int xx = i + px[i], yy = j + py[i];
                    if(xx < 1 || yy < 1 || xx > n || yy > m || a[xx][yy] != '@'){
                        continue;
                    }
                    bu[bel[xx][yy]].insert((i - 1) * m + j);
                }
            }
        }
    }
    for(int i = 1; i <= cnt; i++){
        if(bu[i].size() == cntb){
            cout << "Red" << endl;
            return ;
        }
    }
    cout << "Draw" << endl;
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
