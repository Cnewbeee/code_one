#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int, int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<PII> v(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v[i] = {l, r};
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n-1; i++){
        int l = i, r = n;
        while(l < r){
            int m = (r + l) / 2;
            if(v[m].first <= v[i].second)l = m + 1;
            else r = m;
        }
        ans += l - i - 1;
    }
    
    cout << ans << endl;
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
