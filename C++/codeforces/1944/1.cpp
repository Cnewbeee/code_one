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
    int a[n+1];
    int m = n*(n-1)/2;
    if(k > n-1) cout << 1 << endl;
    else cout << n << endl;

}

signed main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1;
    cin >> t;

    while (t--){
        solve();
    }

	return 0;
}
