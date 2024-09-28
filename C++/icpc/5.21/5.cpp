#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 5e5 + 10;

void solve()
{
    ll l, n1, n2;
    cin >> l >> n1 >> n2;
    vector<PII> a;
    for(int i = 0; i < n1; i++){
        int m, s;
        cin >> m >> s;
        a.push_back({s, m});
    }
    ll ans = 0;
    int k = 0;
    int ss = 0;
    for(int i = 0; i < n2; i++){
        int m, s;
        cin >> m >> s;
        ss += s;
        while(1){
            if(ss <= a[k].first){
                if(a[k].second == m)ans += ss;
                a[k].first -= ss;
                ss = 0;
                break;
            }else{
                if(a[k].second == m)ans += a[k].first;
                ss -= a[k].first;
                k++;
            }
        }
    }
    cout << ans << endl;
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
