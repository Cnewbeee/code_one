#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
int u = 0, d = 0;
int ans;
PII blocks[5] = {{1, 2}, {2, 1}, {1, 1}, {2, 0}, {0, 2}};
bool chack(int u, int d, int i){
    if(u-d == 2 && (i == 0 || i == 1 || i == 2 || i == 3))return true;
    if(d-u == 2 && (i == 0 || i == 1 || i == 2 || i == 4))return true;
    if(u-d == 1 && (i == 0 || i == 2 || i == 4))return true;
    if(d-u == 1 && (i == 1 || i == 2 || i == 3))return true;
    return false;
}
void dfs(int u, int d){
    if(u == n && d == n){
        ans++;
        if(ans >= 10000)ans %= 10000;
        return ;
    }

    for(int i = 0; i < 5; i++){
        int du = u + blocks[i].first;
        int dd = d + blocks[i].second;
        if(du > n || dd > n || chack(u, d, i))continue;
        //cout << " " << du << " : " << dd;
        dfs(du, dd);
    }
    //cout << endl;
}
void solve()
{
    cin >> n;
    dfs(0, 0);
    cout << ans << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    //cin >> T;

    while(T -- ){
        solve();
    }

	return 0;
}
