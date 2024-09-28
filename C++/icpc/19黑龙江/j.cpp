#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1000 + 10;
int n, m;
int a[N][N], b[N][N];
ll sumb;
int a0;
int r = 0;
bool check(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m)return false;
    sumb += b[x][y];
    if(a[x][y] - a0 - sumb >= 0)return true;
    else {sumb -= b[x][y];return false;}
}
    
void dfs(int x, int y){
    if(r)return ;
    if(x == n-1 && y == m-1){
        r = 1;
        return ;
    }
    for(int i = 0; i < 2; i++){
        int xx, yy;
        if(i == 0)xx = x + 1, yy = y;
        else xx = x, yy = y + 1;
        if(xx == n-1 && yy == m-1){
            r = 1;
            return ;
        }
        if(!check(xx, yy)){continue;}
        if(r)return ;
        //cout << xx << " : " << yy << "  ";
        dfs(xx, yy);
        if(r)return ;
        sumb -= b[xx][yy];
        //cout << sumb << "  ";
    }
}
void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &b[i][j]);
        }
    }
    sumb = b[0][0];
    a0 = a[0][0];
    dfs(0, 0);
    if(r)puts("YES");
    else puts("NO");
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
