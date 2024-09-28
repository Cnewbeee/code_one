#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int n, m, x = 1e18;

void solve()
{
    cin >> n >> m;
    if(n * n < m && n <= 1e6){
        cout << -1 << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        int t = (m + i - 1) / i;
        if(t <= n){
            x = min(x, i * t);
        }
        if(t <= i)break;
    }
    cout << x << endl;
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
