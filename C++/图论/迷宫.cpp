#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1010;
int n, m;
char g[N][N];
int d[N][N];
int ans[N*N];
bool check(int x, int y){
    return x < n && x >= 0 && y < n && y >= 0;
}
void dfs(int r,int c,int z,int lll){
    if (r<0 || r>=n || c<0 || c>=n || d[r][c]!=-1 || g[r][c]-'0'!=z)return;
    d[r][c]=lll;ans[lll]++;
    dfs(r-1,c,!z,lll);
    dfs(r+1,c,!z,lll);
    dfs(r,c-1,!z,lll);
    dfs(r,c+1,!z,lll);
}
signed main(void)
{
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    memset(d, -1, sizeof d);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (d[x][y]==-1)
            dfs(x,y,g[x][y]-'0',i);
        else 
            ans[i]=ans[d[x][y]];
    }
    for (int i=0;i<m;i++)
        printf("%d\n",ans[i]);

	return 0;
}
