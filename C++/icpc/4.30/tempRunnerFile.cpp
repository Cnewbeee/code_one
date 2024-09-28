#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 100 + 10;
int h, w;
char s[110][110], a[] = "snuke";
bool st[110][110];
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
vector<PII> ans;

void dfs(int x, int y, int u){
    if(s[x][y] == a[u]){
        ans.push_back({x, y});
    }else{
        return ;
    }
    if(u == 4){
        for(PII k : ans){
            cout << k.first+1 << " " << k.second+1 << endl;
        }
        exit(1);
    }
    st[x][y] = true;
    for(int i = 0; i < 8; i++){
        int xx = dx[i] + x, yy = dy[i] + y;
        if(x < 0 || x >= h || y < 0 || y >= w || st[xx][yy])continue;
        dfs(xx, yy, u+1);
    }
}

void solve()
{
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == a[0]){
                ans.clear();memset(st, false, sizeof st);
                dfs(i, j, 0);
            }
        }
    }
    
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
