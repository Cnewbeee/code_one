#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>


const int mod = 1e9 + 7;
const int N = 2e5 + 10;
ll a[N], s, i, res, n;
signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    cin >> n;
    for(i = 1; i <= n; i++) cin >> a[i];
    
    for(i=1;i<=n;i++){
        res = max(res, a[i] + (a[i-1]+1) / 2 + 1 - s);
        s += a[i] / 2;
    }
    cout << res;
	return 0;
}
