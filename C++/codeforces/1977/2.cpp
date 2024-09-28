#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++){
        cin >> b[i];
    }
    int t = b[n];
    int ans = 0;
    int r = 0;
    int dm = 1e9;
    for(int i = 0; i < n; i++){
        if(t >= min(a[i], b[i]) && t <= max(a[i], b[i]) && !r)r = 1;
        ans += abs(a[i] - b[i]);
        if(abs(a[i] - t) < dm){
            dm = abs(a[i] - t);
        }
        if(abs(b[i] - t) < dm){
            dm = abs(b[i] - t);
        }
    }
    if(!r){
        ans += dm;
    }ans++;

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
