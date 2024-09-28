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
    int n, m;
    cin >> n >> m;
    if((n - m) % 2 == 0 && n >= m) cout << "Yes" << endl;
    else cout << "No" << endl;  
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
