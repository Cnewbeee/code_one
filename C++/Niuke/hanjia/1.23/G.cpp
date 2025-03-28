#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(n <= m || m == 1){
        cout << 1 << endl;
        return;
    }
    int t = log(n) / log(m);
    // cout  << t << " ";
    int ans = (abs(pow(m, t)-n) <= abs(pow(m, t+1)-n))? t : t+1;
    cout << ans << endl;
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
