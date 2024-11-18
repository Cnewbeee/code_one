#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

struct Path{
    int x,y;
    char c;
} ans[20];

char g[4][4], gg[4][4];
bool st[4][4], flag = false;
int cnt = 0;
int num[]{3,3,3,4,3};

bool inArea(int x,int y){
    return x>=0 && x<4 && y>=0 && y<4;
}

bool check(int x, int y, int k){
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++)
            if(inArea(i,j) && g[i][j] == (k+'A'))
                return false;
    return true;
}

void dfs(int s, int x, int y, int kk){
    st[x][y] = true;
    num[kk]--;
    g[x][y] = char(kk+'A');
    ans[s].c = char(kk+'A');
    ans[s].x = (x+1);
    ans[s].y = (y+1);
    //cout << s << " __________________ " << cnt << endl;
    //cout << x << " " << y << " " << char(kk+'A') << endl;
    if(s == 16){
        if(!flag){
            for(int i = 1; i <= 16; i++){
                cout<<ans[i].c<<" "<<ans[i].x<<" "<<ans[i].y;
                cout << endl;
            }
            flag = true;
        }
        cnt++;
    }else{
        for(int k = 0; k < 5; k++){
            if(num[k] > 0){
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        if(num[k] > 0 && !st[i][j] && check(i, j, k))
                            dfs(s+1, i, j, k);
                    }
                }
            }
        }
    }
    num[kk]++;
    g[x][y] = gg[x][y];
    st[x][y] = false;
}

void solve()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> g[i][j];
            gg[i][j] = g[i][j];
        }
    }
    memset(st, false, sizeof(st));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(check(i, j, 3) && !st[i][j])
                dfs(1, i, j, 3);
        }
    }

    cout << cnt << endl;
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
