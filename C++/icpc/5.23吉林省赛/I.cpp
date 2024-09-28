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
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    if(n % 2 == 0){
        ans += (y*2+x) / n;
    }else{
        if(n == 1){
            ans = x + y;
        }else{
            int cnt = n / 2;
            int bi = y / cnt;
            ans += min(x, bi);
            bi = min(x, bi);
            y -= bi * cnt;
            x -= bi;
            if(x && y * 2 + x >= n)ans ++, x -= n - y*2, y = 0;
            ans += x / n;
            ans += y * 2 / (n+1);
        }
    }
    cout << ans << endl;
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
