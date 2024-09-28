#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int y[N];
void solve()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(y[t] == 0)n--, y[t]++;
        else n++, y[t]--;
    }
    cout << n << endl;
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
