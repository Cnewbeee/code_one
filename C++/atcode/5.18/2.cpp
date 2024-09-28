#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

//#define int long long
#define PII pair<int,int>

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    ll sum = 0;
    int t = 0;
    for(string &i : s)cin >> i >> t, sum += t;

    sort(s.begin(), s.end());

    int ans = sum % n;
    cout << s[ans] << endl;
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
