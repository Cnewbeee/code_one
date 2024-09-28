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
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    if(a > b/2){
        if(n % 2 == 1)ans = a, n--;
        ans += (n/2) * b;
    }else {
        ans = n * a;
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
