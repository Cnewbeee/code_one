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
    int a[n];
    int mi = 1e9;
    ll sum = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < mi)mi = a[i];
        sum += a[i];
    }
    cout << ceil(double(sum - mi * n) / k) << endl;
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
