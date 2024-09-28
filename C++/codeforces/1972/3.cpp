#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, k;
PII a[N];
void solve()
{
    cin >> n >> k;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second;
        sum += a[i].first;
    }
    sort(a, a+n);
    for()
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
