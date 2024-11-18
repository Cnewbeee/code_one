#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, k;
int ans[N], num[N];

void dfs(int s, int sum){
    if(s == n){
        if(sum % k == 0){
            for(int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for(int i = 1; i <= num[s]; i++){
        ans[s] = i;
        dfs(s+1, sum+i);
    }
}

void solve()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    dfs(0, 0);
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
