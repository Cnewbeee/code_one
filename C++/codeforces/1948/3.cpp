#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
string a[2];
int n, flag = 0;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int st[2][N];

void dfs(int x, int y){
    if(x == 1 && y == n-1){
        flag = 1;
        return;
    }
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx >= 2 || yy >= n || xx < 0 || yy < 0 || st[xx][yy])continue;
        st[xx][yy] = 1;
        if(a[xx][yy] == '>') yy++;
        else yy--; 
        //cout << xx << " : " << yy << endl;
        st[xx][yy] = 1;
        dfs(xx, yy);
    }
}
void solve()
{
    cin >> n;
    for(int i = 0; i < 2; i++){
        cin >> a[i];
    }
    flag = 0;
    memset(st, 0, sizeof st);
    st[0][0] = 1;
    dfs(0, 0);
    if(flag)cout << "YES" << endl;
    else cout << "NO" << endl;
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
