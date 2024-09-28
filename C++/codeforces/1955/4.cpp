#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, m, k;
int a[N], b[N];
void solve()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int ans = 0;
    map<int, int> ma;
    for(int i = 0; i < m; i++){
        ma[b[i]]++;
    }
    int good = 0;
    for(int i = 0; i < m-1; i++){
        good += ma[a[i]]-- > 0;
    }
    for(int i = 0; i <= n-m; i++){
        good += ma[a[i+m-1]]-- > 0;
        ans += (good >= k);
        good -= ++ma[a[i]] > 0;
    }
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
