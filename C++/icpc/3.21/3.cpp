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
    int ans = k;
    int a[n+1];
    int r = 1;
    memset(a, 2, sizeof a);
    if(k % 2 != 0)ans--, r--;
    int l = -3;
    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        if(l == t-1) ans--;
        else if(l == t - 3) {
            ans++;
            if(r == 0){
                ans--;
                r = 1;
            }
        }
        else l = t;
        //cout << l <<"+++" << t << endl;
    }
    
    cout << ans << endl;
    // 11223345566788  3
    // 1 2 4 7 8
    //12334556678
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
