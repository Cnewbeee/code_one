#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n;
bool st[N];
char ans[N];

void dfs(int s, bool b){
    if(b){
        ans[s-1] = 'Y';
    }else{
        ans[s-1] = 'N';
    }
    if(s == n){
        cout << ans << endl;
        return;
    }

    dfs(s+1, false);
    dfs(s+1, true);
}

void solve()
{
    cin >> n;
    memset(ans, '\0', sizeof ans);
    dfs(1, false);
    dfs(1, true);
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
