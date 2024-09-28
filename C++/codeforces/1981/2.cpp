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
    int n, s;
    cin >> n >> s;
    if(s == 0){
        cout << n << endl;
        return ;
    }
    int ans = 0;
    int cnt = 1;
    int l = max(0ll, n-s), r = n+s;
    for(int i = 31; i >= 0; i--){
        if(l >> i == r >> i && cnt){
            int lt = l >> i;
            lt <<= i;
            ans |= lt;
        }else if(cnt){
            cnt = 0;
            ans |= 1 << i;
        }else{
            ans |= 1 << i;
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
