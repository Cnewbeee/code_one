#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 3e3 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> rows(n);
    for (int i = 0; i < n; ++i) {
        cin >> rows[i];
    }

    unordered_map<string, int> pc;
    int ans = 0;

    for (int j = 0; j < m; ++j) {
        string p;
        for (int i = 0; i < n; ++i) {
            p.push_back(rows[i][j]);
        }
        int cnt = ++pc[p];
        if (cnt > ans) {
            ans = cnt;
        }
    }

    cout << ans << endl;

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
