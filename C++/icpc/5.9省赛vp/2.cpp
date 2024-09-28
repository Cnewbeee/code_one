#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int k, n, m, x;
int a[N];
void solve()
{
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    int b;
    cin >> n >> m >> x;
    int ans = 0;
    x %= m;
    for(int i = 0; i < k; i++)b += a[i] % m;
    b = n/k*b+x;
    for(int i = 0; i < n % k; i++) b += a[i] % m;
    cout << n-b/m << endl;
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
