#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    vector<int> a, b;
    map<int, int> mp;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        mp[x] = y;
        if (y > 0)a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    
    
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
