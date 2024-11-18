#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int len[4], r = 0;
int u[3]={0};
bool st[4];

void dfs(int s){
    if(s == 3){
        if(u[0] < u[1]+u[2] && u[1] < u[0]+u[2] && u[2] < u[0]+u[1]){
            r = 1;
        }else if(r == 0 && (u[0] <= u[1]+u[2] && u[1] <= u[0]+u[2] && u[2] <= u[0]+u[1])){
            r = 2;
        }
        return;
    }

    for(int i = 0; i < 4; i++){
        if(!st[i]){
            u[s] = len[i];
            st[i] = true;
            dfs(s+1);
            st[i] = false;
        }

    }
}

void solve()
{
    cin >> len[0] >> len[1] >> len[2] >> len[3];
    dfs(0);

    if(r == 1){
        cout << "TRIANGLE" << endl;
    }else if(r == 2){
        cout << "SEGMENT" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
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
