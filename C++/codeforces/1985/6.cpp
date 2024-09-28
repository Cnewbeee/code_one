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
    int n, h;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for(auto &i : a)cin >> i;
    for(auto &i : c)cin >> i;
    for(auto i : a)h -= i;
    if(h <= 0){
        cout << 1 << endl;
        return;
    }
    int r = 5e10, l = 0;
    auto check = [&](int x){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += x / c[i] * a[i];
        }
        return cnt >= h;
    };
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid))r = mid-1;
        else l = mid+1;
    }
    cout << l+1 << endl;
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
