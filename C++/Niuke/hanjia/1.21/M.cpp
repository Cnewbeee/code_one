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
    int n;
    cin >> n;
    PII a[n];
    int b[n];

    for(int i = 0; i < n; i++){
        cin >> a[i].first, a[i].second = i;
        b[i] = a[i].first;
    }

    sort(a, a + n);

    int l = a[0].second, r = a[0].second;
    int ma = max(a[0].first*2, a[n-1].first);
    int res = ma - min(a[0].first*2, a[1].first);
    for(int i = 1; i < n; i++){
        while(a[i].second < l){
            l--;
            ma = max(ma, b[l]*2);
        }
        while(a[i].second > r){
            r++;
            ma = max(ma, b[r]*2);
        }
        res = min(res, ma - min(a[0].first*2, a[i+1].first));
    }

    cout << res << endl;
}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
    // cin >> T;

    while (T -- ){
        solve();
    }

	return 0;
}
