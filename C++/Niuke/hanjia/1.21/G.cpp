#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    if (sum != ((n + 1) * n / 2)) {
        cout << -1;
        return;
    }
    sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - (i + 1));
    }
    cout << ans / 2;
}

signed main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
