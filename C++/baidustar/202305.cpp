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
    int p, k;
    cin >> p >> k;
    int ans = 0;
    int pp = 0;
    if(p >= k){
        cout << k << endl;
        return ;
    }
    auto check = [&](int x){
        int res = x;
        while(x / p > 0){
            res += x / p;
            x = x - x / p + (x / p) * p;
        }
        return res;
    };

    int l = p, r = k;
    while(l < r){
        int m = (l + r) / 2;
        if(check(m) >= k) r = m;
        else l = m + 1;
    }
    cout << l << endl;
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
