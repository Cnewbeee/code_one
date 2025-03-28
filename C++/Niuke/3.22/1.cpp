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
    int n, m;
    cin >> n >> m;
    int a[m+1] = {0};
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a[t]++;
    }
    if(a[1] >= 1 && a[m] >= 1)cout << "No" << endl;
    else cout << "Yes" << endl;
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
