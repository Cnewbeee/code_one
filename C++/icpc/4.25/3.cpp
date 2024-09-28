#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e18 + 10;
vector<int> v(100);
void solve()
{
    ll l, r;
    cin >> l >> r;
    r;
    ll ans = 0;
    for(int i = l; i <= r; i++){
        int num = i;
        int k = 0;
        while(num > 0){
            int y = num % 10;
            if(y)k++;
            num /= 10;
        }
        if(k <= 3){
            ans++;
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
