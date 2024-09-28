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
    int n, k;
    cin >> n >> k;
    vector<int> t(n), l(n), w(n);
    for (int i = 0; i < n; i++){
        cin >> t[i] >> l[i] >> w[i];
    }
    
    auto check = [&](int x){
        int cnt = 0;
        int cn, y;
        for (int i = 0; i < n; i++){
            cn = x / (t[i] * l[i] + w[i]);
            y = x % (t[i] * l[i] + w[i]);
            cnt += cn * l[i];
            //cout << cnt << " " << cn << " " << y << endl;
            if(y < t[i] * l[i])cnt += y / t[i];
            else cnt += l[i];
        }
        
        return cnt >= k;
    };
    int da = 1, hi = 5e10;

    while(da <= hi){
        int mid = (da + hi) / 2;
        if (check(mid)) hi = mid - 1;
        else da = mid + 1;
        //cout << da << " " << hi << endl;
    }
    cout << da << endl;
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
