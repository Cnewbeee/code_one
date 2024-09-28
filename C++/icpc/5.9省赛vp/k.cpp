#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 3e6 + 10;
int n, m;
void solve()
{
    cin >> n;
    vector<int> a(n), d(n-1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        d[i] = a[i] - a[i+1];
    }
    sort(d.begin(), d.end(), greater<>());
    vector<ll> pre(n);
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + d[i-1];
    }
    ll ans = a.front() - a.back();
    cin >> m;
    while(m--){
        int op;
        cin >> op;
        int x;
        cin >> x;
        if(op){
            cout << ans - pre[x-1] << endl;
        }else{
            //a[x] = a[x-1] + a[x+1] - a[x];
        }
    }
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
