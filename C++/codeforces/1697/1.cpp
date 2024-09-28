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
    int n , m;
    cin >> n >> m;
    //int a[n+1] = {0}, b[n+1] = {0};
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        sum += t;
    }
     if(sum >= m)cout << sum - m << endl;
     else cout << 0 << endl;
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
