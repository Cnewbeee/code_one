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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;
    ll s = abs((l - a) % m);
    l += s;
    if(s != 0 && (r - l) <= m){
        cout << 0 << endl;
        return ;
    }
    cout << (r - l) / m + 1 << endl;
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
