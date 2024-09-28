#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 10;
int n;
char g[N][N];
bool col[N], dg[N*2], udg[N*2];

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++)puts(g[i]);
        puts("");
        return ;
    }
    for(int i = 0; i < n; i++){
        if(!col[i] && !dg[u+i] && !udg[n-u+i]){
            g[u][i] = 'Q';
            col[i] = dg[u+i] = udg[n-u+i] = 1;
            dfs(u+1);
            g[u][i] = '.';
            col[i] = dg[u+i] = udg[n-u+i] = 0;
        }
    }
}

signed main(void)
{
	cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    dfs(0);

	return 0;
}
